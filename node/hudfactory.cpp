#include "hudfactory.h"

// ======================================================================== HUDELEMENT ===================================================
HUDElement::HUDElement(QQuickItem* parent) : QQuickPaintedItem(parent)
{
}

HUDElement::~HUDElement()
{
}

int HUDElement::type() const
{
    return HUDElementType::Element;
}

void HUDElement::setElementProperty(QString key, QVariant val, int col)
{
    qDebug() << " HUDElement::setElementProperty key: " << key << " val: " << val.toString();
    this->setProperty(key.toUtf8(), val);
}

void HUDElement::loadConfiguration(QJsonObject& json)
{
    json["x"] = x();
    json["y"] = y();
    json["width"] = boundingRect().width();
    json["height"] = boundingRect().height();
}

void HUDElement::saveConfiguration(QJsonObject& json)
{
    json["x"] = x();
    json["y"] = y();
    json["width"] = boundingRect().width();
    json["height"] = boundingRect().height();
    json["type"] = type();
}

void HUDElement::reColor(QPixmap *px, QColor c)
{
    QPainter painter(px);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.setBrush(c);
    painter.setPen(c);
    painter.drawRect(px->rect());
}


// ======================================================================== HUDSCREEN ===================================================
HUDScreen::HUDScreen(QQuickItem* parent) : HUDElement(parent)
{
}

HUDScreen::~HUDScreen()
{}

void HUDScreen::paint(QPainter* painter)
{
    QPen ypen(Qt::yellow);
    ypen.setWidth(1);
    QBrush bbrush(QColor(100, 100, 255, 128));
    bbrush.setStyle(Qt::SolidPattern);
    painter->setPen(ypen);
    painter->setBrush(bbrush);
    painter->drawRect(boundingRect());
}

void HUDScreen::loadConfiguration(QJsonObject& json)
{
}

void  HUDScreen::saveConfiguration(QJsonObject& json)
{
    HUDElement::saveConfiguration(json);
    json["name"] = "SCREEN";
    QJsonArray elems;

    QList<QQuickItem*> children = childItems();
    for (int i = 0; i < children.count(); i++)
    {
        QJsonObject co;
        if (HUDElement* elem = dynamic_cast<HUDElement*>(children.at(i)))
        {
            QJsonObject obj;
            elem->saveConfiguration(obj);
            elems.append(obj);
        }
    }
    json["SCREEN"] = elems;
}

// ======================================================================== HUDClock ===================================================
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

    QPen blp(Qt::black);
    blp.setWidth(6);
    painter->setPen(blp);
    painter->translate(cw, rvo);
    painter->rotate((hour%12)*30);
    painter->drawLine(0, 0, 0, -r + 55);

    painter->resetTransform();
    painter->translate(cw, rvo);
    painter->rotate(min*6);
    blp.setWidth(3);
    painter->setPen(blp);
    painter->drawLine(0, 0, 0, - r+16);

    blp.setWidth(1);
    blp.setColor(frame_color);
    painter->setPen(blp);
    painter->resetTransform();
    painter->translate(cw, rvo);
    painter->rotate(sec * 6);
    painter->drawLine(0, 0, 0, -r + 16);

    rp.setWidth(1);
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

void HUDClock::loadConfiguration(QJsonObject& json)
{
}

void  HUDClock::saveConfiguration(QJsonObject& json)
{
}

void HUDClock::updateTime()
{
    update();
}

// ======================================================================== HUDWeather ===================================================
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

// ======================================================================== HUDBase ===================================================
HUDGarbage::HUDGarbage(QQuickItem* parent) : HUDElement(parent)
{
}

HUDGarbage::~HUDGarbage()
{}

void HUDGarbage::paint(QPainter* painter)
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

    // draw background
    QBrush brush(QColor(68, 68, 68));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, d_width - 2, d_height - 2, 5, 5);
}

void HUDGarbage::loadConfiguration(QJsonObject& json)
{
}

void  HUDGarbage::saveConfiguration(QJsonObject& json)
{
}


