#include "hfs.h"
#include "hactor.h"
#include "hsensor.h"

// ============================ HFS implementation ====================================
HFS::HFS(QObject* parent)
    : QAbstractItemModel(parent), propmap(nullptr), rootItem(nullptr), watcher(nullptr), query1(nullptr),
    query_log(nullptr), db_online(false), _flower(nullptr)
{
    rootItem = new HFSItem("root");
    watcher = new QFileSystemWatcher(this);
    propmap = new QQmlPropertyMap(this);

    setDefaultValues();

    // Setting up scheduler service
    scheduler_timer = new QTimer(this);
    scheduler_timeout_value = 250;
    scheduler_last_epoch = QDateTime::currentDateTime().toSecsSinceEpoch();
    dto = QDateTime::currentDateTime();
    QObject::connect(scheduler_timer, SIGNAL(timeout()), this, SLOT(scheduler_timeout()));
    scheduler_timer->setSingleShot(false);

    provides(this, System_Date_Year);
    provides(this, System_Date_Month);
    provides(this, System_Date_Day);

    provides(this, System_Time_Hour);
    provides(this, System_Time_Minute);
    provides(this, System_Time_Second);

    provides(this, System_Time_DayEpoch);
    provides(this, System_Time_Epoch);
}

HFS::~HFS()
{
    if (db.isValid() && db.isOpen())
        db.close();
    scheduler_timer->stop();
    rootItem->deleteLater();
}

void HFS::addHFSSubscribes()
{
    subscribe(this, System_Time_Epoch,  "hfs.epochChanged");
    subscribe(this, Bootup_NodeRole,    "hfs.nodeRoleChange");
    subscribe(this, Bootup_DeviceID,    "hfs.deviceIdChanged");
    subscribe(this, CS_ConnectionState, "hfs.connectionStateChanged");

    deviceIdChanged(data(Bootup_DeviceID).toInt());
    setData(Bootup_NodeRole, data(Bootup_NodeRole));                        // Sending out missing triggers 
    provides(this, "hfs.restoreState()", HFS_LocalUsage);
    provides(this, "hfs.epochChanged()", HFS_LocalUsage);
    _noderole = data(Bootup_NodeRole).toString().toLower();
}

void HFS::startServices()
{
    //    if (nodeRole() == NR_MASTER)             // Only master should provide ticks for now
    {                                                     // Later all nodes should have synced and fall back timing sources
        scheduler_timer->start(scheduler_timeout_value);
    }
    QObject::connect(propmap, SIGNAL(valueChanged(const QString&, const QVariant&)), this, SLOT(qmlValueChanged(const QString&, const QVariant&)));
}

