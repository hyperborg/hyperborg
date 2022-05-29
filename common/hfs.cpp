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

void HFSItem::setData(int column, QVariant data)
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

HFSItem* HFSItem::parentItem()
{
    return m_parentItem;
}

// ============================ HFS implementation ====================================
HFS::HFS( QObject* parent)
    : QAbstractItemModel(parent)
{
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
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    HFSItem* item = static_cast<HFSItem*>(index.internalPointer());

    return item->data(index.column());
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

void HFS::heartBeatTest()
{
    HFSItem *item= _hasPath("test.heartbeat");
    if (!item)
    {
        log(0, "test.heartbeat is not created!");
    }

    int val = rndgen.bounded(60) - 10;
    item->setData(0, val);
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


