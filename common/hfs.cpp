#include "hfs.h"

// ============================ HFS implementation ====================================
HFS::HFS( QObject* parent)
    : QAbstractItemModel(parent), propmap(NULL), rootItem(NULL), watcher(NULL)
{
    rootItem = new HFSItem("root");
    watcher = new QFileSystemWatcher(this);

    propmap = new QQmlPropertyMap(this);
    QObject::connect(propmap, SIGNAL(valueChanged(const QString&, const QVariant&)), this, SLOT(qmlValueChanged(const QString&, const QVariant&)));
    setDefaultValues();
    qDebug() << "THREAD: " << QThread::currentThread();

#if 0
    _hasPath("test.heartbeat");
    testtimer = new QTimer(this);
    bool fff = QObject::connect(testtimer, SIGNAL(timeout()), this, SLOT(heartBeatTest()));
    testtimer->setSingleShot(false);
    testtimer->start(100);
#endif

}

HFS::~HFS()
{
    delete rootItem;
}

void HFS::setDefaultValues()
{
    setData(Bootup_NodeRole, NR_UNDECIDED);
    setData(Bootup_MatixId,  "1");
    setData(Bootup_Port,     "33333");
    setData(Bootup_IP,        "127.0.0.1");
    setData(Bootup_DB_Host,   "127.0.0.1");
    setData(Bootup_DB_Type,   "");
    setData(Bootup_DB_Name,   "");
    setData(Bootup_DB_User,   "");
    setData(Bootup_DB_Pass,   "");
    setData(Bootup_DB_Port,   "");
#if defined(WIN32)
    setData(Bootup_GUI,       1);
#elif defined(WASM)
    setData(Bootup_GUI,       1);
#elif defined(LINUX)
    setData(Bootup_GUI, 0);
#endif

    setData("system.log", "");
    setData("system.logline", "");

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
    qDebug() << "---section BOOTUP---";
    log(0, tr("Section BOOTUP"));
    bool retbool = false;
    watcher->removePath(data("bootup.config_file").toString());

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
	    log(0, QString(tr("USING CONFIGURATION (BOOTUP) FILE: %1")).arg(filename));
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
    if (1)	// Enable local config loading for slave nodes
    {
	QString cfile = data("bootup.config_file").toString();
	if (!cfile.isEmpty())
	{
	    if (!loadConfigIni(cfile))
	    {
		    log(0, QString(tr("Configuration file <%1> cannot be opened!")).arg(cfile));
	    }
	}
	else
	{
	    log(0, QString(tr("Config file is not defined in the bootup.ini file")));
	}
    }

    QString str = data("bootup.config_file").toString();
    watcher->addPath(data("bootup.config_file").toString());
    QObject::connect(watcher, SIGNAL(fileChanged(const QString&)), this, SLOT(fileChanged(const QString&)));


#endif
    return retbool;
}

bool HFS::loadConfigIni(QString jsonfile, bool _clear)
{
    log(0, QString(tr("OPENING CONFIGURATION FILE <%1> with clear flag: %2")).arg(jsonfile).arg(_clear));
    // Let's make sure we can read the json into the memory before we start to update this node
    if (jsonfile.isEmpty())
    {
	    log(0, "Cannot open config file without a name!");
	    return false;
    }
    QFile f(jsonfile);
    if (!f.open(QIODevice::ReadOnly))
    {
	    log(0, QString("cannot open config file with name: <%1>").arg(jsonfile));
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
	    log(0, QString("Config file load failed due to error at %1 : %2").arg(parseError.offset).arg(parseError.errorString()));
        return false;
    }

    // So far, so good. We could load json into memory and it could be parsed correctly
    // So now we drop out the complete HFS, except the entries under the bootup. path
    QString str = data("bootup.config_file").toString();
    watcher->addPath(data("bootup.config_file").toString());
    log(0, "Clearing HFS ...");
    if (_clear) clear();

    QJsonObject jsonObj;
    jsonObj = doc.object();
    QStack<QJsonObject> jstack;
    jstack.push(jsonObj);
    QStack<HFSItem *> hstack;
    hstack.push(rootItem);
//    log(0, "ROOTITEM: " + rootItem->fullPath());
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
//		log(0, QString(tr("JCHILD %1 is NULL")).arg(ckey));
	    }
	    else if (jchild.isUndefined())
	    {
//		log(0, QString(tr("JCHILD %1 is UNDEFINED")).arg(ckey));
	    }
	    else if (jchild.isArray())
	    {
//		log(0, QString(tr("JCHILD %1 is ARRAY")).arg(ckey));
	    }
	    else if (jchild.isBool())
	    {
//		log(0, QString(tr("JCHILD %1 is BOOL")).arg(ckey));
        	nitem->setData(jchild.toBool());
	    }
	    else if (jchild.isDouble())
	    {
//		log(0, QString(tr("JCHILD %1 is DOUBLE")).arg(ckey));
        	nitem->setData(jchild.toDouble());
    	    }
    	    else if (jchild.isString())
    	    {
        	log(0, QString(tr("JCHILD %1 is STRING  - set to %3")).arg(npath).arg(jchild.toString()));
        	nitem->setData(jchild.toString());
    	    }
    	    else if (jchild.isObject())
	    {
//		    log(0, QString(tr("JCHILD %1 is OBJECT")).arg(ckey));
		    hstack.push(nitem);
		    jstack.push(jchild.toObject());
	    }
	}
    }
    return true;    
}

