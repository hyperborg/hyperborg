#include "hudbutton.h"

HUDButton::HUDButton(QQuickItem* parent) : HUDElement(parent)
{
    _val = 0;
}

HUDButton::~HUDButton()
{
}

void HUDButton::paint(QPainter* painter)
{
    // collect general values
    int mx = size().width();
    int my = size().height();
    int cx = mx / 2;
    int cy = my / 2;

    // draw background
    QBrush brush(QColor(68, 68, 68));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, mx-2, my-2, 5, 5);

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

    QBrush gbrush;
    switch (_val)
    {
    case 0:
        gbrush.setColor(color_off);
        break;
    case 1:
        gbrush.setColor(color_on);
        break;
    case 2:
        gbrush.setColor(color_pend);
        break;
    case 3:
        gbrush.setColor(color_forbidden);
        break;
    }

    gbrush.setStyle(Qt::SolidPattern);
    painter->setBrush(gbrush);
    painter->drawRect(20, cy - 15, size().width() - 40, 30);

}

void HUDButton::mousePressed(int x, int y, int butt)
{
    if (!_hfs) return;
    if (_val) _val = 0;
    else _val = 1;
    _hfs->dataChangeRequest("test.switch", _val);
}
