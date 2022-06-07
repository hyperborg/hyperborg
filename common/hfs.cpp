#include "hfs.h"

// ============================ HFSItem implementation ================================

HFSItem::HFSItem(QString id, HFSItem* parentItem, const QList<QVariant>& data)
    : m_itemData(data), m_parentItem(parentItem), _id(id)
{
    if (parentItem)
        parentItem->appendChild(getThis());
}

HFSItem::~HFSItem()
{
    qDeleteAll(m_childItems);
}

void HFSItem::appendChild(HFSItem* item)
{
    m_childItems.append(item);
}

HFSItem* HFSItem::child(int row)
{
    if (row < 0 || row >= m_childItems.size())
        return nullptr;
    return m_childItems.at(row);
}

int HFSItem::childCount() const
{
    return m_childItems.count();
}

int HFSItem::row() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<HFSItem*>(this));

    return 0;
}

int HFSItem::columnCount() const
{
    return m_itemData.count();
}

QVariant HFSItem::data(int column) const
{
    if (column < 0 || column >= m_itemData.size())
        return QVariant();
    return m_itemData.at(column);
}

void HFSItem::setData(QVariant data, int column)
{
    if (m_itemData.count()==0 || column > m_itemData.count())
    {
        m_itemData.resize(column+1);
    }
    m_itemData[column] = data;

    for (int i = 0; i < registered.count(); i++)
    {
        QMetaObject::invokeMethod(registered.at(i), "setElementProperty", Qt::QueuedConnection, Q_ARG(QString, "value"), Q_ARG(QVariant, data));
    }
}

QVariant HFSItem::data(int column)
{
    if (column<0 || column>=m_itemData.count())
    {
        return QVariant();
    }
    return m_itemData[column];
}

HFSItem* HFSItem::parentItem()
{
    return m_parentItem;
}

// ============================ HFS implementation ====================================
HFS::HFS( QObject* parent)
    : QAbstractItemModel(parent)
{

    pinis << "/etc/hyperborg/hynode.imi";         // Linux: use config from /etc
    pinis << "hynode.imi";                        // Use file next to hynode
    pinis << "/home/web_user";                    // WASM: use file from persistant cache (IDBFS)

    rootItem = new HFSItem("root");
    _hasPath("test.heartbeat");
    QObject::connect(&testtimer, SIGNAL(timeout()), this, SLOT(heartBeatTest()));
    testtimer.setSingleShot(false);
    testtimer.start(1000);
}

HFS::~HFS()
{
    delete rootItem;
}

void HFS::setDefaultValues()
{
    setData("config.role",      NR_UNDECIDED);
    setData("config.matrixid",  "1");
    setData("config.port",      "33333");
    setData("config.ip",        "127.0.0.1");
    setData("config.db_host",   "127.0.0.1");
    setData("config.db_type",   "");
    setData("config.db_name",   "");
    setData("config.db_user",   "");
    setData("config.db_pass",   "");
    setData("config.db_port",   "");
    setData("config.forcegui",   0);
}

void HFS::loadInitFiles()
{
    setDefaultValues();

    bool ok = false;
    for (int i = 0; i < pinis.count() && !ok; i++)
    {
        QString filename = pinis.at(i);
        QFile f(filename);
        if (f.open(QIODevice::ReadOnly))
        {
            ok = true;
            setData("config.used_file", filename);
            while (f.canReadLine())
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

                        setData(key, val);
                    }
                }
            }
            f.close();
        }
    }
}

// Make sure we are not removing user added comments!
void HFS::saveInitFiles()
{
    log(0, "HFS::saveInitFiles() is not yet implemented");
    return; 

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

    return item->data(index.column());
}

QVariant HFS::data(QString path, int column)
{
    //QMutexLocker locker(&mutex);
    QVariant retvar;
    if (HFSItem* hitem = _hasPath(path, false))
    {
        retvar = hitem->data(column);
    }
    return retvar;
}

