#include "huditem.h"

HUDItem::HUDItem(QGraphicsItem *parent) : QGraphicsPolygonItem(parent), painterbase(NULL)
{ 
}

HUDItem::HUDItem(const QPolygonF &polygon, QGraphicsItem *parent) : QGraphicsPolygonItem(polygon, parent), painterbase(NULL)
{
}

HUDItem::HUDItem(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent) : QGraphicsPolygonItem(parent), painterbase(NULL)
{
    QPolygonF poly;
    poly << QPointF(x1, y1) << QPointF(x2, y1) << QPointF(x2, y2) << QPointF(x1, y2);
    setPolygon(poly);
}

HUDItem::~HUDItem()
{
}

void HUDItem::setRect(QRectF rect)
{
}

QRectF HUDItem::boundingRect() const 
{
    QRectF brx = QGraphicsPolygonItem::boundingRect();
    QRectF br(0, 0, 300, 300);
    return br;
}

int HUDItem::type() const
{
    return Element;
}

void HUDItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QRectF br = boundingRect();
    if (!painterbase)
    {
        QRectF rf(1, 1, br.width() - 2, br.height() - 2);
        QPen rpen(QColor(255, 0, 0));
        painter->setPen(rpen);
        painter->drawRect(rf);
    }
    else
    {
        painterbase->paint(painter, br);
    }
}

void HUDItem::setHFS(HFS *hfs)
{
    _hfs = hfs;
}
