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


void HFSItem::reset()
{
    for (auto child : m_childItems)
    {
        child->deleteLater();
    }
    m_childItems.clear();
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

QJsonObject HFSItem::saveToJson(QueryDepth depth)
{
    QJsonObject obj;

    switch(depth)
    {
        // not using breaks are intentional here
        case FullRecursive:
        case WithFullChildrenInfo:
        case OnlyNameOfChildren:
        case OnlyItem:
            obj["_id"] = _id;
            obj["_fullpath"] = _fullpath;
            obj["_fullqmlpath"] = _fullqmlpath;
            obj["data"] = QJsonValue::fromVariant(m_itemData);
            obj["_devid"] = _devid;
            obj["_flags"] = _flags;
        case OnlyNameWithChildName:
        case OnlyName:
            obj["_path"] = _path;
    }
    obj["_depth"] = depth;

    if (depth> OnlyName)
    {
        QJsonArray arr;
        QueryDepth childdepth;
        switch (depth)
        {
            case OnlyNameWithChildName:
            case OnlyNameOfChildren:
                childdepth = OnlyName;
                break;
            case WithFullChildrenInfo:
                childdepth = OnlyItem;
                break;
            case FullRecursive:
                childdepth = WithFullChildrenInfo;
                break;
        }

        for (int i = 0; i < m_childItems.count(); ++i)
        {
            HFSItem* item = m_childItems.at(i);
            QJsonObject cobj = item->saveToJson(childdepth);
            arr << cobj;
        }
        obj["children"] = arr;
    }
    return obj;
}

void HFSItem::loadFromJson(QJsonObject obj)
{
    int depth = (QueryDepth)obj["_depth"].toInt();
    switch (depth)
    {
        case FullRecursive:
        case WithFullChildrenInfo:
        case OnlyNameOfChildren:
        case OnlyItem:
            _id = obj["_id"].toString();
            _fullpath = obj["_fullpath"].toString();
            _fullqmlpath = obj["_fullqmlpath"].toString();
            m_itemData = obj["data"].toVariant();
            _devid = obj["_devid"].toInt();
            _flags = obj["_flags"].toInt();
        case OnlyNameWithChildName:
        case OnlyName:
            _path = obj["_path"].toString();
    }

    if (obj.contains("children"))
    {
        QJsonArray arr = obj["children"].toArray();
        for (auto child : arr)
        {
            if (HFSItem* item = new HFSItem(QString(), this))
            {
                item->loadFromJson(child.toObject());
            }
        }
    }
}