void HFS::dataChangeRequest(QString path, QVariant val, int row)
{
    //QMutexLocker locker(&mutex);
    qDebug() << "setDataRequest is called";
    emit signal_dataChangeRequest(path, val, row);
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

void HFS::interested(QObject *obj, QString path, int mode)
{
    // QMutexLocker locker(&mutex); //! Would cause deadlock since _hasPath is using the same mutex
    if (!obj)
    {
        log(0, "NULL object cannot be registered as ::interested");
        return;
    }
    HFSItem* item = _hasPath(path);
    if (!item) 
    {
        log(0, "Cannot create path in ::interested");
        return;
    }

    item->registered.append(obj);
    
    int key = obj2int(obj);
    if (!interested_cache.contains(key))
    {
        QStringList val;
        val << path;
        interested_cache.insert(key, val);
    }
    else
    {
        QStringList val = interested_cache.value(key);
        val.append(path);
        interested_cache.insert(key, val);
    }
}

void HFS::uninterested(QObject *obj, QString path)
{
    // QMutexLocker locker(&mutex); //! Would cause deadlock since _hasPath is using the same mutex
    HFSItem* item = _hasPath(path,  false);
    if (!item)
    {
        log(0, "Unregistered/non-existing path cannot be uninterested");
        return;
    }
    int key = obj2int(obj);
    if (!interested_cache.contains(key))
    {
        log(0, "Cannot be uninterested if was not interested before");
    }
    else
    {
        QStringList val = interested_cache.value(key);
        val.removeAll(path);
        interested_cache.insert(key, val);
    }
    item->registered.removeAll(obj);
}

void HFS::objectDeleted(QObject* obj)
{
    log(0, "::objectDeleted is not YET implemented");
    int key = obj2int(obj);
    if (key == 0) return;

    if (interested_cache.contains(key))
    {
        QStringList lst = interested_cache.value(key);
        for (int i = 0; i < lst.count(); i++)
        {
            uninterested(obj, lst.at(i));
        }
        interested_cache.remove(key);
    }
}

HFSItem* HFS::_hasPath(QString path, bool create)
{
    // QMutexLocker locker(&mutex);
    if (path.isEmpty()) return NULL;
    QStringList plst = path.split(".");
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
    }
    return current;
}

HFSItem* HFS::_createPath(QString path)
{
//    QMutexLocker locker(&mutex);
    if (path.isEmpty()) return NULL;
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
            curr = child;
        }
    }
    if (curr == rootItem) curr = nullptr;
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

void HFS::log(int severity, QString logline)
{
    emit signal_log(severity, logline, "HFS");
}

int HFS::obj2int(QObject* obj)
{
    auto ret = reinterpret_cast<std::uintptr_t>(obj);
    return ret;
}

void HFS::setData(QString path, QVariant value, int col)
{
    HFSItem* item = _hasPath(path);
    if (!item)
    {
        log(0, path + " cannot be created");
        return;
    }

    qDebug() << "::setData path:" << path << " value: " << value;
    item->setData(value, col);
}

void HFS::heartBeatTest()
{
    HFSItem *item= _hasPath("test.heartbeat");
    if (!item)
    {
        log(0, "test.heartbeat is not created!");
    }

    int val = rndgen.bounded(60) - 10;
    item->setData(val, 0);
}

/* NON USED CODE - COULD BE REUSED LATER ON*/
/*

QString HFS::getToken(QObject* object)
{
    QString _token;
    if (!object) return _token;
    int key = (int)(void *)object;
    if (tokens.contains(key))
    {
        _token = tokens[key];
    }
    else
    {
        do
        {
            _token = getRandomString(16);
            QHashIterator<int, QString> it(tokens);
            while (it.hasNext())    // make sure we do not have duplicated tokens
            {
                it.next();
                if (it.value() == _token)
                {
                    _token = "";
                }
            }
        } while (_token.isEmpty());
    }
    return _token;
}

void HFS::releaseToken(QObject *object)
{
    if (!object) return;
    tokens.remove((int)(void *)object);
}

*/


