#include <unicore.h>
//#include "ReaderSTEP.h"


UniCore::UniCore(HFS* _hfs, QObject* parent) : QThread(parent), hfs(_hfs)
{
    unicore_mutex = new QMutex();
    waitcondition = new QWaitCondition();

    setupFlowerBase();
    reloadFlower();

    hfs->subscribe(this, Bootup_NodeRole, "unicore.nodeRoleChanged");
    hfs->provides(this, "unicore.nodeRoleChanged()");
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

QVariant UniCore::nodeRoleChanged(Job *job)
{
    qDebug() << "UniCore::nodeRoleChanged var:";
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
            pp += processDataFromCoreServer();
        }
        unicore_mutex->unlock();
    }
}

int UniCore::processDataFromCoreServer()
{
    DataPack* pack = nullptr;
    pack = databuffer->takeFirst();
    if (!pack) return 0;

    //This is the first point outside data packet is being processed
    // WE DO NOT TRUST ANYTHING AT THIS POINT!!!
    // Before we let any packages into the main processing parts, we need to
    // check each of them for diffent attributes. If any of the next functions return false
    // we silently discard the package (with a minimal log)
    // Any malformed block should not leave this function
    // We also need to implement an input pool for the thread execution

    int errcnt = 0;
    if      (!checkIntegrity(pack))                     errcnt += 1;
    else if (!checkACL(pack))                           errcnt += 2;
    else if (!checkWhatever(pack))                      errcnt += 4;
//    else if (!DataPack::deserialize(pack))                 errcnt += 8;
    else if (!processDataPack(pack, false))             errcnt += 16;
    if (errcnt)
    {
        log(1, QString("malformed incoming DataPack from %1 having issue: %2").arg(pack->sourceDevice()).arg(errcnt));
        delete(pack);
        return 1; // we processed DataPack. returning 0 here might stall processing for inbound
    }
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

void UniCore::HFS_inBound(DataPack* pack)                   // sync and datachangeRequest from HFS
{
    processDataPack(pack, 1);
}

bool UniCore::processDataPack(DataPack* pack, int local_source)
{
    if (!pack) return false;
    QString topic = pack->getStringAttribute("path");
    QString value = pack->getStringAttribute("value");
    int cmd = pack->command();
    int flags = hfs->getFlagsFromItem(hfs->_hasPath(topic));
    int flag_glob = (flags & HFS_GlobalUsage);
    bool broadcast = false;
     
    switch (cmd)
    {
        case HFSDataChangeRequest:
            {
                if (hfs->nodeRole() == NR_SLAVE)
                {
                    if (local_source)
                    {
                        if (flag_glob)
                        {
                            emit newPackReadyForCS(pack);               // local slave sends global dataChange to master
                        }
                        else
                        {
                            hfs->setData(topic, value, false);          // local slave updates local variable without dispatcing
                        }
                    }
                    else
                    {
                        // NOP                                           // should be discarded: slave cannot have dataChangeRequest from server
                    }
                }
                else if (hfs->nodeRole() == NR_MASTER)
                {
                    if (local_source)
                    {
                        if (flag_glob)
                        {
                            hfs->setData(topic, value, true);           // local master updates and dispatches global variable
                        }
                        else
                        {
                            hfs->setData(topic, value, false);          // local master updates local variable without dispatch
                        }
                    }
                    else
                    {
                        if (flag_glob)
                        {
                            hfs->setData(topic, value, true);           // local master updates and dispatches global variable due to request from remote slave
                        }
                        else
                        {
                            //NOP                                       // should be discarded: remote slave wants to update local variable
                        }
                    }
                }
            }
            break;
        case HFSSetData:                                        
            {
                if (hfs->nodeRole() == NR_MASTER)          // should arrive only from remote master only
                {           
                    if (flag_glob)                         // we broadcast dispatch only global variable was modified
                    {
                        broadcast = true;
                    }
                }
            }
            break;

        case Ping:
            {
                qDebug() << "=========== PING ================================";
                qDebug() << "  NODE ID : " << pack->sourceDevice();
                qDebug() << "  SOCK ID : " << pack->socketId();
                qDebug() << "=================================================";
            }
            break;
        case JobTransfer:
            {
                qDebug() << "=========== JOB TRANSFER ========================";
                qDebug() << "  NODE ID : " << pack->sourceDevice();
                qDebug() << "  SOCK ID : " << pack->socketId();
                qDebug() << "=================================================";

                if (Job* job = new Job())
                {
                    job->load(pack->textPayload());
                    flower->jobTransferred(job);
                }
            }
            break;
        case SetSocketId:
            {
                qDebug() << "=========== SET SOCKET ID ======================";
                qDebug() << "  NODE ID : " << pack->sourceDevice();
                qDebug() << "  SOCK ID : " << pack->socketId();

#if PF_WASM
                if (pack->attributes.contains("socket_id"))
                {
                    hfs->setDevId(pack->attributes["socket_id"].toInt());
                }
                qDebug() << "  DEVID SET: " << hfs->devId();
#endif
                qDebug() << "=================================================";
            }
            break;
        case SetDevId:
            break;
        case HFSCreatePath:
            break;
        case HFSLog:
            break;
        case HFSSubscribe:
            break;
        case HFSUnsubscribe:
            break;
        case HFSSetAttribute:
            break;
        case HFSRemoveAttribute:
            break;
        case HFSSetMethod:
            break;
        case HFSRemoveMethod:
            break;
        default:
            break;
        }

    if (broadcast)
    {
        pack->setDestination(-1);                // broadcast for all nodes
        emit newPackReadyForCS(pack);
        return true;
    }

    delete(pack);
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

    fg_executor = new Executor(hfs, this);
    flower->addExecutor("gui", fg_executor);
    fg_executor->moveToThread(qApp->thread());

    QObject::connect(flower, SIGNAL(outBoundJob(Job*, int)), this, SLOT(outBoundJob(Job*, int)));
}

void UniCore::outBoundJob(Job* job, int task_devid)
{
    if (!job) return;
    int orig_src = job->sourceDevice();
    job->setSourceDevice(hfs->devId());
    job->setDestinationDevice(task_devid);
    if (DataPack *pack = new DataPack(job->save()))
    {
        pack->setCommand(JobTransfer);
        if (task_devid==-1)
        {
            pack->setDestination(orig_src);      // When non-defined execution is defined, we should send back to the original caller
        }
        pack->setDestination(task_devid);
        emit newPackReadyForCS(pack);
    }
}

void UniCore::reloadFlower()
{
    // Stop & clear Flower subsystem

    // General helper pointers
    Flow* flow = nullptr;
    Task* task = nullptr;

    // Load basic default flows
        // 0. Create test flow

    flow = flower->createFlow("cs_noderole"); //!
    for (int i = 0; i < 1;i++)
    {
        flow->createTask("coreserver_set_noderole", "cs.nodeRoleChanged()");
        flow->createTask("unicore_set_noderole", "unicore.nodeRoleChanged()");
    }

    // 1. Coreserver should be notified when Bootup_NodeRole is changed (->topicChanged, with NODEROLE idx)
    //    flow = flower->createFlow("cs_noderole2", Bootup_NodeRole);
    //    flow->createTask("cs_noderole2", "cs", "nodeRoleChanged");
    // 2. Unicore should be notified when Bootup_NodeRole is changed  (->topicChanged, with NODEROLE idx)
    // 3. Unicore should be notified when System_Time_DayEpoch is changed ( ->dayEpochChanged, w/o idx);
    // 4. Coreserver should have been set up with proper NodeRole

    hfs->setData("test.test", NR_MASTER);

    // Load basic POC flows

    // - create basic buttons for POC relay 1
#if 0
    flow = flower->createFlow("sw_1_1", "button.1_1");
    flow->createTask("sw_1_1_toggle", "relay.1_1.toggle()");

    flow = flower->createFlow("sw_1_2", "button.1_2");
    flow->createTask("sw_1_2_toggle", "relay.1_2.toggle()");

    flow = flower->createFlow("sw_1_3", "button.1_3");
    flow->createTask("sw_1_3_toggle", "relay.1_3.toggle()");

    flow = flower->createFlow("sw_1_4", "button.1_4");
    flow->createTask("sw_1_4_toggle", "relay.1_4.toggle()");

    flow = flower->createFlow("sw_1_5", "button.1_5");
    flow->createTask("sw_1_5_toggle", "relay.1_5.toggle()");

    flow = flower->createFlow("sw_1_6", "button.1_6");
    flow->createTask("sw_1_6_toggle", "relay.1_6.toggle()");

    flow = flower->createFlow("sw_1_7", "button.1_7");
    flow->createTask("sw_1_7_toggle", "relay.1_7.toggle()");

    flow = flower->createFlow("sw_1_8", "button.1_8");
    flow->createTask("sw_1_8_toggle", "relay.1_8.toggle()");
#else

    flow = flower->createFlow("login_flow");
    flow->createTask("gather_credentials", "system.gatherCredentials()");
    flow->createTask("login", "system.login()");
    flow->createTask("dumpHFS", "hfs.dumpState()");
    flow->createTask("restoreHFS", "hfs.restoreState()");
   
    flow = flower->createFlow("test_flow");
//    flow->createTask("test_step_1", "system.1.function1()");
//    flow->createTask("test_step_2", "system.2.function2()");
    flow->createTask("test_step_2", "jmeter.2.getCountOfAllRecords()");
    flow->createTask("test_step_3", "system.3.updateAllCountInfo()");

    flow = flower->createFlow("button1");
    flow->createTask("button1_step1", "relay.1_1.toggle()");


#endif
}