bool HFS::clear()		// clear() drops all HFSItem EXCEPT nodes in "bootup." path
{
    QMutexLocker locker(&mutex);
    if (!rootItem) return false;
    beginResetModel();
    QList<HFSItem *> children;
    for (int i=0;i<rootItem->childCount();++i)		// should be cached out or indexing goes wrong
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
    log(0, "HFS::saveInitFiles() is not yet implemented");
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
        return item->data();
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
//            retlst.append(hitem->child(i)->data().toString());
            retlst.append(hitem->child(i)->id());
        }
    }
    return QVariant(retlst);
}

void HFS::dataChangeRequest(QString path, QVariant val)
{
    //QMutexLocker locker(&mutex);
#if 0
    qDebug() << "dataChangeRequest - " << path << " val: " << val.toInt();
    emit signal_dataChangeRequest(path, val);
#else
    if (DataPack* pack = new DataPack())
    {
        pack->setSource("HFS");
        pack->setCommand(PackCommands::HFSDataChangeRequest);
        pack->attributes.insert("path", path);
        pack->attributes.insert("value", val);
        emit outPack(pack);
    }
#endif
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

void HFS::subscribe(QObject *obj, QString path, QString fncname, QString keyidx)
{
    // QMutexLocker locker(&mutex); //! Would cause deadlock since _hasPath is using the same mutex
    if (!obj)
    {
        log(0, "NULL object cannot be registered as ::subscribe");
        return;
    }
    HFSItem* item = _hasPath(path);
    if (!item) 
    {
        log(0, "Cannot create path in ::subscribe");
        return;
    }

    Registered* reg = new Registered(obj, keyidx, fncname);

    item->registered.append(reg);
    
    int key = obj2int(obj);
    if (!subscribed_cache.contains(key))
    {
        QStringList val;
        val << path;
        subscribed_cache.insert(key, val);
    }
    else
    {
        QStringList val = subscribed_cache.value(key);
        val.append(path);
        subscribed_cache.insert(key, val);
    }
}

void HFS::unsubscribe(QObject *obj, QString path, QString funcname)
{
    // QMutexLocker locker(&mutex); //! Would cause deadlock since _hasPath is using the same mutex
    HFSItem* item = _hasPath(path,  false);
    if (!item)
    {
        log(0, "Unregistered/non-existing path cannot be unsubscribe");
        return;
    }
    int key = obj2int(obj);
    if (!subscribed_cache.contains(key))
    {
        log(0, "Cannot be unsubscribed if was not subscribed before");
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
    log(0, "::objectDeleted is not YET implemented");
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
    qDebug() << "---- getSubList --- path: " << path;
    QStringList retlst;
    if (HFSItem *item = _hasPath(path, false))
    {
	int ic = item->childCount();
	qDebug() << "childcount: " << ic;
	for (int i=0;i<ic;i++)
        {
	    if (HFSItem *citem = item->child(i))
	    {
		qDebug() << "ID: " << citem->id();
		retlst.append(citem->id());
	    } else qDebug() << "citem IS NULL";
	}
    } else qDebug() << "no such path";
    qDebug() << "---- end of getSubList --- path: " << path;
    return retlst;
}

HFSItem* HFS::_hasPath(QString path, bool create)
{
    // QMutexLocker locker(&mutex);
    if (path.isEmpty()) return NULL;
    QStringList plst = path.split(".");
    if (plst.last().isEmpty())
    {
        log(0, "looking for item with empty name");
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
	    log(0, QString(tr("Path <%1> cannot be created in HFS")).arg(path));
	}
    }
    return current;
}

HFSItem* HFS::_createPath(QString path)
{
//    QMutexLocker locker(&mutex);
    if (path.isEmpty()) return NULL;
    int created = 0;
    beginResetModel();
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
            HFSItem* child = new HFSItem(_cid, curr);
            created++;
            curr = child;
        }
    }
    if (curr == rootItem) curr = nullptr;
    endResetModel();

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

