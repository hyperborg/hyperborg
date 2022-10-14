#include "hudweather.h"

HUDWeather::HUDWeather(QQuickItem* parent) : HUDElement(parent)
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

HUDWeather::~HUDWeather()
{}

void HUDWeather::paint(QPainter* painter)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);

    // general values
    int w = width();
    int h = height();
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
}

void HUDWeather::loadConfiguration(QJsonObject& json)
{
}

void  HUDWeather::saveConfiguration(QJsonObject& json)
{
}

