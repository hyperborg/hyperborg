#include "hudwire.h"

HUDWire::HUDWire(QGraphicsItem* parent) : HUDItem(parent), _wire(NULL)
{
}

HUDWire::~HUDWire()
{
}

void HUDWire::setWire(Wire *w)
{
    QString nid = "";
    setProperty("wireID", "");
    _wire=w;
    if (_wire)
    {
        nid = w->property("id").toString();
    }
    setProperty("wireID", nid);
}

void HUDWire::load(QJsonObject obj)
{
    HUDItem::load(obj);
    setProperty("wireID", obj["wireID"].toString());
}

QJsonObject HUDWire::save()
{
    QJsonObject obj = HUDItem::save();
    obj["wireID"]=_wireID;
    return obj;
}


void HUDWire::paint(QPainter* painter)
{
    // collect general values
    int mx = boundingRect().width();
    int my = boundingRect().height();
    int cx = mx / 2;
    int cy = my / 2;

    // draw background
    QBrush brush(QColor(68, 68, 68));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, mx-2, my-2, 5, 5);

    QBrush gbrush;
    gbrush.setStyle(Qt::SolidPattern);
    painter->setBrush(gbrush);
    painter->drawRect(20, cy - 15, boundingRect().width() - 40, 30);

}

