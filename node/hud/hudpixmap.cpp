#include "hudpixmap.h"

HUDPixmap::HUDPixmap(QGraphicsItem* parent) : HUDItem(parent)
{
    _pixmap = NULL;
}

HUDPixmap::~HUDPixmap()
{
    if (_pixmap) delete(_pixmap);
}

void HUDPixmap::load(QJsonObject obj)
{
    HUDItem::load(obj);
}

QJsonObject HUDPixmap::save()
{
    QJsonObject obj = HUDItem::save();
    return obj;
}

void HUDPixmap::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    // collect general values
    int mx = size().width();
    int my = size().height();
    int cx = mx / 2;
    int cy = my / 2;

    // draw background
    QBrush brush(QColor(100, 100, 100));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, mx-2, my-2, 5, 5);

    if (_pixmap)
    {
        QPixmap px;
        painter->drawPixmap(0,0,mx, my, *_pixmap);
    }
}

void HUDPixmap::setPixmap(QPixmap *pixmap)
{
    if (_pixmap) delete(_pixmap);
    _pixmap = pixmap;
    calculateGeometry();
}

void HUDPixmap::calculateGeometry()
{
    int _w = 0;
    int _h = 0;
    if (_pixmap)
    {
        _w = _pixmap->width();
        _h = _pixmap->height();
    }
    resize(_w, _h);
}

