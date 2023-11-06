#include <unicore.h>

UniCore::UniCore(HFS* _hfs, HSM* _hsm, QObject* parent) : QThread(parent), bypass(true), hfs(_hfs), hsm(_hsm)
{
    unicore_mutex = new QMutex();
    waitcondition = new QWaitCondition();
    hfs->subscribe(this, Bootup_NodeRole, "topicChanged", "NODEROLE");
    hfs->subscribe(this, System_Time_DayEpoch, "dayEpochChanged");

    if (hfs->data(Bootup_NodeRole).toString().toLower() == NR_MASTER)
    {
        bypass = false;
    }

    setupFlowerBase();
    reloadFlower();
}

UniCore::~UniCore()
{
    delete(unicore_mutex);
    delete(waitcondition);
}

void UniCore::init()
{
}

void UniCore::addExecutor(QString prefix, Executor* executor)
{
    if (!flower)
        setupFlowerBase();
    flower->addExecutor(prefix, executor);
}

QWaitCondition* UniCore::getWaitCondition()
{
    return waitcondition;
}

void UniCore::log(int severity, QString line)
{
    hfs->log(severity, line, "UNICORE");
}

QVariant UniCore::nodeRoleChanged(QVariant var)
{
    qDebug() << "UniCore::nodeRoleChanged var:" << var;
    return QVariant();
}

void UniCore::run()
{
    forever
    {
        unicore_mutex->lock();
        waitcondition->wait(unicore_mutex, 2000);
        int pp = 1;
        while (pp)
        {
            pp = 0;
            pp += processPackFromSlotter();
            pp += processDataFromCoreServer();
        }
        unicore_mutex->unlock();
    }
}

int UniCore::processDataFromCoreServer()
{
    DataPack* DataPack = NULL;
    DataPack = databuffer->takeFirst();
    if (!DataPack) return 0;
    //  log(Info, "UC: processDataFromCoreServer");
        //This is the first point outside data packet is being processed
        // WE DO NOT TRUST ANYTHING AT THIS POINT!!!
        // Before we let any packages into the main processing parts, we need to
        // check each of them for diffent attributes. If any of the next functions return false
        // we silently discard the package (with a minimal log)
        // Any malformed block should not leave this function
        // We also need to implement an input pool for the thread execution

    int errcnt = 0;
    if (!checkIntegrity(DataPack))              errcnt += 1;
    else if (!checkACL(DataPack))               errcnt += 2;
    else if (!checkWhatever(DataPack))          errcnt += 4;
    else if (!DataPack::deserialize(DataPack))  errcnt += 8;
    else if (!processDataPack(DataPack, false)) errcnt += 16;
    if (errcnt)
    {
        log(1, QString("malformed incoming DataPack from %1 having issue: %2").arg(DataPack->socketId()).arg(errcnt));
        delete(DataPack);
        return 1; // we processed DataPack. returning 0 here might stall processing for inbound
    }

    // TESTING -- simply drop DataPack and pass a new datapacked to upper layer
    return 1;
}

bool UniCore::checkIntegrity(DataPack* db)
{
    return true;
}

bool UniCore::checkACL(DataPack* db)
{
    return true;
}

bool UniCore::checkWhatever(DataPack* db)
{
    return true;
}

bool UniCore::parseDataPack(DataPack* db)
{
    return true;
}

bool UniCore::constructDataPack(DataPack* db)
{
    return true;
}

/*
    Serializatin is where we flatten all known information into a binary or textual representation
    so it could be easily sent over the socket. No other part knows about the serialization, so it
    could define the protocol on its own. Of course serialize() and deserialize() should use the same
    protocol. Here it is possible to introduce versions, compressions or anything, this part is hidden from
    any other part of the node.

    NOTE: For now we just create a simple name=value list delimited by \n. It is sufficient for the POC.
    If tree-line data structures are required, this should be updated as well as DataPack structures.
    Wish we are there ... :)
*/

/* ===================================================================================
                    EXECUTE DATAPACK BLOCK
======================================================================================*/

int UniCore::processPackFromSlotter()
{
    DataPack* pack = NULL;
    pack = packbuffer->takeFirst();
    if (!pack) return 0;
    processDataPack(pack, true);
    return 1;
}

