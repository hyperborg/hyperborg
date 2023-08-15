#include "hfsitem.h"

// ============================ HFSItem implementation ================================

HFSItem::HFSItem(QString id, HFSItem* parentItem, Platforms platform, const QVariant& data)
    : m_itemData(data), m_parentItem(parentItem), _id(id), _fullpath(QString()),
      _platform(platform), _flags(0)
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
    qDeleteAll(methods);
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

void HFSItem::setData(QVariant data)
{
    m_itemData = data;
    for (int i = 0; i < subscribers.count(); i++)
    {
        if (Subscriber* sub = subscribers.at(i))
        {
            QString keyidx = sub->_keyidx;
            if (sub->_keyidx.isEmpty())
            {
                QMetaObject::invokeMethod(sub->_obj, sub->_func.toLocal8Bit().data(), Qt::QueuedConnection, Q_ARG(QString, _fullpath), Q_ARG(QVariant, data));
            }
            else
            {
                QMetaObject::invokeMethod(sub->_obj, sub->_func.toLocal8Bit().data(), Qt::QueuedConnection, Q_ARG(QString, _fullpath), Q_ARG(QVariant, data), Q_ARG(QString, keyidx));
            }
        }
    }
}

void HFSItem::callMethod()
{
    for (int i = 0; i < methods.count(); i++)
    {
        if (Listener* listener = methods.at(i))
        {
            if (listener->_obj)
            {
                if (listener->_keyidx.isEmpty())
                {
                    QMetaObject::invokeMethod(listener->_obj, listener->_method_name.toLocal8Bit().data(), Qt::QueuedConnection, Q_ARG(QString, _fullpath), Q_ARG(QVariant, m_itemData ));
                }
                else
                {
                    QMetaObject::invokeMethod(listener->_obj, listener->_method_name.toLocal8Bit().data(), Qt::QueuedConnection, Q_ARG(QString, _fullpath), Q_ARG(QVariant, m_itemData), Q_ARG(QString, listener->_keyidx) );
                }
            }
        }
    }
}

HFSItem* HFSItem::parentItem()
{
    return m_parentItem;
}

void HFSItem::loadFromJson(QJsonObject obj, bool recursive)
{
    _platform = (Platforms)qBound(0, obj["platform"].toInt(), (int)PLATFORM_LAST);
    m_itemData = obj["data"].toVariant();
}

QJsonObject HFSItem::saveToJson(bool recursive)
{
    QJsonObject obj;
    obj["_fullpath"] = _id;
    obj["platform"] = _platform;
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