void HFS::heartBeatTest()
{
    qDebug() << " --heartBeatTest --";
    int zz = 0;
    zz++;
    if (HFSItem *item= _hasPath("test.heartbeat"))
    {
	    int val = rndgen.bounded(60) - 10;
	    item->setData(val);
    }
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

    setData("system.logline", logstr);

#if 1
    qDebug() << logstr;
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
    int zz = 0;
    zz++;
}

void HFS::fileChanged(const QString& str)
{
    log(0,data("bootup.config_file").toString()+"changed. reloading system");
    if (str == data("bootup.config_file"))
    {
        this->loadConfigIni(data("bootup.config_file").toString());
    }
}

void HFS::qmlValueChanged(const QString& key, const QVariant& value)
{
    qDebug() << "qmlValueChanged  key: " << key << "  val: " << value;
}

HFSItem* HFS::addProperty(HFSItem* parent, QString prop_name, int platform)
{
    HFSItem* citem = new HFSItem(prop_name, parent, platform);
    return citem;
}

HFSItem* HFS::addMethod(QObject *obj, HFSItem *parent, QString methodName, QString keyidx)
{
    if (HFSItem* citem = addProperty(parent, methodName, METHOD))
    {
        subscribe(obj, citem->fullPath(), methodName, keyidx);
        return citem;
    }
    return NULL;
}

