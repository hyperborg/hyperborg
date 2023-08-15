#ifndef GUICOMMON_H
#define GUICOMMON_H

#include "common.h"

#include <QColor>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>

#define HUDELEMENT_IDX_START 90000

enum HUDElementType
{
    Element         = QGraphicsItem::UserType + 1,
    Magnet          = QGraphicsItem::UserType + 2,
    Screen          = QGraphicsItem::UserType + 3,
    Button          = QGraphicsItem::UserType + 4,
    Gauge           = QGraphicsItem::UserType + 5,
    Clock           = QGraphicsItem::UserType + 6,
    Weather         = QGraphicsItem::UserType + 7,
    Garbage         = QGraphicsItem::UserType + 8,
    PowerGrid       = QGraphicsItem::UserType + 9,
    TimeTable       = QGraphicsItem::UserType + 10,
    TodoList        = QGraphicsItem::UserType + 11,
    EventList       = QGraphicsItem::UserType + 12,
    ShoppingList    = QGraphicsItem::UserType + 13,
    Calendar        = QGraphicsItem::UserType + 14,
    CalendarDay     = QGraphicsItem::UserType + 15,
    CalendarEntry   = QGraphicsItem::UserType + 16,
    HFSTree         = QGraphicsItem::UserType + 17,
    Library         = QGraphicsItem::UserType + 18,
    Navigator       = QGraphicsItem::UserType + 19,
    ScreenSaver     = QGraphicsItem::UserType + 20,
    ScreenManager   = QGraphicsItem::UserType + 21,
    HET_Task        = QGraphicsItem::UserType + 22,
    HET_Port        = QGraphicsItem::UserType + 23,
    HET_Wire        = QGraphicsItem::UserType + 24,
    HET_Pixmap      = QGraphicsItem::UserType + 25,
    HET_Text        = QGraphicsItem::UserType + 26,
    HET_Repo        = QGraphicsItem::UserType + 27

};



static void reColor(QPixmap *px, QColor c)
{
    QPainter painter(px);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.setBrush(c);
    painter.setPen(c);
    painter.drawRect(px->rect());
}

#endif