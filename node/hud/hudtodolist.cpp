#include "hudtodolist.h"

HUDTodoList::HUDTodoList(QQuickItem* parent) : HUDElement(parent)
{
}

HUDTodoList::~HUDTodoList()
{}

void HUDTodoList::paint(QPainter* painter)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);

    // general values
    int w = width();
    int h = height();
    double d_width = 450.0;     // design width and height
    double d_height = 450.0;

    double scalex = w / d_width;
    double scaley = h / d_height;
    painter->scale(scalex, scaley);

    int wh = w / 2;
    int hh = h / 2;

    // draw background
    QBrush brush(QColor(68, 68, 68));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, d_width - 2, d_height - 2, 5, 5);
}

void HUDTodoList::loadConfiguration(QJsonObject& json)
{
}

void  HUDTodoList::saveConfiguration(QJsonObject& json)
{
}