// ======================================================================== HUDBase ===================================================
HUDPowerGrid::HUDPowerGrid(QQuickItem* parent) : HUDElement(parent)
{
    d_width = 450.0;     // design width and height
    d_height = 450.0;
    cx = d_width / 2;
    cy = d_height / 2;
    cr = 50;
    cg = 8;
    bg = 35;

    // setup colors
    color_batt = QColor(Qt::green);
    color_pv = QColor(Qt::red);
    color_grid = QColor(Qt::blue);
    color_load = QColor(Qt::cyan);

    // set up painter paths
    QPolygon poly, poly2;
    poly << QPoint(xo[1], yo[0] + cr) << QPoint(xo[1], yo[2] - cr);
    pv_load.addPolygon(poly);
    poly.clear();

    poly << QPoint(xo[0]+cr, yo[1]) << QPoint(xo[2]-cr, yo[1]);
    batt_grid.addPolygon(poly);
    poly.clear();

    // PV->BATT
    poly << QPoint(xo[1] - cg, yo[0]+cr) << QPoint(xo[1] - cg, yo[1]  - bg);
    pv_batt.addPolygon(poly);
    QPointF bc(xo[1] - cg , yo[1]-cg );           // Bezier quadratic curve control point
    QPointF ep(xo[1] - cg - bg, yo[1] - cg);
    pv_batt.quadTo(bc, ep);
    poly2 << ep.toPoint() << QPoint(xo[0] + cr, yo[1] - cg);
    pv_batt.addPolygon(poly2);
    poly.clear(); poly2.clear();

    //PV->GRID
    poly << QPoint(xo[1] + cg, yo[0] + cr) << QPoint(xo[1] + cg, yo[1] - bg);
    pv_grid.addPolygon(poly);
    QPointF bc2(xo[1] + cg , yo[1] -cg);           // Bezier quadratic curve control point
    QPointF ep2(xo[1] + cg + bg, yo[1] - cg);
    pv_grid.quadTo(bc2, ep2);
    poly2 << ep2.toPoint() << QPoint(xo[2] - cr, yo[1] - cg);
    pv_grid.addPolygon(poly2);
    poly.clear(); poly2.clear();

    //BATT->LOAD
    poly << QPoint(xo[0] + cr, yo[1] + cg) << QPoint(xo[1] -cg - bg, yo[1] +cg);
    batt_load.addPolygon(poly);
    QPointF bc3(xo[1] - cg, yo[1] + cg);           // Bezier quadratic curve control point
    QPointF ep3(xo[1] - cg, yo[1] + cg+bg );
    batt_load.quadTo(bc3, ep3);
    poly2 << ep3.toPoint() << QPoint(xo[1] - cg, yo[2] - cr);
    batt_load.addPolygon(poly2);
    poly.clear(); poly2.clear();

    //GRID->LOAD
    poly << QPoint(xo[2] - cr, yo[1] + cg) << QPoint(xo[1] + cg + bg, yo[1] + cg);
    grid_load.addPolygon(poly);
    QPointF bc4(xo[1] + cg, yo[1] + cg);           // Bezier quadratic curve control point
    QPointF ep4(xo[1] + cg, yo[1] + cg + bg);
    grid_load.quadTo(bc4, ep4);
    poly2 << ep4.toPoint() << QPoint(xo[1] + cg, yo[2] - cr);
    grid_load.addPolygon(poly2);
    poly.clear(); poly2.clear();

    color_icon=QColor(245, 245, 245);
    px_batt.load(":/QML/home-battery.svg");
    px_grid.load(":/QML/transmission-tower.svg");
    px_load.load(":/QML/calendar-month.svg");
    px_pv.load(":/QML/solar-power.svg");

    reColor(&px_batt, color_icon);
    reColor(&px_grid, color_icon);
    reColor(&px_load, color_icon);
    reColor(&px_pv, color_icon);

    val_batt_power = 0.150f;
    val_batt_soc   = 93.2f;
    val_pv = 1.483;
    val_grid = 0.100f;
    val_load = 0.148f;
}

HUDPowerGrid::~HUDPowerGrid()
{}

