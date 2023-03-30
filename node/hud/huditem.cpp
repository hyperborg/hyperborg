#include "hfsitem.h"

HUDItem::HUDItem(QGraphicsItem *parent=0)
{
}

HUDItem::HUDItem(const QPolygonF &polygon, QGraphicsItem *parent=0)
{
}

HUDItem::HUDItem(qreal, x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent=0)
{
}

virtual HUDItem::~HUDItem()
{
}

int HUDItem::type() const
{
    return Element;
}

void HUDItem::paint(QPainter *painter)
{}

void HUDItem::setHFS(HFS *hfs)
{
    _hfs = hfs;
}

#endif