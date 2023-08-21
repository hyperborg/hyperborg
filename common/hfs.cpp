#include "hfs.h"

// ============================ HFS implementation ====================================
HFS::HFS( QObject* parent)
    : QAbstractItemModel(parent), propmap(NULL), rootItem(NULL), watcher(NULL),query1(NULL), query_log(NULL), db_online(false)
{
    rootItem = new HFSItem("root");
    watcher = new QFileSystemWatcher(this);
    propmap = new QQmlPropertyMap(this);

    // setting up Flower system
    flower = new Flower(this, this);
    fg_executor = new Executor(this, this);
    flower->addExecutor("gui", fg_executor);
    bg_executor = new Executor(this, nullptr);
    bg_thread = new QThread(this);
    bg_executor->moveToThread(bg_thread);
    flower->addExecutor("bg", bg_executor);

    setDefaultValues();
    setupTestFlows();

    // Setting up ticktock service
    ticktock_timer = new QTimer(this);
    bool f = QObject::connect(ticktock_timer, SIGNAL(timeout()), this, SLOT(ticktock_timeout()));
    ticktock_timer->setSingleShot(true);

    provides(this, System_Date_Year, SENSOR);
    provides(this, System_Date_Month, SENSOR);
    provides(this, System_Date_Day, SENSOR);

    provides(this, System_Time_Hour, SENSOR);
    provides(this, System_Time_Minute, SENSOR);
    provides(this, System_Time_Second, SENSOR);

    provides(this, System_Time_DayEpoch, SENSOR);
    provides(this, System_Time_Epoch, SENSOR);

    subscribe(this, System_Time_Epoch, "epochChanged");
}

HFS::~HFS()
{
    delete rootItem;
}

void HFS::startServices()
{
//    if (data(Bootup_NodeRole) == NR_MASTER)             // Only master should provide ticks for now
    {                                                        // Later all nodes should have synced and fall back timing sources   
//        ticktock_timer->start(1000);
    }
    QObject::connect(propmap, SIGNAL(valueChanged(const QString&, const QVariant&)), this, SLOT(qmlValueChanged(const QString&, const QVariant&)));
}

void HFS::setDefaultValues()
{
    setData(Bootup_Name, "Unknown device");
    setData(Bootup_NodeRole, NR_UNDECIDED);
    setData(Bootup_MatixId,  "1");
    setData(Bootup_Port,     "33333");
    setData(Bootup_IP,        "127.0.0.1");

    setData(Config_DB_Host,   "127.0.0.1");
    setData(Config_DB_Type,   "");
    setData(Config_DB_Name,   "");
    setData(Config_DB_User,   "");
    setData(Config_DB_Pass,   "");
    setData(Config_DB_Port,   "");

#if defined(WIN32)
    setData(Bootup_GUI,       1);
#elif defined(WASM)
    setData(Bootup_GUI,       1);
#elif defined(LINUX)
    setData(Bootup_GUI, 0);
#endif
    setData(HFS_State, HFSCreated);

    setData(System_Log, "");
    setData(System_LogLine, "");
    setData(System_BuildDate, HYPERBORG_BUILD_TIMESTAMP);
}

void HFS::setupTestFlows()
{
    if (!flower) return;
    Flow* button12flow = flower->createFlow("button.1_2");
    subscribe(flower, "button.1_2", "startJob");
    button12flow->createTask("BUTTON_1_2_TOGGLE", "hfs.callMethod", "switch.1_2.toggle");

    /*
    // Slider and other zoom GUI element change handling
    iTask* task = new iTask("SLIDERCHANGED", "gui.SliderChanged");
    zoomflow->addTask(task);
    GETBROKER->subscribe(flower, DOCUMENT_ZOOMCOMBO, "startJob");
    GETBROKER->subscribe(flower, DOCUMENT_ZOOMSLIDER, "startJob");
    GETBROKER->subscribe(flower, DOCUMENT_FITHOR, "startJob");
    GETBROKER->subscribe(flower, DOCUMENT_FITBOTH, "startJob");

    // Document effectivepercent changed
    iFlow* effPercentFlow = new iFlow(DOCUMENT_EFFPERCENT);
    flower->addFlow(effPercentFlow, DOCUMENT_EFFPERCENT);
    iTask* eptask = new iTask("EFFPERCENT_CHANGED", "gui.EffpercentChanged");
    effPercentFlow->addTask(eptask);
    GETBROKER->subscribe(flower, DOCUMENT_EFFPERCENT, "startJob");

    // Zoom dotmode is changed
    iFlow* dotFlow = new iFlow(DOCUMENT_DOTMODE);
    flower->addFlow(dotFlow, DOCUMENT_DOTMODE);
    iTask* dottask = new iTask("DOTMODE CHANGED", "gui.dotModeChanged");
    dotFlow->addTask(dottask);
    GETBROKER->subscribe(flower, DOCUMENT_DOTMODE, "startJob");
    */

}

// Try to load init parametrics from the files listed here
// There is only one "trick" here. The value for Bootup_NodeRole should not be processed right away,
// since that triggers all subsystems dependent of its value and they should not run before
// with semi-setup HFS database.

void HFS::useConfig(QString configfile)
{
    _configfile = configfile;
}