void HUDPowerGrid::paint(QPainter* painter)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);

    // general values
    int w = width();
    int h = height();

    double scalex = w / d_width;
    double scaley = h / d_height;
    painter->scale(scalex, scaley);

    // draw background
    QBrush brush(QColor(68, 68, 68));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, d_width - 2, d_height - 2, 5, 5);

    // setup common 
    QPen p(color_icon);
    p.setWidth(2);
    painter->setPen(p);
    QFont f;
    f.setPixelSize(18);
    f.setBold(true);
    painter->setFont(f);
    QFontMetrics fm(f);
    QString str;
    int bo;
    int bh = fm.height() + 6;
    QString str_kwh = "kWh";
    int ko = fm.horizontalAdvance(str_kwh) / 2;

    // draw PV
    painter->setPen(color_pv);
    painter->drawEllipse(QPoint(xo[1], yo[0]), cr, cr);
    painter->drawPixmap(xo[1] - px_pv.width() / 2, yo[0]-cr + 15, px_pv);
    str = QString::number(val_pv, 'n', 3);
    bo = fm.horizontalAdvance(str) / 2;
    painter->setPen(color_icon);
    painter->drawText(xo[1]-bo, yo[0]+5, str);
    painter->drawText(xo[1]-ko, yo[0] + 5+bh, str_kwh);

    // draw Batterie
    painter->setPen(color_batt);
    painter->drawEllipse(QPoint(xo[0], yo[1]), cr, cr);
    painter->drawPixmap(xo[0] - px_pv.width() / 2, yo[1] - cr + 15, px_batt);
    str = QString::number(val_batt_power, 'n', 3);
    bo = fm.horizontalAdvance(str) / 2;
    painter->setPen(color_icon);
    painter->drawText(xo[0] - bo, yo[1] + 5, str);
    painter->drawText(xo[0] - ko, yo[1] + 5 + bh, str_kwh);

    // draw load
    painter->setPen(color_load);
    painter->drawEllipse(QPoint(xo[1], yo[2]), cr, cr);
    painter->drawPixmap(xo[1] - px_pv.width() / 2, yo[2] - cr + 15, px_load);
    str = QString::number(val_load, 'n', 3);
    bo = fm.horizontalAdvance(str) / 2;
    painter->setPen(color_icon);
    painter->drawText(xo[1] - bo, yo[2] + 5, str);
    painter->drawText(xo[1] - ko, yo[2] + 5 + bh, str_kwh);

    // draw grid
    painter->setPen(color_grid);
    painter->drawEllipse(QPoint(xo[2], yo[1]), cr, cr);
    painter->drawPixmap(xo[2] - px_pv.width() / 2, yo[1] - cr + 15, px_grid);
    str = QString::number(val_grid, 'n', 3);
    bo = fm.horizontalAdvance(str) / 2;
    painter->setPen(color_icon);
    painter->drawText(xo[2] - bo, yo[1] + 5, str);
    painter->drawText(xo[2] - ko, yo[1] + 5 + bh, str_kwh);

    if (1)  // PV->GRID
    {
        QLinearGradient gr(QPointF(xo[1], yo[0]), QPointF(xo[2], yo[1]));
        gr.setColorAt(0, color_pv);
        gr.setColorAt(1, color_grid);
        QPen pp(QBrush(gr), 2.0f);
        painter->setPen(pp);
        painter->drawPath(pv_grid);
    }

    if (1)  // PV->BATT
    {
        QLinearGradient gr(QPointF(xo[1], yo[0]), QPointF(xo[0], yo[1]));
        gr.setColorAt(0, color_pv);
        gr.setColorAt(1, color_batt);
        QPen pp(QBrush(gr), 2.0f);
        painter->setPen(pp);
        painter->drawPath(pv_batt);
    }

    if (1)  // BATT->LOAD
    {
        QLinearGradient gr(QPointF(xo[0], yo[1]), QPointF(xo[1], yo[2]));
        gr.setColorAt(0, color_batt);
        gr.setColorAt(1, color_load);
        QPen pp(QBrush(gr), 2.0f);
        painter->setPen(pp);
        painter->drawPath(batt_load);
    }

    if (1)  // GRID->LOAD
    {
        QLinearGradient gr(QPointF(xo[2], yo[1]), QPointF(xo[1], yo[2]));
        gr.setColorAt(0, color_grid);
        gr.setColorAt(1, color_load);
        QPen pp(QBrush(gr), 2.0f);
        painter->setPen(pp);
        painter->drawPath(grid_load);
    }

    if (1)  // PV->LOAD
    {
        QLinearGradient gr(QPointF(xo[1], yo[0]), QPointF(xo[1], yo[2]));
        gr.setColorAt(0, color_pv);
        gr.setColorAt(1, color_load);
        QPen pp(QBrush(gr), 2.0f);
        painter->setPen(pp);
        painter->drawPath(pv_load);
    }

    if (1)  // BATT->GRID
    {
        QLinearGradient gr(QPointF(xo[0], yo[1]), QPointF(xo[2], yo[1]));
        gr.setColorAt(0, color_batt);
        gr.setColorAt(1, color_grid);
        QPen pp(QBrush(gr), 2.0f);
        painter->setPen(pp);
        painter->drawPath(batt_grid);
    }
}