QString HFS::provides(QObject *obj, QString path, int platform, QString keyidx)
{
    HFSItem* mitem = _hasPath(path, true);  // should add as a main entity type
    mitem->setPlatform(platform);
    QString token = "<unknown>";
    if (!mitem) return token;

    if (1)     // adding default parameters
    {
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
    }

    switch (platform)
    {
        case AIR_QUALITY:
            break;
        case ALARM_CONTROL_PANEL:
            addProperty(mitem, "state");
            addProperty(mitem, "codeFormat");
            addProperty(mitem, "changedBy");
            break;
        case BINARY_SENSOR:
            addProperty(mitem, "isOn");
            addProperty(mitem, "deviceClass");
            break;
        case BUTTON:
            addMethod(obj, mitem, "pressed");
            break;
        case CALENDAR:
            addProperty(mitem, "state");
            addProperty(mitem, "startDate");
            addProperty(mitem, "endDate");
            break;
        case CAMERA:
            addProperty(mitem, "isRecording");
            addProperty(mitem, "isStreaming");
            addProperty(mitem, "motionDetectionEnabled");
            addProperty(mitem, "isOn");
            addProperty(mitem, "brand");
            addProperty(mitem, "model");
            addProperty(mitem, "frameInterval");
            addProperty(mitem, "frontendStreamType");
            break;
        case CLIMATE:
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
            break;
        case COVER:
            addProperty(mitem, "currentCoverPosition");
            addProperty(mitem, "currentCoverTiltPosition");
            addProperty(mitem, "isOpening");
            addProperty(mitem, "isClosing");
            addProperty(mitem, "isClosed");
            addProperty(mitem, "deviceClass");
            addProperty(mitem, "supportedFeatures");
            break;
        case DATASET:
            break;
        case DEVICE_SCANNER:
            addProperty(mitem, "sourceType");
            addProperty(mitem, "isConnected");
            addProperty(mitem, "batteryLevel");
            addProperty(mitem, "ipAddress");
            addProperty(mitem, "macAddress");
            addProperty(mitem, "hostname");
            break;
        case DEVICE_TRACKER:
            addProperty(mitem, "sourceType");
            addProperty(mitem, "latitude");
            addProperty(mitem, "longitude");
            addProperty(mitem, "batteryLevel");
            addProperty(mitem, "locationAccuracy");
            addProperty(mitem, "locationName");
            break;
        case FAN:
            addProperty(mitem, "currentDirection");
            addProperty(mitem, "isOn");
            addProperty(mitem, "oscillating");
            addProperty(mitem, "percentage");
            addProperty(mitem, "speedCount");
            addProperty(mitem, "supportedFeatures");
            addProperty(mitem, "presetMode");
            addProperty(mitem, "presetModes");
            break;
        case GEO_LOCATION:
            break;
        case HUMIDIFIER:
            addProperty(mitem, "targetHumidity");
            addProperty(mitem, "maxHumidity");
            addProperty(mitem, "minHumidity");
            addProperty(mitem, "mode");
            addProperty(mitem, "availableModes");
            addProperty(mitem, "supportedFeatures");
            addProperty(mitem, "isOn");
            addProperty(mitem, "deviceClass");
            break;
        case IMAGE_PROCESSING:
            break;
        case LIGHT:
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
            break;
        case LOCK:
            addProperty(mitem, "changedBy");
            addProperty(mitem, "codeFormat");
            addProperty(mitem, "isLocked");
            addProperty(mitem, "isLocking");
            addProperty(mitem, "isUnlocking");
            addProperty(mitem, "isJammed");
            break;
        case MAILBOX:
            break;
        case MEDIA_PLAYER:
            addProperty(mitem, "supportedFeatures");
            addProperty(mitem, "soundMode");
            addProperty(mitem, "soundModeList");
            addProperty(mitem, "source");
            addProperty(mitem, "sourceList");
            addProperty(mitem, "mediaImageUrl");
            addProperty(mitem, "mediaImageRemotelyAccessible");
            addProperty(mitem, "deviceClass");
            addProperty(mitem, "groupMembers");
            addMethod(obj, mitem, "playMedia");
            addMethod(obj, mitem, "browseMedia");
            addMethod(obj, mitem, "selectSoundMode");
            addMethod(obj, mitem, "selectSource");
            break;
        case NOTIFY:
            break;
        case NUMBER:
            addProperty(mitem, "deviceClass");
            addProperty(mitem, "mode");
            addProperty(mitem, "nativeMaxValue");
            addProperty(mitem, "nativeMinValue");
            addProperty(mitem, "nativeStep");
            addProperty(mitem, "nativeValue");
            break;
        case REMOTE:
            addProperty(mitem, "currentActivity");
            addProperty(mitem, "activityList");
            break;
        case SCENE:
            break;
        case SELECT:
            addProperty(mitem, "currentOption");
            addProperty(mitem, "options");
            break;
        case SENSOR:
            addProperty(mitem, "lastReset");
            addProperty(mitem, "nativeValue");
            addProperty(mitem, "nativeUnitOfMeasurement");
            addProperty(mitem, "stateClass");
            break;
        case SIREN:
            addProperty(mitem, "isOn");
            addProperty(mitem, "availableTones");
            break;
        case STT:
            break;
        case SWITCH:
            addProperty(mitem, "isOn");
            addMethod(obj, mitem, "turnOn");
            addMethod(obj, mitem, "turnOff");
            addMethod(obj, mitem, "toggle");
            break;
        case TTS:
            break;
        case UPDATE:
            addProperty(mitem, "autoUpdate");
            addProperty(mitem, "inProgress");
            addProperty(mitem, "installedVersion");
            addProperty(mitem, "latestVersion");
            addProperty(mitem, "releaseSummary");
            addProperty(mitem, "releaseUrl");
            addProperty(mitem, "title");
            break;
        case VACUUM:
            addProperty(mitem, "name");
            addProperty(mitem, "state");
            addProperty(mitem, "batteryLevel");
            addProperty(mitem, "batteryIcon");
            addProperty(mitem, "fanSpeed");
            addProperty(mitem, "fanSpeedList");
            addProperty(mitem, "error");
            break;
        case WATER_HEATER:
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

            addMethod(obj, mitem, "setTemperature");
            addMethod(obj, mitem, "setOperationMode");
            addMethod(obj, mitem, "turnAwayModeOn");
            addMethod(obj, mitem, "turnAwayModeOff");
            break;
        case WEATHER:
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
            break;
    }
    return token;
}

void HFS::setData(QString path, QVariant value)
{
    if (HFSItem* item = _hasPath(path))
    {
//        qDebug() << "HFS::setData path: " << path << " val: " << value;
        item->setData(value);
        qDebug() << "HFS::propmap path: " << path << " val: " << value;
        propmap->insert(item->fullQMLPath(), value);
    }
}
