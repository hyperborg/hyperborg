#include "hudtext.h"

HUDText::HUDText(QGraphicsItem* parent) : HUDItem(parent)
{
    _text = "HUDText";
    _font = font();
    if (parent) setZValue(parent->zValue() + 2);
    _voffset = 0;
}

HUDText::~HUDText()
{
}

void HUDText::setFont(QFont f)
{
    _font = f;
}

void HUDText::setText(QString text)
{
    _text = text;
    calculateGeometry();
    update();
}

void HUDText::load(QJsonObject obj)
{
    HUDItem::load(obj);
}

QJsonObject HUDText::save()
{
    QJsonObject obj = HUDItem::save();
    return obj;
}

void HUDText::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    // collect general values
    int mx = size().width();
    int my = size().height();

    // draw background
    QBrush brush(QColor(0, 100, 100));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, mx-2, my-2, 5, 5);

    painter->setFont(_font);
    QPen wpen(QColor(255,255,255));
    painter->setPen(wpen);
    painter->drawText(10, _voffset, _text);
}

void HUDText::calculateGeometry()
{
    QFontMetrics fm(_font);
    qreal _w = fm.horizontalAdvance(_text);
    qreal _h = fm.height();
    _voffset = fm.ascent();
    _w += 20;              // adding some gap
    resize(_w, _h);
}