bool UniCore::processDataPack(DataPack* pack, bool down)
{
    if (!pack) return false;
    QString _source = pack->source();
    QString _device = pack->sourceDevice();
    if (_source == "HFS")
    {
        if (_device == hfs->devId())                          //packet originated from here, we send down to the
        {                                                   // transportation layer.
            emit newPackReadyForCS(pack);
            return true;
        }
    }

    if (bypass)                         // We are SLAVE. Simply passing packet to the next layer.
    {                                   // When decentralised execution is implemented, this is where
                                        // we should decide wherher incoming package processed locally or not.
        if (down)
        {
            emit newPackReadyForCS(pack);   // sending to CoreServer for dispatch
        }
        else
        {
            emit newPackReadyForSL(pack);       // sending to Slotter
        }
    }
    else                // We are MASTER, so we need to inspect/update the package here
    {
        switch (pack->command())
        {
        case CommandNotDefined:
            break;
        case NOP:
            break;
        case Ping:
            break;
        case RegisterEntity:            // OBSOLETE
            break;
        case UnregisterEntity:          // OBSOLETE
            break;
        case SystemEvent:
            break;
        case HFSDataChangeRequest:
        {
            emit newPackReadyForCS(pack);
        }
        break;
        case HFSLog:
            break;
        }
    }
    return true;
}

void UniCore::HFS_inBound(DataPack* pack)
{
    //    processDataPack(pack, true);
    executeDataPack(pack, true);
}

bool UniCore::executeDataPack(DataPack* pack, bool down)
{
    //! DataPack should contain the platform in this case (datachangerequest)

    QString topic = pack->attributes["path"].toString();
    QString value = pack->attributes["value"].toString();

    qDebug() << "TOPIC: " << topic << " VALUE: " << value;

    if (topic == System_LogLine)
    {
        if (pack->command() == PackCommands::HFSLog)                        // Only local packages have HFSLog flags set
        {                                                                   // serialization skip coping with this flag
        }
        else
        {
            DataPack::deserialize(pack);
            value = pack->attributes["value"].toString();
        }
        hfs->directLog(value);
    }
    else
    {
        hfs->setData(topic, value);
    }
    return true;
}

void UniCore::dayEpochChanged(QVariant epoch_var)
{
    QString epoch = epoch_var.toString();
}

QString UniCore::toEpoch(int hour, int min, int sec)
{
    int rint = hour * 60 * 60 + min * 60 + sec;
    QString retstr = QString::number(rint);
    return retstr;
}

void UniCore::setupFlowerBase()
{
    flower = new Flower(hfs, this);
    fg_executor = new Executor(this, this);
    flower->addExecutor("gui", fg_executor);
    fg_executor->moveToThread(qApp->thread());
    bg_executor = new Executor(this, nullptr);
    bg_thread = new QThread(this);
    bg_executor->moveToThread(bg_thread);
    flower->addExecutor("bg", bg_executor);
}

void UniCore::reloadFlower()
{
    // Stop & clear Flower subsystem

    // General helper pointers
    Flow* flow = NULL;
    Task* task = NULL;

    // Load basic default flows
        // 0. Create test flow

    flow = flower->createFlow("cs_noderole", "test.test");
    flow->createTask("coreserver_set_noderole", "cs", "nodeRoleChanged");
    flow->createTask("slotter_set_noderole", "slotter", "nodeRoleChanged");
    flow->createTask("unicore_set_noderole", "gui", "nodeRoleChanged");

    // 1. Coreserver should be notified when Bootup_NodeRole is changed (->topicChanged, with NODEROLE idx)
    //    flow = flower->createFlow("cs_noderole2", Bootup_NodeRole);
    //    flow->createTask("cs_noderole2", "cs", "nodeRoleChanged");

        // 2. Slooter should be notified when Bootup_NodeRole is changed  (->topicChanged, with NODEROLE idx)
        // 3. Slotter should be notified when HFS_State is changed (->topicChanged, with HFSSTATE idx)
        // 4. Unicore should be notified when Bootup_NodeRole is changed  (->topicChanged, with NODEROLE idx)
        // 5. Unicore should be notified when System_Time_DayEpoch is changed ( ->dayEpochChanged, w/o idx);

        // 6. Coreserver should have been set up with proper NodeRole

    hfs->setData("test.test", NR_MASTER);

    // Load basic POC flows

    // - create basic buttons for POC relay 1
#if 0
    flow = flower->createFlow("sw_1_1", "button.1_1");
    flow->createTask("sw_1_1_toggle", "hfs", "callMethod", "relay.1_1", "toggle");
#else
    for (int i = 1; i < 9; i++)
    {
        QString numstr = QString::number(i);
        flow = flower->createFlow("sw_1_" + numstr, "button.1_" + numstr);
        flow->createTask("sw_1_" + numstr + "_toggle", "hfs", "callMethod", "relay.1_" + numstr, "toggle");
    }
#endif
}