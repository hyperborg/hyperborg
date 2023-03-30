#include "painterbase.h"

void HUDButtonPainter::paint(QPainter* painter, QRectF boundingrect)
{
    // collect general values
    int mx = boundingrect.width();
    int my = boundingrect.height();
    int cx = mx / 2;
    int cy = my / 2;

    // draw background
    QBrush brush(QColor(68, 68, 68));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, mx - 2, my - 2, 5, 5);

    if (!_text.isEmpty())
    {
        QPen pen(QColor(247, 247, 247));
        painter->setPen(pen);
        QFont f = QFont();
        //        f.setBold(true);
        f.setPointSize(16);
        QFontMetrics fm(f);
        int gn = cx - fm.horizontalAdvance(_text) / 2;
        painter->setFont(f);
        painter->drawText(gn, 30, _text);
    }

    QBrush gbrush(QColor(0, 200, 20));
    gbrush.setStyle(Qt::SolidPattern);
    painter->setBrush(gbrush);
    painter->drawRect(20, cy - 15, mx - 40, 30);
}
