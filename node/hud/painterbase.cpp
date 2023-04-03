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


void HUDCalendarPainter::paint(QPainter* painter, QRectF boundingrect)
{
}

void HUDClockPainter::paint(QPainter* painter, QRectF boundingrect)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);
    int w = boundingrect.width();
    int cw = w / 2;
    int h = boundingrect.height();
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
    rvo += r + vgap;                 // move current vert offset to center of clock

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
    painter->save();
    painter->translate(cw, rvo);
    painter->rotate((hour % 12) * 30 + min / 2.0);
    painter->drawLine(0, 0, 0, -r + 55);
    painter->restore();

    painter->save();                  // draw "minute" handler
    painter->translate(cw, rvo);
    painter->rotate(min * 6);
    blp.setWidth(3);
    painter->setPen(blp);
    painter->drawLine(0, 0, 0, -r + 16);
    painter->restore();

    blp.setWidth(1);                       // draw "second" handler
    blp.setColor(frame_color);
    painter->setPen(blp);
    painter->save();
    painter->translate(cw, rvo);
    painter->rotate(sec * 6);
    painter->drawLine(0, 0, 0, -r + 16);
    painter->restore();

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

void HUDTimeTablePainter::paint(QPainter* painter, QRectF boundingrect)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);

    // general values
    int w = boundingrect.width();
    int h = boundingrect.height();
    double d_width = 600.0;     // design width and height
    double d_height = 300.0;

    double scalex = w / d_width;
    double scaley = h / d_height;
    painter->scale(scalex, scaley);

    int wh = w / 2;
    int hh = h / 2;

    // draw background
    QBrush brush(QColor(68, 68, 68));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, d_width - 2, d_height - 2, 5, 5);

    painter->setPen(QColor(245, 245, 245));

    QFont f;
    f.setPixelSize(16);
    f.setBold(true);
    painter->setFont(f);
    QFontMetrics fm(f);
    int th = fm.height();
    painter->drawText(8, th + 6, _stationName);
    int tiw = fm.horizontalAdvance("XX:XX");
    int sw = fm.horizontalAdvance("X");
    QList<int> rs;
    rs << 5;
    rs << rs.last() + tiw + 10;
    rs << rs.last() + tiw + 10;
    rs << rs.last() + sw*8 + 10;
    rs << rs.last() + sw * 30 + 10;

    // draw headers
    int yo = 2 * th + 16;
    painter->drawText(rs.at(0), yo, "Time");
    painter->drawText(rs.at(1), yo, "ACT");
    painter->drawText(rs.at(2), yo, "Num");
    painter->drawText(rs.at(3), yo, "Destination");
    painter->drawText(rs.at(4), yo, "Peron");

    painter->drawLine(5, yo + 7, w - 5, yo + 7);
    yo += 25;
    for (int i = 0; i < timetable_lst.count() && i < 10; ++i)
    {
        QStringList lst = timetable_lst.at(i).split(";");
        if (lst.count() == 7)
        {
            if (lst.at(1).isEmpty())
            {
                painter->setPen(QColor(245, 245, 245));
            }
            else
            {
                painter->setPen(QColor(Qt::red));
                if (!lst.at(6).isEmpty()) lst[5] = lst[6];
            }

            painter->drawText(rs.at(0), yo, lst.at(0));
            painter->drawText(rs.at(1), yo, lst.at(1));
            painter->drawText(rs.at(2), yo, lst.at(2));
            painter->drawText(rs.at(3), yo, lst.at(3));
            painter->drawText(rs.at(4), yo, lst.at(5));
            yo += th + 2;
        }
    }
}


void HUDWeatherPainter::init()
{
    _px_weather.load(":/QML/weather-cloudy.svg");
    _px_humidity.load(":/QML/water-percent.svg");
    _px_pressure.load(":/QML/weather-cloudy.svg");
    _px_sunrise.load(":/QML/weather-sunset-up.svg");
    _px_wind.load(":/QML/windsock.svg");
    _px_visibility.load(":/QML/weather-cloudy.svg");
    _px_sunset.load(":/QML/weather-sunset-down.svg");

    QColor icon_color(112, 232, 255);
    reColor(&_px_weather, icon_color);
    reColor(&_px_humidity, icon_color);
    reColor(&_px_pressure, icon_color);
    reColor(&_px_sunrise, icon_color);
    reColor(&_px_wind, icon_color);
    reColor(&_px_visibility, icon_color);
    reColor(&_px_sunset, icon_color);
}