bool HFS::loadBootupIni()
{
    log(Info, tr("Section BOOTUP"));
    bool retbool = false;
    watcher->removePath(data(Bootup_ConfigFile).toString());

#if defined(WASM)                                 // WebAssembly based clinet is always slave and use its origin
    retbool = true;

    QString source_href = emscripten_run_script_string("window.location.href");
    QUrl url(source_href);
    QString host = url.host();

    setData(Bootup_IP, host);
    setData(Bootup_Port, 33333);
    setData(Bootup_NodeRole, NR_SLAVE);

#else
    // Loading and handling BOOTUP FILE
    pinis.clear();
    if (!_configfile.isEmpty()) pinis << _configfile;
    pinis << "/etc/hyperborg/bootup.ini";         // Linux: use config from /etc
    pinis << "c:\\hyperborg\\bootup.ini";
    pinis << "bootup.imi";                        // Use file next to hynode
    pinis << "/home/web_user/bootup.ini";         // WASM: use file from persistant cache (IDBFS)

    QString Bootup_NodeRoleCache;
    bool ok = false;
    for (int i = 0; i < pinis.count() && !ok; i++)
    {
        QString filename = pinis.at(i);
        QFile f(filename);
        if (f.open(QIODevice::ReadOnly))
        {
            log(Info, QString(tr("USING CONFIGURATION (BOOTUP) FILE: %1")).arg(filename));
            ok = true;
            setData("config.used_file", filename);
            while (!f.atEnd())
            {
                QString str = f.readLine();
                int idx = str.indexOf("#");
                if (idx > -1) str = str.mid(0, idx);
                if (str.length())
                {
                    idx = str.indexOf("=");
                    if (idx != -1)
                    {
                        QString key = str.mid(0, idx);
                        QString val = str.mid(idx + 1);

                        key = key.trimmed();
                        val = val.trimmed();

                        if (key != Bootup_NodeRole)
                        {
                            setData(key, val);
                        }
                        else
                        {
                            Bootup_NodeRoleCache = val;
                        }
                    }
                }
            }
            f.close();
            if (!Bootup_NodeRoleCache.isEmpty())
            {
                retbool = true;
                setData(Bootup_NodeRole, Bootup_NodeRoleCache);
            }
        }
    }

    // LOADING AND HANDLING THE MAIN CONFIGURATION FILE
//    if (hfs->value("config.role").toUpper()=="MASTER")
    if (1)  // Enable local config loading for slave nodes
    {
        QString cfile = data(Bootup_ConfigFile).toString();
        if (!cfile.isEmpty())
        {
            if (!loadConfigIni(cfile))
            {
                log(Info, QString(tr("Configuration file <%1> cannot be opened!")).arg(cfile));
            }
        }
        else
        {
            log(Info, QString(tr("Config file is not defined in the bootup.ini file")));
        }
    }

    QString str = data(Bootup_ConfigFile).toString();
    watcher->addPath(data(Bootup_ConfigFile).toString());
    QObject::connect(watcher, SIGNAL(fileChanged(const QString&)), this, SLOT(fileChanged(const QString&)));
#endif
    setData(HFS_State, HFSBootInfoLoaded);
    return retbool;
}

bool HFS::loadConfigIni(QString jsonfile, bool _clear)
{
    setData(HFS_State, HFSBootInfoLoaded); // Step back to previous stage, triggering clearing operations, like unload QML in Slotter

    log(Info, QString(tr("OPENING CONFIGURATION FILE <%1> with clear flag: %2")).arg(jsonfile).arg(_clear));
    // Let's make sure we can read the json into the memory before we start to update this node
    if (jsonfile.isEmpty())
    {
        log(Info, "Cannot open config file without a name!");
        return false;
    }
    QFile f(jsonfile);
    if (!f.open(QIODevice::ReadOnly))
    {
        log(Info, QString("cannot open config file with name: <%1>").arg(jsonfile));
        return false;
    }
    QByteArray rall;
    rall = f.readAll();
    f.close();

    QJsonParseError parseError;
    QJsonDocument doc;
    doc = QJsonDocument::fromJson(rall, &parseError);
    if(parseError.error != QJsonParseError::NoError)
    {
        log(Info, QString("Config file load failed due to error at %1 : %2").arg(parseError.offset).arg(parseError.errorString()));
        return false;
    }

    // So far, so good. We could load json into memory and it could be parsed correctly
    // So now we drop out the complete HFS, except the entries under the bootup. path
    QString str = data(Bootup_ConfigFile).toString();
    watcher->addPath(data(Bootup_ConfigFile).toString());
    log(Info, "Clearing HFS ...");
    if (_clear) clear();

    QJsonObject jsonObj;
    jsonObj = doc.object();
    QStack<QJsonObject> jstack;
    jstack.push(jsonObj);
    QStack<HFSItem *> hstack;
    hstack.push(rootItem);
//    log(Info, "ROOTITEM: " + rootItem->fullPath());
    int runblock = 0;
    while(!jstack.isEmpty() && runblock<15)
    {
        runblock++;
        QJsonObject cjo = jstack.pop();
        HFSItem *item =hstack.pop();
        QStringList keys = cjo.keys();

        for (int i=0;i<keys.count();++i)
        {
            QString ckey = keys.at(i);
            QString fp = item->fullPath();
            if (!fp.isEmpty()) fp+=".";
            QString npath = fp+ckey;
            HFSItem *nitem = _hasPath(npath, true);
            QJsonValue jchild = cjo.value(ckey);

            if (jchild.isNull())
            {
    //      log(Info, QString(tr("JCHILD %1 is NULL")).arg(ckey));
            }
            else if (jchild.isUndefined())
            {
    //      log(Info, QString(tr("JCHILD %1 is UNDEFINED")).arg(ckey));
            }
            else if (jchild.isArray())
            {
    //      log(Info, QString(tr("JCHILD %1 is ARRAY")).arg(ckey));
            }
            else if (jchild.isBool())
            {
    //      log(Info, QString(tr("JCHILD %1 is BOOL")).arg(ckey));
                nitem->setData(jchild.toBool());
            }
            else if (jchild.isDouble())
            {
    //      log(Info, QString(tr("JCHILD %1 is DOUBLE")).arg(ckey));
                nitem->setData(jchild.toDouble());
                }
                else if (jchild.isString())
                {
    //          log(Info, QString(tr("JCHILD %1 is STRING  - set to %3")).arg(npath).arg(jchild.toString()));
                nitem->setData(jchild.toString());
                }
                else if (jchild.isObject())
            {
    //          log(Info, QString(tr("JCHILD %1 is OBJECT")).arg(ckey));
                hstack.push(nitem);
                jstack.push(jchild.toObject());
            }
        }
    }

    // Main SQL related initialization
    db_online = false;
    if (db.open())
    {
        db.close();
    }

    if (query1)
    {
        delete query1;
    }

    if (query_log)
    {
        delete query_log;
    }

    db = QSqlDatabase::addDatabase(data(Config_DB_Type).toString());
    if (db.isValid())
    {
        db.setHostName(data(Config_DB_Host).toString());
        db.setPort(data(Config_DB_Port).toInt());
        db.setUserName(data(Config_DB_User).toString());
        db.setPassword(data(Config_DB_Pass).toString());
        db.setDatabaseName(data(Config_DB_Name).toString());

        if (db.open())
        {
            log(Info, "Database opened");
            db_online = true;

            query1 = new QSqlQuery(db);
            query1->exec("SET CLIENT_ENCODING TO 'UTF8'");
            query_log = new QSqlQuery(db);
            query_log->exec("SET CLIENT_ENCODING TO 'UTF8'");

            checkDataBase();

            for (int i = 0; i < log_cache.length(); ++i)
            {
                directLog(log_cache.at(i));
            }
            log_cache.clear();
        }
        else
        {
            log(Critical, "Database could not be opened");
        }
    }

    setData(HFS_State, HFSConfigLoaded);
    return true;    
}

