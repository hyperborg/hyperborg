#include "hudelements.h"

HUDButton::HUDButton(QGraphicsItem* parent) : QGraphicsRectItem(parent)
{
    _size = QSize(130, 60);
    uppertext = new QGraphicsTextItem(this);
    feedback_line = new QGraphicsLineItem(this);
    lowertext = new QGraphicsTextItem(this);
    uppertext->hide();
    feedback_line->hide();
    lowertext->hide();

    QFont f = QFont();
    f.setBold(true);
    uppertext->setDefaultTextColor(Qt::white);
    uppertext->setFont(f);
    lowertext->setDefaultTextColor(Qt::white);
    lowertext->setFont(f);
}

void HUDButton::generateLayout()
{
    if (!uppertext->toPlainText().isEmpty())
    {
        int tw = uppertext->boundingRect().width();
        uppertext->setPos((_size.width() - tw) / 2, 0);
        uppertext->show();
    }
    else
    {
        uppertext->hide();
    }

    if (!lowertext->toPlainText().isEmpty())
    {
        int tw = lowertext->boundingRect().width();
        lowertext->setPos((_size.width() - tw) / 2, 30);
        lowertext->show();
    }
    else
    {
        lowertext->hide();
    }


}

void HUDButton::setText(QString utext, QString ltext)
{
    uppertext->setPlainText(utext);
    lowertext->setPlainText(ltext);
    generateLayout();
}

void HUDButton::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    QBrush rbrush(Qt::red);
    rbrush.setStyle(Qt::SolidPattern);
    painter->setBrush(rbrush);
    painter->drawRect(boundingRect());
}

