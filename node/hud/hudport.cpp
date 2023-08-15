#include "hudport.h"

HUDPort::HUDPort(QGraphicsItem* parent) : HUDItem(parent)
{
    setGeometry(0,0,20,20);
    if (parent)
        setZValue(parent->zValue() + 2);
}

HUDPort::~HUDPort()
{
}

void HUDPort::load(QJsonObject obj)
{
    HUDItem::load(obj);
}

QJsonObject HUDPort::save()
{
    QJsonObject obj = HUDItem::save();
    return obj;
}


void HUDPort::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    // collect general values
    int mx = size().width();
    int my = size().height();
    int cx = mx / 2;
    int cy = my / 2;

    // draw background
    QBrush brush(QColor(255, 0, 0));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, mx-2, my-2, 5, 5);
}