void HFS::directLog(QString logline)
{
#if HDEBUG
    qDebug() << logline;
#endif
    if (logline.isEmpty()) return;
    if (!db_online)
    {
        log_cache.append(logline);
        if (log_cache.length() > 5000)
        {
            log_cache.takeFirst();
        }
    }

    if (!db_online || !query_log) return;

#if 0       // Qt's bindValue is broken atm, it would be investivated later
    if (query_log->prepare("INSERT INTO log (severity, logline, source) VALUES (:severity,:logline, :source)"))
    {
        query_log->bindValue(":severity", "0");
        query_log->bindValue(":source", "SRC");
        query_log->bindValue(":logline", logline);

        if (!query_log->exec())
        {
            qDebug() << "Cannot insert logline into SQL database";
            qDebug() << query_log->lastError().text();
        }
    }
    else
    {
        qDebug() << "Cannot prepare SQL statement";
        qDebug() << query_log->lastError().text();
    }
#else
    QString cmd = "INSERT INTO log (severity, logline, source) VALUES ('0','"+logline+"', 'SRC')";
    if (!query_log->exec(cmd))
    {
        qDebug() << "Cannot insert logline into SQL database";
        qDebug() << query_log->lastError().text();
    }
#endif
}

bool HFS::clear()       // clear() drops all HFSItem EXCEPT nodes in "bootup." path
{
    QMutexLocker locker(&mutex);
    if (!rootItem) return false;
    beginResetModel();
    QList<HFSItem *> children;
    for (int i=0;i<rootItem->childCount();++i)      // should be cached out or indexing goes wrong
    {
        if (HFSItem *citem=rootItem->child(i))
        {
            if (citem->id().toUpper()!="BOOTUP")
                children.append(citem);
        }
    }

    for (int i=0;i<children.count();++i)
    {
        delete(children.at(i));
    }

    endResetModel();
    return true;
}


// Make sure we are not removing user added comments!
bool HFS::saveConfigIni()
{
    log(Info, "HFS::saveInitFiles() is not yet implemented");
    return false;

/*
    QString filename = data("config.user_file").toString();
    QStringList fl = pinis;
    if (filename.isEmpty())                 // Put the loaded file at the beginning of the list
    {                                       // If it is possible to save there, let's try that first
        fl.prepend(filename);
    }

    bool ok = false;
    for (int i = 0; i < fl.count() && !ok; ++i)
    {
        QFile f(fl.at(i));
        if (f.open(QIODevice::WriteOnly))
        {
        }
    }
*/
}

QModelIndex HFS::index(int row, int column, const QModelIndex& parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    HFSItem* parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<HFSItem*>(parent.internalPointer());

    HFSItem* childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}

QModelIndex HFS::parent(const QModelIndex& index) const
{
    if (!index.isValid())
        return QModelIndex();

    HFSItem* childItem = static_cast<HFSItem*>(index.internalPointer());
    HFSItem* parentItem = childItem->parentItem();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int HFS::rowCount(const QModelIndex& parent) const
{
    HFSItem* parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<HFSItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int HFS::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return static_cast<HFSItem*>(parent.internalPointer())->columnCount();
    return rootItem->columnCount();
}

QVariant HFS::data(const QModelIndex& index, int role) const
{
    //QMutexLocker locker(&mutex);
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    if (HFSItem* item = static_cast<HFSItem*>(index.internalPointer()))
    {
        switch (index.column())
        {
        case 0:
            return item->fullPath();
            break;
        case 1:
            return item->data();
            break;
        default:
            break;
        };
    }
    return QVariant();
}

QVariant HFS::data(QString path)
{
    //QMutexLocker locker(&mutex);
    QVariant retvar;
    if (HFSItem* hitem = _hasPath(path, false))
    {
        return hitem->data();
    }
    return retvar;
}

QVariant HFS::childKeys(QString path)
{
    QStringList retlst;
    if (HFSItem* hitem = _hasPath(path, false))
    {
        int cc = hitem->childCount();
        for (int i = 0; i < cc; ++i)
        {
            retlst.append(hitem->child(i)->id());
        }
    }
    return QVariant(retlst);
}

int HFS::dataChangeRequest(QObject* requester,      // The object that is requesting the datachange, this object would be notified if
    QString sessionid,                              // The device_sessionid.user_sessionid combo for ACL checking
    QString topic,                                  // The topic of which value change was requested
    QVariant val)                                   // The new requested value 
{
    //QMutexLocker locker(&mutex);
    if (DataPack* pack = new DataPack())
    {
        pack->setSource("HFS");
        pack->setCommand(PackCommands::HFSDataChangeRequest);
        pack->attributes.insert("path", topic);
        pack->attributes.insert("value", val);
        pack->attributes.insert("acl_sid", sessionid);
        emit outPack(pack);
    }
    return 0;
}

Qt::ItemFlags HFS::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
}

QVariant HFS::headerData(int section, Qt::Orientation orientation,
    int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data();

    return QVariant();
}

void HFS::subscribe(QObject* obj,                   // The object that request notification when the topic is changed 
                    QString topic,                  // The topic the object is attached (subscirbed) to  
                    QString funcname ,              // The obj's method name (slot) that would be called when topic is changed
                    QString keyidx ,                // If the function is a handles multiple topic, this key is added to the call for sorting out reason
                    HFS_Subscription_Flag subflag , // When should be the object notified 
                    Unit unit                       // To which unit should the value to be converted before dispatch (if possible)
) 
{
    // QMutexLocker locker(&mutex); //! Would cause deadlock since _hasPath is using the same mutex
    if (!obj)
    {
        log(Info, "NULL object cannot be registered as ::subscribe");
        return;
    }
    HFSItem* item = _hasPath(topic);
    if (!item)
    {
        log(Info, "Cannot create path in ::subscribe");
        return;
    }

    Subscriber* sub = new Subscriber(obj, keyidx, funcname);

    item->subscribers.append(sub);
    int key = obj2int(obj);
    if (!subscribed_cache.contains(key))
    {
        QStringList val;
        val << topic;
        subscribed_cache.insert(key, val);
    }
    else
    {
        QStringList val = subscribed_cache.value(key);
        val.append(topic);
        subscribed_cache.insert(key, val);
    }
}

