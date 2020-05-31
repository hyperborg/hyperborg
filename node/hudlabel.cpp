#include "hudlabel.h"

HUDLabel::HUDLabel(QWidget* parent) : QWidget(parent)
{
    ui.setupUi(this);
}

HUDLabel::~HUDLabel()
{}

void HUDLabel::paintEvent(QPaintEvent* event)
{
    int w = width();
    int h = height();
    // paint decoration lines, dependint
    QPainter pmp(this);
    QPen linepen(QColor(119, 141, 152));
    linepen.setWidth(3);
    pmp.setPen(linepen);
    pmp.setCompositionMode(QPainter::CompositionMode_SourceOver);

    int y1u = 5;       // y coordinate, 1st line,upper
    int y1l = h-5;
    int sx = 30;
    int ex = w - sx;
    int xcp2 = w - ui.label->width() - 30; // cutpoints, where the lines should be broken (x coordinate)
    int xcp1 = xcp2 - h - 10;

    // draw datum line (upper)
    pmp.drawLine(sx, y1u, xcp1, y1u);
    pmp.drawLine(xcp1, y1u, xcp2, y1l);
    pmp.drawLine(xcp2, y1l, ex, y1l);
    pmp.end();
}

void HUDLabel::setText(QString str)
{
    ui.label->setText(str);
    update();
}