void HUDPowerGrid::loadConfiguration(QJsonObject& json)
{
}

void  HUDPowerGrid::saveConfiguration(QJsonObject& json)
{
}



// ======================================================================== HUDGAUGE ======================================================
HUDGauge::HUDGauge(int mmode, int smode, QQuickItem* parent) : HUDElement(parent), _hfs(NULL)
{
    _bidi = 0;
}

void HUDGauge::setMainMode(int mode)
{
    _mainMode = mode;
    if (1)              // left to right
    {
        _degFrom = 225;
        _degTo = -45;
    }
    else                // right to left
    {
        _degFrom = -45;
        _degTo = 225;
    }
    _gFrame = 8;
    _ticks = 10;
    _subticks = 5;

    switch (_mainMode)
    {
    case 1:         // temperature
    {
        colors << QColor(2, 2, 250);
        colors << QColor(20, 156, 255);
        colors << QColor(0, 206, 251);
        colors << QColor(17, 254, 255);
        colors << QColor(0, 223, 151);
        colors << QColor(5, 219, 23);
        colors << QColor(0, 255, 0);
        colors << QColor(255, 255, 3);
        colors << QColor(253, 202, 0);
        colors << QColor(255, 131, 0);
        colors << QColor(255, 66, 7);
        colors << QColor(255, 14, 4);
        double s = 1.0 / colors.count();
        double f = 0;
        double t = s;
        for (int i = 0; i < colors.count(); i++)
        {
            colors[i].from = f;
            colors[i].to = t;
            f += s;
            t += s;
        }
        _ticks = colors.count();
        _name = "Temperature";
        _unit = "C";
        gauge_value = "0";
        _rangeMin = -10;
        _rangeMax = 50;
        _value = 0.0;
    }
    break;
    case 2:         // humidity
    {
        colors << ColorRange(0, 0.45, QColor(17, 254, 255));
        colors << ColorRange(0.45, 0.75, QColor(0, 255, 0));
        colors << ColorRange(0.75, 1.0, QColor(255, 14, 4));
        _subticks = 2;

        _name = "Humidity";
        _unit = "%";
        gauge_value = "0";
        _rangeMin = 0;
        _rangeMax = 80;
        _value = 60.0;
    }
    break;
    case 3:         // UV index
    {
        double s = 1.0 / 14.0;
        colors << ColorRange(0 * s, 3 * s, QColor(0, 255, 0));
        colors << ColorRange(3 * s, 5 * s, QColor(249, 216, 0));
        colors << ColorRange(5 * s, 7 * s, QColor(254, 87, 0));
        colors << ColorRange(7 * s, 10 * s, QColor(246, 9, 0));
        colors << ColorRange(10 * s, 14 * s, QColor(253, 13, 200));
        _subticks = 0;
        _ticks = 14;

        _name = "UV index";
        _unit = "";
        gauge_value = "0";
        _rangeMin = 0;
        _rangeMax = 14;
        _value = 6.0;
    }
    break;
    case 4:         // pressure
    {
        double s = 1.0 / 10.0;
        colors << ColorRange(0 * s, 3 * s, QColor(8, 253, 8));
        colors << ColorRange(3 * s, 6 * s, QColor(253, 253, 8));
        colors << ColorRange(6 * s, 10 * s, QColor(253, 8, 3));

        _name = "Pressure";
        _unit = "Hgmm";
        gauge_value = "1000";
        _rangeMin = 950;
        _rangeMax = 1050;
        _value = 1011.0;
    }
    break;
    case 5:         // wind direction
    {
        _degFrom = 0;
        _degTo = 359;
        colors << ColorRange(0, 1, QColor(253, 253, 8));
        _ticks = 4;
        _subticks = 2;

        _name = "Wind direction";
        _unit = "";
        gauge_value = "0";
        _rangeMin = 0;
        _rangeMax = 360;
        _value = 77;

    }
    break;
    case 6:         // wind speed
    {
        double s = 1.0 / 48.0;
        for (int i = 0; i < 48; i++)
        {
            colors << ColorRange(i * s, (i + 1) * s, QColor(255 - i * 5, 255 - i * 5, 253));
        }
        _ticks = 8;
        _subticks = 2;

        _name = "Wind speed";
        _unit = "km/h";
        gauge_value = "0";
        _rangeMin = 0;
        _rangeMax = 80;
        _value = 30.0;
    }
    break;
    default:
        break;
    }
    _rotFrom = _degFrom * 16;
    _rotTo = _degTo * 16;
    _value = _rangeMin + (_rangeMax - _rangeMin) / 4.0;
    update();
}

