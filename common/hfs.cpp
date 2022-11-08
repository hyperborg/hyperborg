#include "hfs.h"

// ============================ HFS implementation ====================================
HFS::HFS( QObject* parent)
    : QAbstractItemModel(parent)
{
    rootItem = new HFSItem("root");
    setDefaultValues();
    _hasPath("test.heartbeat");
    QObject::connect(&testtimer, SIGNAL(timeout()), this, SLOT(heartBeatTest()));
    testtimer.setSingleShot(false);
//    testtimer.start(1000);
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

    HFSItem* item = static_cast<HFSItem*>(index.internalPointer());
    if (index.column() == 0)
    {
        return item->data(HFSIDX_Path);
    }
    return item->data(index.column());
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
    qDebug() << "dataChangeRequest - " << path << " val: " << val.toInt();
    emit signal_dataChangeRequest(path, val);
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
        return rootItem->data(section);

    return QVariant();
}

void HFS::subscribe(QObject *obj, QString path, QString fncname, int mode)
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

    Registered* reg = new Registered(obj, mode, fncname);

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

void HFS::provides(QString path)
{
    HFSItem* item = _hasPath(path, true);
    if (!item) return;
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
        DataPack* pack = new DataPack();
        pack->setSource("HFS");
//        pack->setCommand("createPath");
        pack->attributes.insert("path", path);
        emit outPack(pack);
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

void HFS::setData(QString path, QVariant value)
{
    if (HFSItem* item = _hasPath(path))
    {
	qDebug() << "HFS::setData path: " << path << " val: " << value ;
	item->setData(value);
    }
}

void HFS::heartBeatTest()
{
    if (HFSItem *item= _hasPath("test.heartbeat"))
    {
	int val = rndgen.bounded(60) - 10;
	item->setData(val, 0);
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

#if 1
    qDebug() << logstr;
#endif
}

void HFS::inPack(DataPack* pack)
{
}
