#ifndef GUICOMMON_H
#define GUICOMMON_H

#include "common.h"

#include <QColor>
#include <QPixmap>
#include <QPainter>

static void reColor(QPixmap *px, QColor c)
{
    QPainter painter(px);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.setBrush(c);
    painter.setPen(c);
    painter.drawRect(px->rect());
}

#endif