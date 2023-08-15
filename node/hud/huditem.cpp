#include "huditem.h"
#include "hudfactory.h"

HUDItem::HUDItem(QGraphicsItem *parent, Qt::WindowFlags wFlags) : QGraphicsWidget(parent), painterbase(NULL), hudfactory(NULL)
{
}

HUDItem::~HUDItem()
{
}

int HUDItem::type() const
{
    return Element;
}

void HUDItem::setHUDFactory(HUDFactory *hf)
{
    hudfactory = hf;
}

HUDFactory *HUDItem::getHUDFactory()
{
    return hudfactory;
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

QJsonObject HUDItem::save()
{
    QJsonObject obj;
    obj["id"]       = property("id").toString();
    obj["type"]     = type();
    obj["visible"]  = isVisible();
    obj["x"]        = pos().x();
    obj["y"]        = pos().y();
    obj["width"]    = size().width();
    obj["height"]   = size().height();
    return obj;
}

void HUDItem::load(QJsonObject obj)
{
    setProperty("id", obj["id"].toString());
    setVisible(obj["visible"].toBool(true));
    qreal _x = obj["x"].toDouble();
    qreal _y = obj["y"].toDouble();
    qreal _w = obj["width"].toDouble();
    qreal _h = obj["height"].toDouble();

    setGeometry(_x, _y, _w, _h);
}