HUDGauge::~HUDGauge()
{
}

void HUDGauge::setHFS(HFS* hfs)
{
    _hfs = hfs;
}

void HUDGauge::loadConfiguration(QJsonObject& json)
{
	// POC connect
}

void HUDGauge::saveConfiguration(QJsonObject& json)
{
    HUDElement::saveConfiguration(json);
    json["_degFrom"] = _degFrom;
    json["_degTo"] = _degTo;
    json["_gFrame"] = _gFrame ;
    json["_ticks"] = _ticks ;
    json["_subticks"] = _subticks;
    json["_rangeMin"] = _rangeMin;
    json["_rangeMax"] = _rangeMax;
    json["_value"] = _value;
    json["_name"] = _name;
    json["_unit"] = _unit;
    json["gauge_value"] = gauge_value;
    json["_mainMode"] = _mainMode;
    json["_bidi"] = _bidi;
}

void HUDGauge::paint(QPainter* painter)
{
    // calculate points
    painter->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    int sx = 0;
    int sy = 0;
    int mx = 300;
    int my = 300;
    painter->scale((double)width() / (double)mx, (double)height() / (double)my);
    int cx = mx / 2;    // center x
    int cy = my / 2;    // center y
    int r = cx;         // radius of the gauge
    int d = cx * 2;
    int arc_off = _gFrame + 13; // gap between the frame and the outer perimeter of the arc
    int arc_in = _gFrame + 33;  // thickness of the arc

    // calculate values
    double dtotal = _degTo - _degFrom;
    double stotal = _rotTo - _rotFrom;
    double dValue = _value;
    dValue = qBound(_rangeMin, dValue, _rangeMax);
    double valPer = 0;  // value percentage
    if (_rangeMax != _rangeMin)
    {
        valPer = (dValue - _rangeMin) / (_rangeMax - _rangeMin);
    }
    double vtotal = _rotFrom + valPer * stotal;

    // drawing gauge background
    QBrush bbrush(Qt::black);
    bbrush.setStyle(Qt::SolidPattern);
    QBrush wbrush(QColor(245, 245, 245));
    wbrush.setStyle(Qt::SolidPattern);
    QPen bpen(Qt::black);
    QPen wpen(Qt::white);

    painter->setBrush(bbrush);
    painter->drawEllipse(sx, sy, d, d);
    painter->setBrush(wbrush);
    painter->drawEllipse(sx + 1, sy + 1, d - 2, d - 2);
    painter->setBrush(bbrush);
    painter->drawEllipse(sx + _gFrame, sy + _gFrame, d - _gFrame * 2, d - _gFrame * 2);

    // draw arcs
    QPen apen;
    apen.setWidth(1);
    QBrush rbrush;
    rbrush.setStyle(Qt::SolidPattern);
    int cc = colors.count();

    if (_bidi == 0)
    {
        for (int i = 0; i < cc; i++)
        {
            ColorRange cr = colors.at(i);
            QColor ccolor = cr.color;
            apen.setColor(ccolor);
            painter->setPen(apen);
            rbrush.setColor(ccolor);
            painter->setBrush(ccolor);
            double cfrom = _rotFrom + cr.from * stotal;
            double cto = _rotFrom + cr.to * stotal;
            painter->drawPie(sx + arc_off, sy + arc_off, mx - arc_off * 2, my - arc_off * 2, cfrom, cto - cfrom);
        }
    }
    else if (_bidi == 1)
    {
        QColor ccolor = QColor(200, 200, 200); // default color
        bool found = false;
        for (int i = 0; i < colors.count() && !found; i++)
        {
            if ((colors.at(i).from < valPer) && (valPer <= colors.at(i).to))
            {
                ccolor = colors.at(i).color;
                found = true;
                apen.setColor(ccolor);
                painter->setPen(apen);
                rbrush.setColor(ccolor);
                painter->setBrush(ccolor);
                double cfrom = _rotFrom;
                double cto = _rotFrom + valPer * stotal;
                painter->drawPie(sx + arc_off, sy + arc_off, mx - arc_off * 2, my - arc_off * 2, cfrom, cto - cfrom);
            }
        }
    }

    // draw inner disc
    painter->setBrush(bbrush);
    painter->setPen(bpen);
    painter->drawEllipse(sx + arc_in, sy + arc_in, d - arc_in * 2, d - arc_in * 2);

    // draw _subticks
    bpen.setWidth(1);
    painter->setPen(bpen);
    QLineF slinef(-70, 0, -80, 0);

    if (_subticks && _bidi == 0)
    {
        int _ticksnum = qMax(1, _ticks) * _subticks;
        double substep = dtotal / _ticksnum;
        painter->save();
        painter->translate(cx, cy);
        painter->rotate(_degFrom);
        for (int i = 0; i < _ticksnum; i++)
        {
            painter->drawLine(slinef);
            painter->rotate(substep);
        }
        painter->drawLine(slinef);
        painter->restore();
    }

    // draw main _ticks
    bpen.setWidth(2);
    painter->setPen(bpen);
    QLineF linef(-60, 0, -80, 0);

    if (_ticks && _bidi == 0)
    {
        double substep = dtotal / _ticks;
        painter->save();
        painter->translate(cx, cy);
        painter->rotate(_degFrom);
        for (int i = 0; i < _ticks; i++)
        {
            painter->drawLine(linef);
            painter->rotate(substep);
        }
        painter->drawLine(slinef);
        painter->restore();
    }

    // draw measurement units
    if (_bidi==0)
    {
        painter->setPen(wpen);
        for (int i = 0; i < 13; i++)
        {
            double rot = _degFrom + i * 1.0 / 12.0 * (_degFrom - _degTo);
            painter->save();
            painter->translate(cx, cy);
            painter->rotate(rot);
            painter->translate(0, -47);
            painter->rotate(-rot);
            painter->translate(-3, 0);
            painter->drawText(QPoint(0, 0), QString::number(i));
            painter->restore();
        }
    }

    // draw gauge name
    painter->setPen(wpen);
    QFont f = QFont();
    f.setBold(true);
    QFontMetrics fm(f);
    int gn = cx - fm.horizontalAdvance(_name) / 2;
    painter->setFont(f);
    painter->drawText(gn, cy - 20, _name);

    // draw gauge unit
    gn = cx - fm.horizontalAdvance(_unit) / 2;
    painter->setFont(f);
    painter->drawText(gn, cy + 70, _unit);

    // draw gauge value text
    if (_bidi == 1)
    {
        f.setPointSize(20);
        QFontMetrics fms(f);
        gauge_value = QString::number(_value, 'f', 1);
        gn = cx - fms.horizontalAdvance(gauge_value) / 2;
        painter->setFont(f);
        painter->drawText(gn, cy + 15, gauge_value);
    }

    // draw needle
    static const QPoint needle[3] = {
            QPoint(5, 8),
            QPoint(-5, 8),
            QPoint(0, -80)
    };
    
        if (_bidi==0)
        {
            painter->save();
            QBrush nbrush(QColor(255, 150, 150, 128));
            painter->setBrush(nbrush);
            QPen npen(QColor(255, 150, 150, 100));
            painter->setPen(npen);
            painter->translate(cx, cy);
            painter->rotate(_degFrom+valPer*(_degFrom-_degTo));
            painter->drawConvexPolygon(needle, 3);
            painter->restore();
        }

        // draw needle hat
        if (_bidi==0)
        {
            painter->setBrush(wbrush);
            painter->setPen(bpen);
            int nh = cx - 10;
            painter->drawEllipse(sx + nh, sy + nh, d - nh * 2, d - nh * 2);
        }
    
}

// ======================================================================== HUDBUTTON =====================================================
HUDButton::HUDButton(QQuickItem* parent) : HUDElement(parent), _hfs(NULL)
{
}

HUDButton::~HUDButton()
{
}

void HUDButton::setHFS(HFS* hfs)
{
    _hfs = hfs;
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

// ======================================================================== HUDFACTORY =====================================================

HUDFactory::HUDFactory()
{}

HUDFactory::~HUDFactory()
{}

HUDElement* create(int type)
{
    return nullptr;
}

/*
// ======================================================================== HUDBase ===================================================
HUDBase::HUDBase(QQuickItem* parent) : HUDElement(parent)
{
}

HUDBase::~HUDBase()
{}

void HUDBase::paint(QPainter* painter)
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

    // draw background
    QBrush brush(QColor(68, 68, 68));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, d_width - 2, d_height - 2, 5, 5);
}

void HUDBase::loadConfiguration(QJsonObject& json)
{
}

void  HUDBase::saveConfiguration(QJsonObject& json)
{
}
*/