void HFS::unsubscribe(QObject *obj, QString path, QString funcname)
{
    // QMutexLocker locker(&mutex); //! Would cause deadlock since _hasPath is using the same mutex
    HFSItem* item = _hasPath(path,  false);
    if (!item)
    {
        log(Info, "Unregistered/non-existing path cannot be unsubscribe");
        return;
    }
    int key = obj2int(obj);
    if (!subscribed_cache.contains(key))
    {
        log(Info, "Cannot be unsubscribed if was not subscribed before");
    }
    else
    {
        QStringList val = subscribed_cache.value(key);
        val.removeAll(path);
        subscribed_cache.insert(key, val);
    }
    //item->registered.removeAll(obj); //!!
}

void HFS::objectDeleted(QObject* obj)
{
    log(Info, "::objectDeleted is not YET implemented");
    int key = obj2int(obj);
    if (key == 0) return;

    if (subscribed_cache.contains(key))
    {
        QStringList lst = subscribed_cache.value(key);
        for (int i = 0; i < lst.count(); i++)
        {
            unsubscribe(obj, lst.at(i));
        }
        subscribed_cache.remove(key);
    }
}

QStringList HFS::getSubList(QString path)
{
    QStringList retlst;
    if (HFSItem *item = _hasPath(path, false))
    {
        int ic = item->childCount();
        for (int i=0;i<ic;i++)
        {
            if (HFSItem *citem = item->child(i))
            {
                retlst.append(citem->id());
            }
        }
    }
    return retlst;
}

HFSItem* HFS::_hasPath(QString path, bool create)
{
    // QMutexLocker locker(&mutex);
    if (path.isEmpty()) return NULL;
    QStringList plst = path.split(".");
    if (plst.last().isEmpty())
    {
        log(Info, "looking for item with empty name");
        return NULL;
    }

    int pcnt = plst.count();
    HFSItem* current = rootItem;
    int i;
    for (i = 0; i < pcnt && current; i++)
    {
        bool found = false;
        for (int j = 0; j < current->childCount() && !found; ++j)
        {
            if (current->m_childItems.at(j)->_id == plst.at(i))
            {
                current = current->m_childItems.at(j);
                found = true;
            }
        }
        if (!found) current = NULL;
    }

    if (!current && create)             // path not found thus create it
    {
        current = _createPath(path);
        if (!current)
        {
            log(Info, QString(tr("Path <%1> cannot be created in HFS")).arg(path));
        }
    }
    return current;
}

HFSItem* HFS::_createPath(QString path)
{
//    QMutexLocker locker(&mutex);
    if (path.isEmpty()) return NULL;
    int created = 0;
    QStringList lst = path.split(".");
    int plst = lst.count();
    HFSItem* curr = rootItem;
    for (int i = 0; i < plst; ++i)
    {
        QString _cid = lst.at(i);
        bool found = false;
        for (int j = 0; j < curr->childCount() && !found; ++j)
        {
            if (curr->m_childItems.at(j)->_id == _cid)
            {
                found = true;
                curr = curr->m_childItems.at(j);
            }
        }
        if (!found)
        {
            beginResetModel();
            if (HFSItem* child = new HFSItem(_cid, curr))
            {
                created++;
                curr = child;
                propmap->insert(child->fullQMLPath(), "");
            }
            endResetModel();
        }
    }
    if (curr == rootItem) curr = nullptr;

    if (created)
    {
        if (DataPack* pack = new DataPack())
        {
            pack->setSource("HFS");
            pack->setCommand(PackCommands::HFSCreatePath);
            pack->attributes.insert("path", path);
            emit outPack(pack);
        }
    }

    return curr;
}

QString HFS::getRandomString(int length)
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int possibleCharactersLength = possibleCharacters.length();
    QString randomString;
    for (int i = 0; i < length; ++i)
    {
        int index = rndgen.bounded(possibleCharactersLength);
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}


int HFS::obj2int(QObject* obj)
{
    auto ret = reinterpret_cast<std::uintptr_t>(obj);
    return ret;
}

void HFS::log(int severity, QString logline)
{
    log(severity, logline, "HFS");
}

void HFS::log(int severity, QString logline, QString source)
{
    if (source.isEmpty()) source = "CORE";
    QDateTime dt;
    dt = QDateTime::currentDateTime();
    QString logstr = dt.toString("yyyy.MM.dd hh:mm:ss.zzz") + "["+QString::number(severity)+"]" +" (" + source + ") " + logline;
    qDebug() << logstr;
#if HDEBUG  // for direct debugging non-connected SLAVE nodes
    setData(System_LogLine, logstr);
#else
    dataChangeRequest(this, "", System_LogLine, logstr);
#endif

    if (DataPack* pack = new DataPack())
    {
        pack->setSource("HFS");
        pack->setCommand(PackCommands::HFSLog);
        pack->attributes.insert("source", source);
        pack->attributes.insert("logline", logline);
        emit outPack(pack);
    }
}

void HFS::inPack(DataPack* pack)
{
    qDebug() << "inPack ";
}

void HFS::fileChanged(const QString& str)
{
    log(Info,data(Bootup_ConfigFile).toString()+"changed. reloading system");
    if (str == data(Bootup_ConfigFile))
    {
        loadConfigIni(data(Bootup_ConfigFile).toString());
    }
}

void HFS::qmlValueChanged(const QString& key, const QVariant& value)
{
    qDebug() << "qmlValueChanged  key: " << key << "  val: " << value;
}

bool HFS::setAttribute(HFSItem* item, const QString &attr_name, QVariant value)
{
    if (!item) return false;
    QString topic = item->path() + "." + attr_name;
    if (HFSItem* attritem = _hasPath(topic))
    {
        attritem->setFlags(HFS_Attribute);
        attritem->setData(value);
    }
    return true;
}

bool HFS::removeAttribute(HFSItem *item, const QString &attrName)
{
    if (!item) return false;
    QString topic = item->fullPath() + "." + attrName;
    if (HFSItem* mitem = _hasPath(topic, false))
    {
        item->m_childItems.removeAll(mitem);
        QModelIndexList matches = match(index(0, 0, QModelIndex()), Qt::DisplayRole, topic, 1, Qt::MatchFlags(Qt::MatchExactly | Qt::MatchRecursive));
        if (matches.count() == 1)
        {
            QModelIndex cidx = matches.at(0);
            emit dataChanged(cidx, cidx);
            emit layoutChanged();
        }
    }
    return true;
}

bool HFS::setMethod(HFSItem* item, QObject *obj, const QString& methodName)
{
    if (!item) return false;
    QString topic = item->fullPath() + "." + methodName;
    if (HFSItem* mitem = _hasPath(topic))
    {
        if (obj)
        {
            Listener* listener = new Listener(obj, methodName);
            mitem->methods.append(listener);
            mitem->setFlags(HFS_Provided | HFS_Method);
        }
    }
    return true;
}

