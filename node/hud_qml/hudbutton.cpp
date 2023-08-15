#include "hudbutton.h"

HUDButton::HUDButton(QQuickItem* parent) : HUDElement(parent)
{
    _switchValue = 0;
    color_off = QColor(0, 255, 0);
    color_pend = QColor(255, 255, 0);
    color_on = QColor(255, 0, 0);
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

    if (!_subtext.isEmpty())
    {
    }

    QBrush gbrush;
    switch (_switchValue)
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
    if (_switchValue) _switchValue = 0;
    else _switchValue = 1;
    _hfs->dataChangeRequest(this, "", _button, _switchValue);
}