void HUDWeatherPainter::paint(QPainter* painter, QRectF boundingbox)
{
/*
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);

    // general values
    int w = boundingbox.width();
    int h = boundingbox.height();
    double d_width = 450.0;     // design width and height
    double d_height = 450.0;

    double scalex = w / d_width;
    double scaley = h / d_height;
    painter->scale(scalex, scaley);

    int wh = w / 2;
    int hh = h / 2;

    // feed in some fake values

    _temperature = "19.5 C";
    _humidity   = "45 %";
    _pressure   = "1021.2 hPa";
    _sunrise    = "5:59:02";
    _wind       = "W 3 km/h";
    _visibility = "11 km";
    _sunset     = "21:02:34";

    // draw main frame
    // draw background
    QBrush brush(QColor(68, 68, 68));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, d_width - 2, d_height - 2, 5, 5);

    // draw current weather
    painter->drawPixmap(50, 50, _px_weather);

    // draw current temperature
    QFont f;
    f.setPixelSize(48);
    f.setBold(true);
    painter->setFont(f);
    painter->setPen(QColor(245, 245, 245));
    painter->drawText(280, 65, _temperature);

    // set font for the next 6 elements and set common coordinates
    f.setPixelSize(16);
    painter->setFont(f);
    QFontMetrics fm(f);

    int xs[2] = { 50, 380 };
    int ys[3] = { 130, 160, 190 };
    int xg = 30;                        // x gap
    int yo = _px_humidity.height()-6;     // y align (not nice offset, should aling with font height!)
    int xo=0;
    // draw humidity
    painter->drawPixmap(xs[0], ys[0], _px_humidity);
    painter->drawText(xs[0] + xg, ys[0]+yo , _humidity);

    // draw air-pressure
    painter->drawPixmap(xs[0], ys[1], _px_pressure);
    painter->drawText(xs[0] + xg, ys[1] + yo, _pressure);

    // draw sunrise
    painter->drawPixmap(xs[0], ys[2], _px_sunrise);
    painter->drawText(xs[0] + xg, ys[2] + yo, _sunrise);

    // draw wind direction and speed
    painter->drawPixmap(xs[1], ys[0], _px_wind);
    xo = fm.horizontalAdvance(_wind);
    painter->drawText(xs[1] - xo - xg, ys[0] + yo, _wind);

    // draw visibility?
    painter->drawPixmap(xs[1], ys[1], _px_visibility);
    xo = fm.horizontalAdvance(_visibility);
    painter->drawText(xs[1] - xo - xg, ys[1] + yo, _visibility);

    // draw sunset
    painter->drawPixmap(xs[1], ys[2], _px_sunset);
    xo = fm.horizontalAdvance(_sunset);
    painter->drawText(xs[1] - xo - xg, ys[2] + yo, _sunset);

    // draw next 5 days forecast
    xg = 90;
    int cols = 5;
    int ry[5] = { 280, 310, 340, 370, 400 };

    QStringList ins;
    ins << "Mo" << "Tu" << "We" << "Th" << "Fr.";

    for (int i = 0; i < cols; i++)
    {
        int cl = i * xg + xg / 2; // center vertical line
        int xa = 0;                     // x align

        QString _initial = ins.at(i);
        QString _max_temp = "31.4";
        QString _min_temp = "17.5";
        QString _perc = "0.1 mm";
        
        // draw day initial
        xa = fm.horizontalAdvance(_initial) / 2;
        painter->drawText(cl - xa, ry[0], _initial);

        // draw forecast icon

        // draw max temperature
        xa = fm.horizontalAdvance(_max_temp) / 2;
        painter->drawText(cl - xa, ry[2], _max_temp);

        // draw min temperature
        xa = fm.horizontalAdvance(_min_temp) / 2;
        painter->drawText(cl - xa, ry[3], _min_temp);

        // draw percipication
        xa = fm.horizontalAdvance(_perc) / 2;
        painter->drawText(cl - xa, ry[4], _perc);

        // draw separator
        if (i != cols-1)
        {
            painter->drawLine(xg * (i + 1), ry[0]-30, xg * (i + 1), ry[4]+30);
        }
    }
*/
}