void HFS::setDefaultValues()
{
    setData(Bootup_Name, "Unknown device");
    setData(Bootup_NodeRole, NR_UNDECIDED);
    setData(Bootup_MatixId, "1");
    setData(Bootup_Port, "33333");
    setData(Bootup_IP, "127.0.0.1");

    setData(Config_DB_Host, "127.0.0.1");
    setData(Config_DB_Type, "");
    setData(Config_DB_Name, "");
    setData(Config_DB_User, "");
    setData(Config_DB_Pass, "");
    setData(Config_DB_Port, "");

#if defined(WIN32)
    setData(Bootup_GUI, 1);
#elif defined(PF_WASM)
    setData(Bootup_GUI, 1);
#elif defined(PF_LINUX)
    setData(Bootup_GUI, 0);
#endif
    setData(HFS_State, HFSCreated);

    setData(System_Log, "");
    setData(System_LogLine, "");
    setData(System_BuildDate, HYPERBORG_BUILD_TIMESTAMP);
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

#if defined(PF_WASM)                                 // WebAssembly based clinet is always slave and use its origin
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
    setData(HFS_State, HFSBootInfoLoaded); // Step back to previous stage, triggering clearing operations, like unload QML in NodeCore

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
    if (parseError.error != QJsonParseError::NoError)
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
    QStack<HFSItem*> hstack;
    hstack.push(rootItem);
    //    log(Info, "ROOTITEM: " + rootItem->fullPath());
    int runblock = 0;
    while (!jstack.isEmpty() && runblock < 15)
    {
        runblock++;
        QJsonObject cjo = jstack.pop();
        HFSItem* item = hstack.pop();
        QStringList keys = cjo.keys();

        for (int i = 0; i < keys.count(); ++i)
        {
            QString ckey = keys.at(i);
            QString fp = item->fullPath();
            if (!fp.isEmpty()) fp += PATH_SEPARATOR;
            QString npath = fp + ckey;
            HFSItem* nitem = _hasPath(npath, true);
            QJsonValue jchild = cjo.value(ckey);

            if (jchild.isNull())
            {
                //      log(Info, QString(tr("JCHILD %1 is nullptr")).arg(ckey));
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
    setData(HFS_State, HFSConfigLoaded);
    return true;
}

void HFS::connectToSQL()
{
    // Main SQL related initialization
    db_online = false;
    if (db.open())
    {
        db.close();
    }

    if (query1)
    {
        delete query1;
        query1 = nullptr;
    }

    if (query_log)
    {
        delete query_log;
        query_log = nullptr;
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
    QString cmd = "INSERT INTO log (severity, logline, source) VALUES ('0','" + logline + "', 'SRC')";
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
    QList<HFSItem*> children;
    for (int i = 0; i < rootItem->childCount(); ++i)      // should be cached out or indexing goes wrong
    {
        if (HFSItem* citem = rootItem->child(i))
        {
            if (citem->id().toUpper() != "BOOTUP")
                children.append(citem);
        }
    }

    for (int i = 0; i < children.count(); ++i)
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

QVariant HFS::data(const QString &path)
{
    //QMutexLocker locker(&mutex);
    QVariant retvar;
    if (HFSItem* hitem = _hasPath(path, false))
    {
        return hitem->data();
    }
    return retvar;
}

QVariant HFS::childKeys(const QString &path)
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

QObject* HFS::getObject(const QString &path)
{
    QObject* retobj = nullptr;
    if (HFSItem* hitem = _hasPath(path, false))
    {
        retobj = hitem->object();
    }
    return retobj;
}


int HFS::dataChangeRequest(QObject* requester,      // The object that is requesting the datachange, this object would be notified if
    const QString &sessionid,                       // The device_sessionid.user_sessionid combo for ACL checking
    const QString &topic,                           // The topic of which value change was requested
    QVariant val)                                   // The new requested value
{
    //QMutexLocker locker(&mutex);
    if (topic == System_LogLine) // HFSLog
    {
        directLog(val.toString());
    }
    else if (DataPack* pack = new DataPack())
    {
        pack->setCommand(PackCommands::HFSDataChangeRequest);
        pack->attributes.insert("path", topic);
        pack->attributes.insert("value", val);
        pack->attributes.insert("acl_sid", sessionid);
        emit to_HFS_inBound(pack);
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

Flow* HFS::subscribe(QObject* obj,      // The object that request notification when the topic is changed
    const QString &topic,               // The topic the object is attached (subscirbed) to
    const QString &funcname,            // The obj's method name (slot) that would be called when topic is changed
    const QString &keyidx,              // If the function is a handles multiple topic, this key is added to the call for sorting out reason
    HFS_Subscription_Flag subflag,      // When should be the object notified
    Unit unit                           // To which unit should the value to be converted before dispatch (if possible)
)
{
    Flow *retflow = nullptr;
    // QMutexLocker locker(&mutex); //! Would cause deadlock since _hasPath is using the same mutex
    if (!obj)
    {
        log(Info, "NULL object cannot be registered as ::subscribe");
        return retflow;
    }
    HFSItem* item = _hasPath(topic);
    if (!item)
    {
        log(Info, "Cannot create path in ::subscribe");
        return retflow;
    }
    else
        qDebug() << "[" << topic << "] is created";

    if (Subscriber* sub = new Subscriber(obj, keyidx, funcname))
    {
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

        sub->_keyidx = keyidx;

        sync(HFSSubscribe, topic);

        // creating auto-flow for this subscription
        if (obj != _flower)
        {
            QDateTime dt = QDateTime::currentDateTime();
            QString flow_name = "auto_" + topic + "_" + dt.toString("yyyymmddhhmmsszzz");
            sub->flow_name = flow_name;
            if (retflow = _flower->createFlow(flow_name))
            {
                QString taskname = flow_name + "_s1";
                retflow->createTask(taskname, funcname);
                qDebug() << "TASK CREATED: " << taskname;
            }
        }
        else
        {
            sub->flow_name = keyidx;
        }
    }
    return retflow;
}

void HFS::unsubscribe(QObject* obj, const QString &topic, const QString &funcname)
{
    // QMutexLocker locker(&mutex); //! Would cause deadlock since _hasPath is using the same mutex
    HFSItem* item = _hasPath(topic, false);
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
        val.removeAll(topic);
        subscribed_cache.insert(key, val);
    }

    sync(HFSUnsubscribe, topic);
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

int HFS::getFlagsFromItem(HFSItem* item)
{
    int retint = -1;
    if (!item) return retint;
    retint = item->flags();
    return retint;
}

QString HFS::getRelativePath(HFSItem* item)
{
    if (!item) return QString();
    return getRelativePath(item->fullPath());
}

QString HFS::getRelativePath(QString path)
{
    QStringList pathElements = path.split(PATH_SEPARATOR);
    if (pathElements.isEmpty()) return QString();

    if (pathElements.first().toUpper() == "GLOBAL")
    {
        pathElements.removeFirst(); // Remove "GLOBAL"
    }
    else if (pathElements.size() > 1)
    {
        pathElements.removeFirst(); // Remove "node.<id>"
        pathElements.removeFirst();
    }

    return pathElements.join(PATH_SEPARATOR);
}

bool HFS::isPathGlobal(HFSItem* item)
{
    bool retbool = false;
    if (!item) return retbool;
    return isPathGlobal(item->fullPath());
}

bool HFS::isPathGlobal(QString path)
{
    QString retstr;
    QStringList retlst = path.split(PATH_SEPARATOR);
    if (retlst.count() < 1) return false;
    if (retlst.count()>0 && retlst.at(0).toUpper() == "GLOBAL")
    {
        return true;
    }
    return true;
}

HFSItem* HFS::_hasPath(const QString& path, bool create, int flags)
{
    // QMutexLocker locker(&mutex);
    if (path.isEmpty()) return nullptr;
    QStringList pathElements = path.split(PATH_SEPARATOR);
    if (pathElements.last().isEmpty())
    {
        log(Info, "Looking for item with empty name");
        return nullptr;
    }

    HFSItem* current = rootItem;
    for (const QString& element : pathElements)
    {
        bool found = false;
        for (HFSItem* child : current->m_childItems)
        {
            if (child->_id == element)
            {
                current = child;
                found = true;
                break;
            }
        }

        if (!found)
        {
            if (create)
            {
                current = _createPath(path, true, flags);
                if (!current)
                {
                    log(Info, QString(tr("Path <%1> cannot be created in HFS")).arg(path));
                }
            }
            else
            {
                return nullptr;
            }
        }
    }
    return current;
}

HFSItem* HFS::_createPath(const QString &path, bool do_sync, int flags)
{
    //    QMutexLocker locker(&mutex);
    if (path.isEmpty()) return nullptr;
    int created = 0;
    QStringList lst = path.split(PATH_SEPARATOR);
    int plst = lst.count();
    HFSItem* curr = rootItem;
    beginResetModel();
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
            if (HFSItem* child = new HFSItem(_cid, curr))
            {
                int cflags = flags;
                if (i != plst - 1) cflags = HFS_Container;
                created++;
                curr = child;
                if (i == plst - 1)
                {
                    child->setFlags(flags);
                }
                else
                {
                    child->setFlags(HFS_Container);
                }
            }
        }
    }
    endResetModel();
    if (curr == rootItem) curr = nullptr;

    if (created && do_sync)
    {
        sync(HFSCreatePath, path);
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

void HFS::log(int severity, const QString &logline, const QString &source)
{
    QDateTime dt;
    dt = QDateTime::currentDateTime();
    QString logstr = dt.toString("yyyy.MM.dd hh:mm:ss.zzz") + "[" + QString::number(severity) + "]" + " (" + source + ") " + logline;
    qDebug() << logstr;
    dataChangeRequest(this, "", System_LogLine, logstr);
}

void HFS::fileChanged(const QString& str)
{
    log(Info, data(Bootup_ConfigFile).toString() + "changed. reloading system");
    if (str == data(Bootup_ConfigFile))
    {
        loadConfigIni(data(Bootup_ConfigFile).toString());
    }
}

void HFS::qmlValueChanged(const QString& key, const QVariant& value)
{
    qDebug() << "qmlValueChanged  key: " << key << "  val: " << value;
}

bool HFS::setAttribute(HFSItem* item, const QString& attr_name, QVariant value)
{
    if (!item) return false;
    QString topic = item->path() + PATH_SEPARATOR + attr_name;
    if (HFSItem* attritem = _hasPath(topic))
    {
        attritem->setFlags(HFS_Attribute);
        attritem->setData(value);
        sync(HFSSetAttribute, topic);
    }
    return true;
}

bool HFS::removeAttribute(HFSItem* item, const QString& attrName)
{
    if (!item) return false;
    QString topic = item->fullPath() + PATH_SEPARATOR + attrName;
    if (HFSItem* mitem = _hasPath(topic, false))
    {
        item->m_childItems.removeAll(mitem);
        QModelIndexList matches = match(index(0, 0, QModelIndex()), Qt::DisplayRole, topic, 1, Qt::MatchFlags(Qt::MatchExactly | Qt::MatchRecursive));
        if (matches.count() == 1)
        {
            QModelIndex cidx = matches.at(0);
            emit dataChanged(cidx, cidx);
            emit layoutChanged();
            sync(HFSRemoveAttribute, topic);
        }
    }
    return true;
}

bool HFS::removeMethod(HFSItem* item, const QString& methodName)
{
    if (!item) return false;
    QString topic = item->fullPath() + PATH_SEPARATOR + methodName;
    if (HFSItem* mitem = _hasPath(topic, false))
    {
        item->m_childItems.removeAll(mitem);
        QModelIndexList matches = match(index(0, 0, QModelIndex()), Qt::DisplayRole, topic, 1, Qt::MatchFlags(Qt::MatchExactly | Qt::MatchRecursive));
        if (matches.count() == 1)
        {
            QModelIndex cidx = matches.at(0);
            emit dataChanged(cidx, cidx);
            emit layoutChanged();
            sync(HFSRemoveMethod, topic);
        }
    }
    return true;
}

int HFS::getDevIdFromPath(QString path)
{
    int retint = -1;
    if (HFSItem* hitem = _hasPath(path, false))
    {
        retint = hitem->devId();
    }

    return retint;
}

QString HFS::provides(QObject* obj,         // The object that would keep this topic updated
    const QString &topic,                   // The unique id of the topic (warning if overdriven!)
    int hfs_flags,                          // Additional HFS flags
    DataType datatype,                      // Value representation for this topic
    Unit unit,                              // Unit of the topic's value
    const QString&regexp                    // Regexp expression to check data validity
)
{
    QString token;
    if (HFSItem* mitem = _hasPath(topic, true))  // should add as a main entity type
    {
        mitem->setObject(obj);
        mitem->setFlags(hfs_flags);
        if ((hfs_flags & HFS_RemotelyCreated) == 0)
        {
            mitem->setDevId(devId());
        }

        if (HActor* actor = dynamic_cast<HActor*>(obj))
        {
            actor->setUnit(preferredUnit(actor->rawunit()));
            connect(actor, &HActor::valueChanged, mitem, &HFSItem::setData);
            if (const QMetaObject* mobject = actor->metaObject())
            {
                int pc = mobject->propertyCount();
                int mc = mobject->methodCount();

                // collecting properties
                for (int i = 0; i < pc; ++i)
                {
                    QMetaProperty mprop = mobject->property(i);
                    QString prop_name = mprop.name();
                    HFSItem* propchild = new HFSItem(prop_name, mitem, mprop.read(obj));
                }

                // collecting methods
                for (int i = 0; i < mc; ++i)
                {
                    QMetaMethod mmethod = mobject->method(i);
                    if (mmethod.access() == QMetaMethod::Public)
                    {
                        if (mmethod.methodType() == QMetaMethod::Slot)
                        {
                            QString method_name = mmethod.name();
                            HFSItem* methodchild = new HFSItem(method_name, mitem);
                        }
                    }
                }
            }
        }
    }
    return token;
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

QList<HFSItem*> HFS::flatItemList()
{
    QList<HFSItem*> retlist;
    if (!rootItem) return retlist;
    retlist << rootItem;
    int idx = 0;
    while (idx < retlist.count())
    {
        HFSItem* it = retlist.at(idx);
        for (int i = 0; i < it->m_childItems.count(); ++i)
        {
            retlist << it->m_childItems.at(i);
        }
        ++idx;
    }
    if (retlist.count())                        // Do not trasfer out root element
        retlist.removeFirst();
    return retlist;
}

QJsonDocument HFS::saveAll()
{
    QJsonDocument doc;
    bool only_global = true;
    QList<HFSItem*> items = flatItemList();
    QJsonArray arr;
    for (int i=0;i<items.count();++i)
    {
        if (HFSItem* citem = items.at(i))
        {
            arr << items.at(i)->saveToJson();
        }
    }
    QJsonObject obj;
    obj["hfs_array"] = arr;
    doc.setObject(obj);
    return doc;
}

void HFS::flow(QString flow, QVariant val)
{
    qDebug() << "FLOW: " << flow << " val: " << val;
    _flower->startJob(flow, "", val);
}


void HFS::testDump()
{
    QJsonDocument doc;
    doc.setObject(rootItem->saveToJson(HFSItem::FullRecursive));
    QString str = doc.toJson();
    QFile f("c:\\projects\\hyperborg\\dump.txt");
    if (f.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&f);
        stream << str;
        f.close();
    }

    rootItem->reset();

    if (f.open(QIODevice::ReadOnly))
    {
        QJsonParseError parseError;
        QJsonDocument doc;
        doc = QJsonDocument::fromJson(f.readAll(), &parseError);
        rootItem->loadFromJson(doc.object());
    }
}

void HFS::setData(QString topic, QVariant value, bool do_sync)
{
    do_sync = false;
    if (HFSItem* item = _hasPath(topic))
    {
        // set the value of the item firts
        item->setData(value);
        if (do_sync)
        {
            sync(HFSSetData, topic, value);
        }

        // updating model
        QModelIndexList matches = match(index(0, 0, QModelIndex()), Qt::DisplayRole, topic, 1, Qt::MatchFlags(Qt::MatchExactly | Qt::MatchRecursive));
        if (matches.count() == 1)
        {
            QModelIndex cidx = matches.at(0);
            emit dataChanged(cidx, cidx);
            emit layoutChanged();
        }

        // QML data upsync
        propmap->insert(item->fullQMLPath(), value);

        // Notifie all registered object about the change

        for (int i = 0; i < item->subscribers.count(); i++)
        {
            if (Subscriber* sub = item->subscribers.at(i))
            {
                QString flow_name = sub->flow_name;
                emit startJob(flow_name, topic, value);
            }
        }
    }
}

QVariant HFS::getAttribute(const QString &topic, const QString &attributename, const QVariant &defvalue)
{
    QVariant retval = defvalue;
    QString attrtopic = topic + PATH_SEPARATOR + attributename;
    if (HFSItem* hitem = _hasPath(attrtopic, false))
    {
        retval = hitem->data();
    }
    return retval;
}

void HFS::scheduler_timeout()
{
    dtn = QDateTime::currentDateTime();
    int epoch_new = dtn.toSecsSinceEpoch();
    bool skew = false;

    if (epoch_new == scheduler_last_epoch && scheduler_skew_epoch.isEmpty())          // We have multiple trigger in a second to balance timing calculation errors under load
    {                                                                                 // Here it seems that the timeout came in the same second we already processed, so just bail out
        return;
    }
    else if (epoch_new==scheduler_last_epoch+1)                                       // We are processing the next second after the second we already processed. This is normal
    {
                                                                                      // Normal operation here, but we cannot assume that we are not in skew mode
    }
    else if (epoch_new>scheduler_last_epoch)                                          // We skipped one ore more seconds since the last processed second, so we need to enqueue
    {
        int diff = dto.msecsTo(dtn);                                                  // Switch to dates to avoud DST induced errors in epoch calculation
        if (diff>0)
        {
            bool limit = false;
            if (scheduler_skew_epoch.count()>10000)
                limit = true;
            int sdiff = (int)(diff/1000.);                                            // Need difference in seconds
            for (int i=1;i<=sdiff && !limit;i++)                                      // We enqueue only 10000 missed seconnd
            {
                scheduler_skew_epoch.append(dto.addSecs(i));                          // Adding missed seconds in the skews list
            }
        }
    }

    if (!scheduler_skew_epoch.isEmpty())                                              // We should process skewed seconds first
    {
        if (scheduler_skew_epoch.constLast()!=dtn)                                    // If we are processing skews, we need to add the currenct second at the end of the list
        {                                                                             // to make sure that is processed later on when the skewing is catcing up
            scheduler_skew_epoch.append(dtn);
        }
        dtn = scheduler_skew_epoch.takeFirst();
        skew = true;
    }

    int den_ms = (int)dtn.time().msecsSinceStartOfDay();
    int den = (int)(den_ms / 1000.0);

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

    // UPDATING DAILY SECOND TIMER
    if (den != _dayepoch)
    {
        dataChangeRequest(this, "", System_Time_DayEpoch, den);
        _dayepoch = den;
    }

    if (skew)                                                                                // In skew mode, we need to recalculate this to dispatch all missed epoch events too
        epoch_new = dtn.toSecsSinceEpoch();                                                  // Need to recalculate, since
    if (epoch_new != _epoch)
    {
        dataChangeRequest(this, "", System_Time_Epoch, epoch_new);
        _epoch = epoch_new;
    }

    dto = dtn;
    scheduler_last_epoch = den;
}

Unit HFS::preferredUnit(Unit rawunit)
{
    Unit retunit = rawunit;
    switch (rawunit)
    {
        case Farenheit:
            retunit = Celsius;
            break;
        case Mph:
            retunit = Kmh;
            break;
        case InHg:
            retunit = hPa;
            break;
        case Inch:
            retunit = Centimeter;
            break;
    }
    return retunit;
}

void HFS::nodeRoleChanged(Job *job)
{
    _noderole = job->variant.toString().toLower();
    log(0, "NODEROLE: " + _noderole);
}

void HFS::deviceIdChanged(Job *job)
{
    deviceIdChanged(job->variant.toInt());
}

void HFS::deviceIdChanged(int id)
{
    _devid = id;
    log(0, "DEVICE ID: " + QString::number(_devid));
}

void HFS::connectionStateChanged(Job *job)
{
    int cstate = job->variant.toInt();
    qDebug() << "HFS Connection state is: " << cstate;
}

void HFS::epochChanged(Job *job)
{
    if (!query1) return;
    int epoch = job->variant.toInt();
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


void HFS::sync(PackCommands cmd, QString topic, QVariant var)
{
    AttributeList lst;
    Attribute attr;
    attr.first = "value";
    attr.second = var;
    lst << attr;
    sync(cmd, topic, lst);
}

void HFS::sync(PackCommands cmd, QString topic, AttributeList attrs)
{
    // qDebug() << "SHOULD symc: " << cmd << " topic: " << topic;
    // Check node role

    // Check for topic (should not sync local-only topic tree - and that tree should be as small as possible)

    if (DataPack* pack = new DataPack())
    {
        pack->setSource(devId());
        pack->setCommand(cmd);
        // feed in input params first, so they do not overwrite internal params
        for (int i = 0; i < attrs.count(); ++i)
        {
            pack->setAttribute(attrs.at(i).first, attrs.at(i).second);
        }

        pack->setAttribute("topic", topic);
        emit to_HFS_inBound(pack);
    }
}

/* Inter-node sync functions */

QVariant HFS::getItemDump(Job* job)
{
    QVariant var;
    if (!job) return var;

    QString path = job->getAttribute("path").toString();
    if (auto* item = this->_hasPath(path, false))
    {
        job->setAttribute("result", item->saveToJson());
        item->dumpObjectInfo();
    }
    else
    {
        job->setAttribute("result", "not_found");
    }

    return var;
}
