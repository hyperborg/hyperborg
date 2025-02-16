#include "hfsitem.h"

// ============================ HFSItem implementation ================================

HFSItem::HFSItem(QString id, HFSItem* parentItem, const QVariant& data)
    : QObject(parentItem), 
     m_itemData(data), m_parentItem(parentItem), _id(id), _fullpath(QString()), 
    _object(nullptr), _flags(0), _devid(0)
{
    if (parentItem)
    {
        parentItem->appendChild(getThis());
        _path=parentItem->fullPath();
        if (_path.isEmpty()) _fullpath = _id;
        else _fullpath=_path+ PATH_SEPARATOR +id;
    }
    _fullqmlpath = _fullpath;
    _fullqmlpath = _fullqmlpath.replace(PATH_SEPARATOR, "_");
    m_itemData = data;
}

HFSItem::~HFSItem()
{
    qDebug() << "HFSITEM del : " << _id;
    if (m_parentItem)
    {
        m_parentItem->removeChild(this);
    }
    qDeleteAll(subscribers);
}

void HFSItem::appendChild(HFSItem* item)
{
    if (!item) return;
    m_childItems.append(item);
    child_ids.append(item->id());
}

void HFSItem::removeChild(HFSItem* child, bool del)
{
    if (!child) return;
    if (QObject::children().contains(child))
    {
        QString child_id = child->id();
        m_childItems.removeAll(child);
        child_ids.removeAll(child_id);
        if (del)
            child->deleteLater();
    }
}

void HFSItem::removeChild(QString child_id, bool del)
{
    if (child_id.isEmpty()) return;
    removeChild(child(child_id), del);
}


HFSItem* HFSItem::child(int row)
{
    if (row < 0 || row >= m_childItems.size())
        return nullptr;
    return m_childItems.at(row);
}

HFSItem* HFSItem::child(QString id)
{
    HFSItem* child = nullptr;
    for (int i = 0; i < m_childItems.count() && !child; ++i)
        if (m_childItems.at(i)->id() == id)
            child = m_childItems.at(i);
    return child;
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
    return 2;
}

QVariant HFSItem::data() const
{
    return m_itemData;
}

QObject* HFSItem::object() const
{
    return _object;
}

int HFSItem::devId() const
{
    return _devid;
}

void HFSItem::setObject(QObject* object)
{
    _object = object;
}

void HFSItem::setDevId(int devid)
{
    _devid = devid;
}

void HFSItem::setData(QVariant data)
{
    qDebug() << _fullpath << " " << data.toString();
    m_itemData = data;
}

HFSItem* HFSItem::parentItem()
{
    return m_parentItem;
}

QJsonObject HFSItem::saveToJson(bool recursive)
{
    QJsonObject obj;
    obj["_id"] = _id;
    obj["_path"] = _path;
    obj["_fullpath"] = _fullpath;
    obj["_fullqmlpath"] = _fullqmlpath;
    obj["data"] = QJsonValue::fromVariant(m_itemData);
    obj["_devid"] = _devid;
    obj["_flags"] = _flags;
    int cc = 0; 
    if (recursive)
    {
        for (int i = 0; i < m_childItems.count(); ++i)
        {
            if (1)                                                  // Should transfer only globally reacheable elements
            {
                HFSItem* item = m_childItems.at(i);
                QJsonObject cobj = item->saveToJson(recursive);
                obj["child_" + QString::number(i)] = cobj;
                cc++;                                               // not all children would be transferred, thus need to count
            }
        }
    }
    obj["child_count"] = cc;
    return obj;
}

void HFSItem::loadFromJson(QJsonObject obj, bool recursive)
{
    _id = obj["_id"].toString();
    _path = obj["_path"].toString();
    _fullpath = obj["_fullpath"].toString();
    _fullqmlpath = obj["_fullqmlpath"].toString();

    m_itemData = obj["data"].toVariant();
    _devid = obj["_devid"].toInt();
    _flags = obj["_flags"].toInt();

    if (recursive)
    {
        int cc = obj["child_count"].toInt();
        for (int i = 0; i < cc; i++)
        {
            QJsonObject nobj = obj["child_" + QString::number(i)].toObject();
            if (!obj.isEmpty())
            {
                if (HFSItem* item = new HFSItem(QString(), this))
                {
                    item->loadFromJson(nobj);
                }
            }
        }
    }
}



