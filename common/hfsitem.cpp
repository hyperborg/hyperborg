#include "hfsitem.h"

// ============================ HFSItem implementation ================================

HFSItem::HFSItem(QString id, HFSItem* parentItem, const QList<QVariant>& data)
    : m_itemData(data), m_parentItem(parentItem), _id(id)
{
    if (parentItem)
    {
        parentItem->appendChild(getThis());
	_path=parentItem->fullPath();
	_fullpath=_path+"."+id;
    }
    m_itemData.resize(HFSIDX_END, QVariant());
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
    if (m_itemData.count() == 0 || column > m_itemData.count())
    {
        m_itemData.resize(column + 1);
    }
    m_itemData[column] = data;

    for (int i = 0; i < registered.count(); i++)
    {
        if (Registered* reg = registered.at(i))
        {
            switch (reg->_mode)
            {
            case SingleInterest:
                qDebug() << "NOTIFY about datachange: [SINGLE] " << registered.at(i);
                QMetaObject::invokeMethod(registered.at(i)->_obj, registered.at(i)->_func.toLocal8Bit().data(), Qt::QueuedConnection, Q_ARG(QVariant, data));
                break;
            case SystemInterest:
                qDebug() << "NOTIFY about datachange: [SYSTEM] " << registered.at(i);
                QMetaObject::invokeMethod(registered.at(i)->_obj, registered.at(i)->_func.toLocal8Bit().data(), Qt::QueuedConnection, Q_ARG(QString, _id), Q_ARG(QVariant, data), Q_ARG(int, column));
                break;
            }
        }
    }
}

QVariant HFSItem::data(int column)
{
    if (column<0 || column>HFSIDX_END)
    {
        return QVariant();
    }
    return m_itemData[column];
}

HFSItem* HFSItem::parentItem()
{
    return m_parentItem;
}
