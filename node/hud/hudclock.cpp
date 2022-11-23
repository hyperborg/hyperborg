#include "hudclock.h"

HUDClock::HUDClock(QQuickItem* parent) : HUDElement(parent)
{
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer.setSingleShot(false);
    timer.start(1000);
}

HUDClock::~HUDClock()
{}

void HUDClock::paint(QPainter* painter)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);
    int w = this->width();
    int cw = w / 2;
    int h = this->height();
    int ch = h / 2;
    int rvo = 0; // running vertical offset
    int vgap = 10; // gap between elements

    // Wired in values (should be transferred out)
    QColor bg_color(68, 68, 68);
    QColor frame_color(154, 165, 185);
    QColor gauge_color(250, 250, 250);
    QColor text_color(250, 250, 250);

    // draw frame
    QBrush brush(bg_color);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, w - 2, h - 2, 5, 5);

    // Generate date and time
    QDateTime dt = QDateTime::currentDateTime();
    QString time_str = dt.toString("hh:mm:ss");
    QString date_str = dt.toString("yyyy-MM-dd");   // Other formats for date?
    int hour = dt.time().hour();
    int min = dt.time().minute();
    int sec = dt.time().second();

    // draw digital time
    QFont f;
    f.setPointSize(28);
    f.setBold(true);
    QFontMetrics fm(f);
    int tw = fm.horizontalAdvance(time_str);
    rvo = fm.height();
    int of = qMax(0, (w - tw) / 2);
    painter->setFont(f);
    QPen bp(text_color);
    painter->setPen(bp);
    painter->drawText(of, rvo, time_str);

    // draw analog clock
    int r = (w - 20) / 2;       // main radius of the clock
    rvo += r+vgap;                 // move current vert offset to center of clock
    
    QBrush wb(gauge_color);                   // draw background
    wb.setStyle(Qt::SolidPattern);
    painter->setBrush(wb);
    QPen rp(frame_color);
    rp.setWidth(3);
    painter->setPen(rp);
    painter->drawEllipse(QPoint(cw, rvo), r, r);

    QPen blp(Qt::black);                        // draw "hour" handler
    blp.setWidth(6);
    painter->setPen(blp);
    painter->translate(cw, rvo);
    painter->rotate((hour%12)*30+min/2.0);
    painter->drawLine(0, 0, 0, -r + 55);

    painter->resetTransform();                  // draw "minute" handler
    painter->translate(cw, rvo);
    painter->rotate(min*6);
    blp.setWidth(3);
    painter->setPen(blp);
    painter->drawLine(0, 0, 0, - r+16);

    blp.setWidth(1);                       // draw "second" handler
    blp.setColor(frame_color);
    painter->setPen(blp);
    painter->resetTransform();
    painter->translate(cw, rvo);
    painter->rotate(sec * 6);
    painter->drawLine(0, 0, 0, -r + 16);

    rp.setWidth(1);                         // cosmetic circle in the main axis
    painter->setPen(rp);
    painter->drawEllipse(QPoint(0, 0), 5, 5);

    rvo += r + vgap;

    // draw date
    painter->resetTransform();
    QFont f2;
    f2.setPointSize(14);
    f2.setBold(true);
    QFontMetrics fm2(f2);
    tw = fm2.horizontalAdvance(date_str);
    rvo += fm2.height();
    of = qMax(0, (w - tw) / 2);
    painter->setFont(f2);
    painter->drawText(of, rvo, date_str);

}

void HUDClock::updateTime()
{
    update();
}
