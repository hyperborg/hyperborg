#include "hfsitem.h"

// ============================ HFSItem implementation ================================

HFSItem::HFSItem(QString id, HFSItem* parentItem, const QVariant& data)
    : m_itemData(data), m_parentItem(parentItem), _id(id), _fullpath(QString()), 
    _object(nullptr), _flags(0)
{
    if (parentItem)
    {
        parentItem->appendChild(getThis());
        _path=parentItem->fullPath();
        if (_path.isEmpty()) _fullpath = _id;
        else _fullpath=_path+"."+id;
    }
    _fullqmlpath = _fullpath;
    _fullqmlpath = _fullqmlpath.replace(".", "_");
    m_itemData = data;
}

HFSItem::~HFSItem()
{
    qDeleteAll(m_childItems);
    qDeleteAll(subscribers);
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

QString HFSItem::devId() const
{
    return _devid;
}

void HFSItem::setObject(QObject* object)
{
    _object = object;
}

void HFSItem::setDevId(QString devid)
{
    _devid = devid;
}

void HFSItem::setData(QVariant data)
{
    m_itemData = data;
}

HFSItem* HFSItem::parentItem()
{
    return m_parentItem;
}

void HFSItem::loadFromJson(QJsonObject obj, bool recursive)
{
    m_itemData = obj["data"].toVariant();
}

QJsonObject HFSItem::saveToJson(bool recursive)
{
    QJsonObject obj;
    obj["_fullpath"] = _id;
    obj["data"] = QJsonValue::fromVariant(m_itemData);
    if (recursive)
    {
        for (int i=0;i<m_childItems.count();++i)
        {
            HFSItem *item=m_childItems.at(i);
            QJsonObject cobj = item->saveToJson(recursive);
            obj["child_"+QString::number(i)]=cobj;
        }
    }
    return obj;
}