bool HFS::removeMethod(HFSItem* item, const QString& methodName)
{
    if (!item) return false;
    QString topic = item->fullPath() + "." + methodName;
    if (HFSItem* mitem = _hasPath(topic, false))
    {
        item->m_childItems.removeAll(mitem);
        QModelIndexList matches = match(index(0, 0, QModelIndex()), Qt::DisplayRole, topic, 1, Qt::MatchFlags(Qt::MatchExactly | Qt::MatchRecursive));
        if (matches.count() == 1)
        {
            QModelIndex cidx = matches.at(0);
            emit dataChanged(cidx, cidx);
            emit layoutChanged();
        }
    }
    return true;
}

bool HFS::providesAttribute(QObject* obj,   // returns true if registration is successful
    QString topic,                          // Topic that should be extended with this attribute (should be existing at this call)
    QString attrname,                       // Name of the attribute (if already exists, it would be overwritten)
    QVariant value                          // Current value of the attribute
)
{
    bool retbool = false;
    if (!obj) return retbool;
    if (HFSItem* hitem = _hasPath(topic, false))
    {
        setAttribute(hitem, topic, value);
        retbool = true;
    }
    return retbool;
}

bool HFS::providesMethod(                   // returns true if registration is successful
    QObject* obj,                           // Object that should be called async when the now registered method is called 
    QString topic,                          // Topic that should be extended with a method (should be existing before this call)
    QString methodname                      // name of the method
)
{
    bool retbool = false;
    if (!obj) return retbool;
    if (HFSItem* hitem = _hasPath(topic, false))
    {
        setMethod(hitem, obj, methodname);
        retbool = true;
    }
    return retbool;
}

