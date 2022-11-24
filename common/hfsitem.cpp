#include "hfsitem.h"

// ============================ HFSItem implementation ================================

HFSItem::HFSItem(QString id, HFSItem* parentItem, int platform, const QVariant& data)
    : m_itemData(data), m_parentItem(parentItem), _id(id), _fullpath(QString()),
      _platform(platform)
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
    qDebug() << _fullpath << " is deleted";
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
    return 1;
}

QVariant HFSItem::data() const
{
    return m_itemData;
}

void HFSItem::setData(QVariant data)
{
    m_itemData = data;

    for (int i = 0; i < registered.count(); i++)
    {
        if (Registered* reg = registered.at(i))
        {
            QString keyidx = reg->_keyidx;
            if (reg->_keyidx.isEmpty())
            {
                qDebug() << "NOTIFY about datachange: [SINGLE] " << registered.at(i);
                QMetaObject::invokeMethod(registered.at(i)->_obj, registered.at(i)->_func.toLocal8Bit().data(), Qt::QueuedConnection, Q_ARG(QVariant, data));
            }
            else
            {
                qDebug() << "NOTIFY about datachange: [INDEXED] " << registered.at(i);
                QMetaObject::invokeMethod(registered.at(i)->_obj, registered.at(i)->_func.toLocal8Bit().data(), Qt::QueuedConnection, Q_ARG(QString, keyidx), Q_ARG(QVariant, data));
                break;
            }
        }
    }
}

HFSItem* HFSItem::parentItem()
{
    return m_parentItem;
}
