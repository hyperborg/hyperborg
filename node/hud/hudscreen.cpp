#include "hudscreen.h"

HUDScreen::HUDScreen(QQuickItem* parent) : HUDElement(parent)
{
}

HUDScreen::~HUDScreen()
{}

void HUDScreen::paint(QPainter* painter)
{
    QPen ypen(Qt::yellow);
    ypen.setWidth(1);
    QBrush bbrush(QColor(100, 100, 255, 128));
    bbrush.setStyle(Qt::SolidPattern);
    painter->setPen(ypen);
    painter->setBrush(bbrush);
    painter->drawRect(boundingRect());
}