QString HFS::provides(QObject* obj,             // The object that would keep this topic updated
                      QString topic,            // The unique id of the topic (warning if overdriven!)
                      Platforms platform,       // Type of the topic respectively to Platform
                      DataType datatype,        // Value representation for this topic
                      Unit unit,                // Unit of the topic's value
                      int hfs_flags,            // Additional HFS flags
                      QString regexp            // Regexp expression to check data validity
)
{
    HFSItem* mitem = _hasPath(topic, true);  // should add as a main entity type
    mitem->setPlatform(platform);
    QString token = "<unknown>";
    if (!mitem) return token;

    if (1)     // adding default parameters
    {
/*
        addProperty(mitem, "assumedState");
        addProperty(mitem, "attribution");
        addProperty(mitem, "available");
        addProperty(mitem, "deviceClass");
        addProperty(mitem, "deviceInfo");
        addProperty(mitem, "entityCategory");
        addProperty(mitem, "entityPicture");
        addProperty(mitem, "extraStateAttributes");
        addProperty(mitem, "hasEntityName");
        addProperty(mitem, "name");
        addProperty(mitem, "shouldPoll");
        addProperty(mitem, "uniqueId");
        addProperty(mitem, "entityRegistryEnabledDefault");
        addProperty(mitem, "entityRegistryVisibleDefault");
        addProperty(mitem, "forceUpdate");
        addProperty(mitem, "icon");
        addProperty(mitem, "enabled");
*/
    }

    switch (platform)
    {

        case SENSOR:
            /*
            addProperty(mitem, "lastReset");
            addProperty(mitem, "nativeValue");
            addProperty(mitem, "nativeUnit");
            addProperty(mitem, "stateClass");
            */
            token = topic;
            break;
        case BUTTON:
            /*
            checkMethod(obj, mitem, "pressed");
            */
            break;
        case AIR_QUALITY:
            break;
        case ALARM_CONTROL_PANEL:
            /*
            addProperty(mitem, "state");
            addProperty(mitem, "codeFormat");
            addProperty(mitem, "changedBy");
            */
            break;
        case BINARY_SENSOR:
            /*
            addProperty(mitem, "isOn");
            addProperty(mitem, "deviceClass");
            */
            break;
        case CALENDAR:
            /*
            addProperty(mitem, "state");
            addProperty(mitem, "startDate");
            addProperty(mitem, "endDate");
            */
            break;
        case CAMERA:
            /*
            addProperty(mitem, "isRecording");
            addProperty(mitem, "isStreaming");
            addProperty(mitem, "motionDetectionEnabled");
            addProperty(mitem, "isOn");
            addProperty(mitem, "brand");
            addProperty(mitem, "model");
            addProperty(mitem, "frameInterval");
            addProperty(mitem, "frontendStreamType");
            */
            break;
        case CLIMATE:
            /*
            addProperty(mitem, "temperatureUnit");
            addProperty(mitem, "precision");
            addProperty(mitem, "currentTemperature");
            addProperty(mitem, "currentHumidity");
            addProperty(mitem, "targetTemperature");
            addProperty(mitem, "targetTemperatureHigh");
            addProperty(mitem, "targetTemperatureLow");
            addProperty(mitem, "targetTemperatureStep");
            addProperty(mitem, "targetHumidity");
            addProperty(mitem, "maxTemp");
            addProperty(mitem, "minTemp");
            addProperty(mitem, "maxHumidity");
            addProperty(mitem, "minHumidity");
            addProperty(mitem, "hvacMode");
            addProperty(mitem, "hvacAction");
            addProperty(mitem, "hvacModes");
            addProperty(mitem, "presetMode");
            addProperty(mitem, "presetModes");
            addProperty(mitem, "fanMode");
            addProperty(mitem, "fanModes");
            addProperty(mitem, "swingMode");
            addProperty(mitem, "swingModes");
            addProperty(mitem, "isAuxHeat");
            addProperty(mitem, "supportedFeatures");
            */
            break;
        case COVER:
            /*
            addProperty(mitem, "currentCoverPosition");
            addProperty(mitem, "currentCoverTiltPosition");
            addProperty(mitem, "isOpening");
            addProperty(mitem, "isClosing");
            addProperty(mitem, "isClosed");
            addProperty(mitem, "deviceClass");
            addProperty(mitem, "supportedFeatures");
            */
            break;
        case DATASET:
            break;
        case DEVICE_SCANNER:
            /*
            addProperty(mitem, "sourceType");
            addProperty(mitem, "isConnected");
            addProperty(mitem, "batteryLevel");
            addProperty(mitem, "ipAddress");
            addProperty(mitem, "macAddress");
            addProperty(mitem, "hostname");
            */
            break;
        case DEVICE_TRACKER:
            /*
            addProperty(mitem, "sourceType");
            addProperty(mitem, "latitude");
            addProperty(mitem, "longitude");
            addProperty(mitem, "batteryLevel");
            addProperty(mitem, "locationAccuracy");
            addProperty(mitem, "locationName");
            */
            break;
        case FAN:
            /*
            addProperty(mitem, "currentDirection");
            addProperty(mitem, "isOn");
            addProperty(mitem, "oscillating");
            addProperty(mitem, "percentage");
            addProperty(mitem, "speedCount");
            addProperty(mitem, "supportedFeatures");
            addProperty(mitem, "presetMode");
            addProperty(mitem, "presetModes");
            */
            break;
        case GEO_LOCATION:
            break;
        case HUMIDIFIER:
            /*
            addProperty(mitem, "targetHumidity");
            addProperty(mitem, "maxHumidity");
            addProperty(mitem, "minHumidity");
            addProperty(mitem, "mode");
            addProperty(mitem, "availableModes");
            addProperty(mitem, "supportedFeatures");
            addProperty(mitem, "isOn");
            addProperty(mitem, "deviceClass");
            */
            break;
        case IMAGE_PROCESSING:
            break;
        case LIGHT:
            /*
            addProperty(mitem, "brightness");
            addProperty(mitem, "colorMode");
            addProperty(mitem, "colorTemp");
            addProperty(mitem, "effect");
            addProperty(mitem, "effectList");
            addProperty(mitem, "hsColor");
            addProperty(mitem, "isOn");
            addProperty(mitem, "maxMireds");
            addProperty(mitem, "minMireds");
            addProperty(mitem, "rgbColor");
            addProperty(mitem, "rgbwColor");
            addProperty(mitem, "rgbwwColor");
            addProperty(mitem, "supportedColorModes");
            addProperty(mitem, "supportedFeatures");
            addProperty(mitem, "whiteValue");
            addProperty(mitem, "xyColor");
            */
            break;
        case LOCK:
            /*
            addProperty(mitem, "changedBy");
            addProperty(mitem, "codeFormat");
            addProperty(mitem, "isLocked");
            addProperty(mitem, "isLocking");
            addProperty(mitem, "isUnlocking");
            addProperty(mitem, "isJammed");
            */
            break;
        case MAILBOX:
            break;
        case MEDIA_PLAYER:
            /*
            addProperty(mitem, "supportedFeatures");
            addProperty(mitem, "soundMode");
            addProperty(mitem, "soundModeList");
            addProperty(mitem, "source");
            addProperty(mitem, "sourceList");
            addProperty(mitem, "mediaImageUrl");
            addProperty(mitem, "mediaImageRemotelyAccessible");
            addProperty(mitem, "deviceClass");
            addProperty(mitem, "groupMembers");
            checkMethod(obj, mitem, "playMedia");
            checkMethod(obj, mitem, "browseMedia");
            checkMethod(obj, mitem, "selectSoundMode");
            checkMethod(obj, mitem, "selectSource");
            */
            break;
        case NOTIFY:
            break;
        case NUMBER:
            /*
            addProperty(mitem, "deviceClass");
            addProperty(mitem, "mode");
            addProperty(mitem, "nativeMaxValue");
            addProperty(mitem, "nativeMinValue");
            addProperty(mitem, "nativeStep");
            addProperty(mitem, "nativeValue");
            */
            break;
        case REMOTE:
            /*
            addProperty(mitem, "currentActivity");
            addProperty(mitem, "activityList");
            */
            break;
        case SCENE:
            break;
        case SELECT:
            /*
            addProperty(mitem, "currentOption");
            addProperty(mitem, "options");
            */
            break;
        case SIREN:
            /*
            addProperty(mitem, "isOn");
            addProperty(mitem, "availableTones");
            */
            break;
        case STT:
            break;
        case SWITCH:
            /*
            addProperty(mitem, "isOn");
            checkMethod(obj, mitem, "turnOn");
            checkMethod(obj, mitem, "turnOff");
            checkMethod(obj, mitem, "toggle");
            */
            break;
        case TTS:
            break;
        case UPDATE:
            /*
            addProperty(mitem, "autoUpdate");
            addProperty(mitem, "inProgress");
            addProperty(mitem, "installedVersion");
            addProperty(mitem, "latestVersion");
            addProperty(mitem, "releaseSummary");
            addProperty(mitem, "releaseUrl");
            addProperty(mitem, "title");
            */
            break;
        case VACUUM:
            /*
            addProperty(mitem, "name");
            addProperty(mitem, "state");
            addProperty(mitem, "batteryLevel");
            addProperty(mitem, "batteryIcon");
            addProperty(mitem, "fanSpeed");
            addProperty(mitem, "fanSpeedList");
            addProperty(mitem, "error");
            */
            break;
        case WATER_HEATER:
            /*
            addProperty(mitem, "minTemp");
            addProperty(mitem, "maxTemp");
            addProperty(mitem, "currentTemperature");
            addProperty(mitem, "targetTemperature");
            addProperty(mitem, "targetTemperatureHigh");
            addProperty(mitem, "targetTemperatureLow");
            addProperty(mitem, "temperatureUnit");
            addProperty(mitem, "currentOperation");
            addProperty(mitem, "operationList");
            addProperty(mitem, "supportedFeatures");
            addProperty(mitem, "isAwayModeOn");

            checkMethod(obj, mitem, "setTemperature");
            checkMethod(obj, mitem, "setOperationMode");
            checkMethod(obj, mitem, "turnAwayModeOn");
            checkMethod(obj, mitem, "turnAwayModeOff");
            */
            break;
        case WEATHER:
            /*
            addProperty(mitem, "condition");
            addProperty(mitem, "nativeTemperature");
            addProperty(mitem, "nativeTemperatureUnit");
            addProperty(mitem, "nativePressure");
            addProperty(mitem, "nativePressureUnit");
            addProperty(mitem, "humidity");
            addProperty(mitem, "ozone");
            addProperty(mitem, "nativeVisibility");
            addProperty(mitem, "nativeVisibilityUnit");
            addProperty(mitem, "nativeWindSpeed");
            addProperty(mitem, "nativeWindSpeedUnit");
            addProperty(mitem, "nativePrecipitationUnit");
            addProperty(mitem, "windBearing");
            addProperty(mitem, "forecast");
            */
            break;
    }
    return token;
}

QString HFS::providesSensor(QObject* obj,
                            QString topic,
                            DataType datatype,
                            Unit native_measurement,
                            QString keyidx,
                            int sub_precision,
                            int major_precision
)
{
#if 0
    QString retstr = provides(obj, path, SENSOR);
    retstr += ".";
    setProperty(retstr+"nativeUnit", native_measurement);
    return retstr;
#else
    provides(obj, topic, SENSOR, datatype, native_measurement);
    if (HFSItem *item = _hasPath(topic))
    {
        setAttribute(item, "major_precision", major_precision);
        setAttribute(item, "sub_precision", sub_precision);
    }
    return QString();
#endif
}


