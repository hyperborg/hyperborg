#include "hudelement.h"

HUDElement::HUDElement(QQuickItem* parent) : QQuickPaintedItem(parent), _hfs(NULL), widget(NULL)
{
    setAcceptedMouseButtons(Qt::AllButtons);
    setAcceptTouchEvents(true);
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

void HUDElement::setElementProperty(QString key, QVariant val)
{
    setProperty(key.toUtf8(), val);
}

void HUDElement::reColor(QPixmap *px, QColor c)
{
    QPainter painter(px);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.setBrush(c);
    painter.setPen(c);
    painter.drawRect(px->rect());
}

void HUDElement::paint(QPainter* painter)
{
}

