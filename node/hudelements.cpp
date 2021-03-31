#include "hudelements.h"

void HUDButton::generateLayout()
{
    uppertext = new QGraphicsTextItem(this);
    feedback_line = new QGraphicsLineItem(this);
    lowertext = new QGraphicsTextItem(this);
}

void HUDButton::setText(QString utext, QString ltext)
{
    uppertext->setPlainText(utext);
    lowertext->setPlainText(ltext);
}