void HFS::dumpState(QString filename)
{
    QJsonDocument doc = saveAll();
    QString s(doc.toJson());
    QFile f(filename);
    if (f.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&f);
        stream << s;
        f.close();
    }
}

QJsonDocument HFS::saveAll()
{
    QJsonDocument doc;
    if (rootItem)
    {
        QJsonObject obj = rootItem->saveToJson(true);
       doc.setObject(obj);
    }

    return doc;
}

void HFS::loadAll(QJsonDocument)
{
}

void HFS::addDBHook(QString path, QString table, QString columnname, 
    DBColumnType datatype, int sub_precision, int major_precision)
{
    QStringList errlst;
    if (!db.open() || !query1) errlst << "database is not connected";
    if (path.isEmpty()) errlst << "path is not defined";
    if (table.isEmpty()) errlst << "table is not definded";
    if (columnname.isEmpty())
    {
        QStringList lst=path.split(".");
        if (lst.count()>1)
        {
            columnname=lst.last();
        }
        if (columnname.isEmpty())
        {
            errlst << "columnname is not defined";
        }
    }
    if (errlst.count())
    {
        for (int i=0;i<errlst.count();++i) log(0, "Cannot create DBHook: "+errlst.at(i));
        return;
    }

    if (datatype==DBF_SameAsDataType)
    {
        int dt = data(path+".nativeUnit").toInt();
        switch(dt)
        {
            case DT_NoDataType:                             break;
            case DT_Boolean:        datatype=DBF_Integer;   break;
            case DT_Bit:            datatype=DBF_Integer;   break;
            case DT_Byte:           datatype=DBF_Integer;   break;
            case DT_Short:          datatype=DBF_Integer;   break;
            case DT_UShort:         datatype=DBF_Integer;   break;
            case DT_Integer:        datatype=DBF_Integer;   break;
            case DT_UInteger:       datatype=DBF_Integer;   break;
            case DT_Float:          datatype=DBF_Float;     break;
            case DT_Double:         datatype=DBF_Double;    break;
            case DT_String:         datatype=DBF_VarChar;   break;
            case DT_ListElement:                            break;
            case DT_BitField16:                             break;
            case DT_BitField32:                             break;
            case DT_File:                                   break;
            case DT_StringList:                             break;
            case DT_Numeric:        datatype=DBF_Numeric;   break;
            case DT_TimeStamp:      datatype=DBF_TimeStamp; break;
            default:                                        break;
        }
    }

    if (!createDBColumn(table, columnname, datatype, sub_precision, major_precision))
    {
        log(0, "Cannot create DBHook: field creation/access error");
        return;
    }
}

void HFS::setDBHookSaveTimer(QString path, int interval)
{}

void HFS::maintainDB()
{}

bool HFS::createDBColumn(QString tablename, QString columnname, int datatype, int sub_precision, int major_precision)
{
    bool retval = false;
    if (!db.open() || tablename.isEmpty() || columnname.isEmpty() || !query1)
    {
        return retval;
    }

    tablename = tablename.toLower();
    columnname= columnname.toLower();

    QStringList utables = db.tables(QSql::Tables);          // user visible tables
    QStringList stables = db.tables(QSql::SystemTables);    // System tables
    if (stables.contains(tablename))                        // We do not mess with systemtables
    {
        log(0, "Bail out since messing with systemtable");
        return retval;
    }

    bool create_uid = false;
    if (!utables.contains(tablename))                       // The table does not exist at all
        create_uid = true;
    else
    {
        QSqlRecord rec = db.record(tablename);
        if (!rec.contains("uid"))
            create_uid = true;
    }

    if (create_uid)                                    // Let's create its skeleton
    {
#if 0   // bindValue seems to be broken. Investigated later
        QString sql_cmd = "CREATE TABLE ?";
        sql_cmd += " (uid BIGINT NOT NULL DEFAULT nextval('uid_serial'),";
        sql_cmd += " epoch BIGINT)";

        qDebug() << "SQL_CMD: " << sql_cmd << "   tablename: " << tablename;
        query1->prepare(sql_cmd);
        query1->addBindValue(tablename);
        if (!query1->exec())
        {
            log(0, "DB error on creating table: "+query1->lastError().text());
            return retval;
        }
#else
        QString sql_cmd = "CREATE TABLE "+tablename;
        sql_cmd += " (uid BIGINT NOT NULL DEFAULT nextval('uid_serial'),";
        sql_cmd += " epoch BIGINT)";

        if (!query1->exec(sql_cmd))
        {
            log(0, "DB error on creating table: "+query1->lastError().text());
            return retval;
        }
#endif

#if 0   // bindValue seems to be broken. Investigated later
        sql_cmd = "CREATE INDEX uid_idx ON :tablename (uid)";
        query1->prepare(sql_cmd);
        query1->bindValue(":tablename", tablename);
        if (!query1->exec())
        {
            log(0, "DB error on creating index: "+query1->lastError().text());
            return retval;
        }

#else
        sql_cmd = "CREATE INDEX uid_idx ON "+tablename+" (uid)";
        if (!query1->exec(sql_cmd))
        {
            log(0, "DB error on creating index: "+query1->lastError().text());
            return retval;
        }
#endif
    }

    if (columnname=="uid")               // "uid" field should be existing at this point
    {
        retval = true;
        return retval;
    }

    // Let's see if we have the field. If so, we do not do anyting. If type or precision is
    // changed, that would be handled in modifyDBColumn()

    QSqlRecord rec = db.record(tablename);
    QSqlField  dbf = rec.field(columnname);
    if (dbf.isValid())
    {
        log(0, columnname+" is existing in DB");
        // do nothing currently, might check its type/precision later
        retval = true;
        return retval;
    }
    else
    {
        QString datatype_str;
        QString major_precision_str = QString::number(major_precision);
        QString sub_precision_str = QString::number(sub_precision);
        switch(datatype)
        {
            case DBF_SameAsDataType:        // we have to read out the HFS datatype and match it up
                                            // Currently that is not yet implemented
                break;
            case DBF_Float:
            case DBF_Double:
                if (sub_precision_str=="-1") sub_precision_str="3";
                datatype_str = "DOUBLE PRECISION("+sub_precision_str+")";
                break;
            case DBF_Integer:
                datatype_str = "INTEGER";
                break;
            case DBF_Numeric:
                if (sub_precision_str=="-1") sub_precision_str="3";
                if (major_precision_str=="-1") major_precision_str="5";
                datatype_str = "NUMERIC("+major_precision_str+","+sub_precision_str+")";
                break;
            case DBF_VarChar:
                if (sub_precision_str=="-1") sub_precision_str="50";
                datatype_str = "VARCHAR("+sub_precision_str+")";
                break;
            case DBF_TimeStamp:
                datatype_str = "TIMESTAMP";
                break;
        }

        if (!datatype_str.isEmpty())
        {
            qDebug() << " --------------- COLUMN ------------------ ";
            qDebug() << "TABLENAME: " << tablename;
            qDebug() << "COLUMNNAME: " << columnname;
            qDebug() << "DATATYPE_STR: " << datatype_str;

#if 0       // bindValue seems to be broken. It will be investigated later
            QString sql_cmd = "ALTER TABLE ? ADD ? ?";
            query1->prepare(sql_cmd);
            query1->addBindValue(tablename);
            query1->addBindValue(columnname);
            query1->addBindValue(datatype_str);
            if (query1->exec())
            {
                retval = true;
            }
            else
            {
                log(0, "DB error on creating column: "+query1->lastError().text());
                return retval;
            }
#else
            QString sql_cmd = "ALTER TABLE "+tablename+" ADD "+columnname+" "+datatype_str;
            if (query1->exec(sql_cmd))
            {
                retval = true;
            }
            else
            {
                log(0, "DB error on creating column: "+query1->lastError().text());
                return retval;
            }

#endif
        }
    }
    return retval;
}

