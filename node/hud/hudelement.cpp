#include "hudelement.h"

HUDElement::HUDElement(QQuickItem* parent) : QQuickPaintedItem(parent), _hfs(NULL)
{
}

HUDElement::~HUDElement()
{
}

int HUDElement::type() const
{
    return HUDElementType::Element;
}

void HUDElement::setHFS(HFS *hfs)
{
    _hfs = hfs;
}

void HUDElement::setElementProperty(QString key, QVariant val, int col)
{
    qDebug() << " HUDElement::setElementProperty key: " << key << " val: " << val.toString();
    this->setProperty(key.toUtf8(), val);
}

void HUDElement::loadConfiguration(QJsonObject& json)
{
    json["x"] = x();
    json["y"] = y();
    json["width"] = boundingRect().width();
    json["height"] = boundingRect().height();
}

void HUDElement::saveConfiguration(QJsonObject& json)
{
    json["x"] = x();
    json["y"] = y();
    json["width"] = boundingRect().width();
    json["height"] = boundingRect().height();
    json["type"] = type();
}

void HUDElement::reColor(QPixmap *px, QColor c)
{
    QPainter painter(px);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.setBrush(c);
    painter.setPen(c);
    painter.drawRect(px->rect());
}