bool HFS::modifyDBColumn(QString tablename, QString columnname, int type, int sub_precision, int major_precision)
{
    bool retval = false;
    return retval;
}

void HFS::setData(QString path, QVariant value)
{
    if (HFSItem* item = _hasPath(path))
    {
        // set the value of the item firts
        item->setData(value);

        // updating model 
        QModelIndexList matches = match( index(0, 0, QModelIndex()), Qt::DisplayRole, path, 1,Qt::MatchFlags(Qt::MatchExactly | Qt::MatchRecursive));
        if (matches.count() == 1)
        {
            QModelIndex cidx = matches.at(0);
            emit dataChanged(cidx, cidx);
            emit layoutChanged();
        }

        // QML data upsync    
        propmap->insert(item->fullQMLPath(), value);
    }
}

QVariant HFS::getAttribute(QString topic,
    QString attributename)
{
    QVariant retval;
    QString attrtopic = topic + "." + attributename;
    if (HFSItem* hitem = _hasPath(attrtopic, false))
    {
        retval = hitem->data();
    }
    return retval;
}

bool  HFS::callMethod(QString topic,
    QString methodname)
{
    QString method_topic = topic;
    if (!methodname.isEmpty()) method_topic = topic + "." + methodname;
    if (HFSItem* hitem = _hasPath(method_topic, false))
    {
        hitem->callMethod();
        return true;
    }
    return false;
}

void HFS::ticktock_timeout()
{
//    dumpState("/home/xxx/hfs.dump");
    dtn = QDateTime::currentDateTime();

    // UPDATING DATE SENSORS
    if (dtn.date().year() != dto.date().year())
    {
        dataChangeRequest(this, "", System_Date_Year, dtn.date().year());
    }
    if (dtn.date().month() != dto.date().month())
    {
        dataChangeRequest(this, "", System_Date_Month, dtn.date().month());
    }
    if (dtn.date().day() != dto.date().day())
    {
        dataChangeRequest(this, "", System_Date_Day, dtn.date().day());
    }

    // UPDATING TIME SENSORS
    if (dtn.time().hour() != dto.time().hour())
    {
        dataChangeRequest(this, "", System_Time_Hour, dtn.time().hour());
    }
    if (dtn.time().minute() != dto.time().minute())
    {
        dataChangeRequest(this, "", System_Time_Minute, dtn.time().minute());
    }
    if (dtn.time().second() != dto.time().second())
    {
        dataChangeRequest(this, "", System_Time_Second, dtn.time().second());
    }

    int den_ms = (int)dtn.time().msecsSinceStartOfDay();
    int den = (int)(den_ms/ 1000.0);
    if (den != _dayepoch)
    {
        dataChangeRequest(this, "", System_Time_DayEpoch, den);
        _dayepoch = den;
    }

    int cep = QDateTime::currentSecsSinceEpoch();
    if (cep != _epoch)
    {
        dataChangeRequest(this, "", System_Time_Epoch, cep);
        _epoch = cep;
    }

    dto = dtn;

    //Calculating new trigger offset (with minimal overshoot)
    int time_offset = den_ms % 1000;
    time_offset += 50;
    time_offset = qBound(50, time_offset, 1000);
    ticktock_timer->start(time_offset);
}

/* ------------ SQL RELATED FUNCTIONS -------------------------------------- */

bool HFS::checkDataBase()
{
    bool retbool = true;
    if (!query1) return false;

    // Should check here all the tables and server side function existence and other
    // data integrity issues
    // Make sure indices are created/updated here

    // PSQL (for other DBS, this should be revised
//    query1->exec("VACUUM FULL ANALYZE");
    if (!query1->exec("CREATE SEQUENCE IF NOT EXISTS uid_serial"))
    {
//     log(0, "DB ERROR: "+query1->lastError().text());
    }

    // Check
    createDBColumn("log", "source",     DBF_VarChar, 64);
    createDBColumn("log", "severity",   DBF_Integer);
    createDBColumn("log", "logline",    DBF_VarChar, 512);
    return retbool;
}

void HFS::epochChanged(QVariant epoch_var)
{
    int epoch = epoch_var.toInt();
    QHashIterator<int, HFSSaveRegistryGroup*> it(savegroups);
    while (it.hasNext())
    {
        it.next();
        if (epoch % it.key() == 0)  // Epoch can be divided with interval, so let's save the whole group
        {
            HFSSaveRegistryGroup* group = it.value();
            QString sql_cmd = group->getSQLCmd();
            QStringList paths = group->getPaths();
            if (paths.count())
            {
                query1->prepare(sql_cmd);
                for (int i = 0; i < paths.count(); ++i)
                {
                    QString cpath = paths.at(i);
                    query1->bindValue(i, data(cpath));
                }
                if (!query1->exec())
                {
                    log(0, QString("SQL ERROR: %1").arg(query1->lastError().driverText() + " " + query1->lastError().databaseText()));
                }
            }
        }
    }
}
