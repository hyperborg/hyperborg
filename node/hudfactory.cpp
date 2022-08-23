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

// ======================================================================== HUDClock ===================================================
HUDWeather::HUDWeather(QQuickItem* parent) : HUDElement(parent)
{
}

HUDWeather::~HUDWeather()
{}

void HUDWeather::paint(QPainter* painter)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);

    // general values
    int w = width();
    int h = height();
    int wh = w / 2;
    int hh = h / 2;

    // feed in some fake values
    _humidity   = "45 %";
    _pressure   = "1021.2 hPa";
    _sunrise    = "5:59:02";
    _wind       = "W 3 km/h";
    _visibility = "11 km";
    _sunset     = "21:02:34";

    // draw main frame
    QPen ypen(Qt::yellow);
    ypen.setWidth(1);
    QBrush bbrush(QColor(100, 100, 255, 128));
    bbrush.setStyle(Qt::SolidPattern);
    painter->setPen(ypen);
    painter->setBrush(bbrush);
    painter->drawRect(boundingRect());

    // draw current temperature




    // draw current weather

    // draw humidity

    // draw air-pressure

    // draw sunrise

    // draw wind direction and speed

    // draw visibility?

    // draw sunset

    // draw next 5 days forecast

        // draw day initial

        // draw forecast icon

        // draw max temperature

        // draw min temperature

        // draw percipication

}

void HUDWeather::loadConfiguration(QJsonObject& json)
{
}

void  HUDWeather::saveConfiguration(QJsonObject& json)
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
    int mx = boundingRect().width();
    int my = boundingRect().height();
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
//    painter->drawRect(0, 0, mx, my);

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

#if 0
    if (!_val.isEmpty())
    {
        QPen pen(QColor(4, 170, 254));
        painter->setPen(pen);
        QFont f = QFont();
        f.setBold(true);
        f.setPointSize(35);
        QFontMetrics fm(f);
        int gn = cx - fm.width(_val) / 2;
        painter->setFont(f);
        painter->drawText(gn, cy+24, _val);
    }
#else
//    QRadialGradient rdg;
//    rdg.setCenter(cx, cy);
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

//    QBrush gbrush(QColor(100, 100, 100));
    gbrush.setStyle(Qt::SolidPattern);
    painter->setBrush(gbrush);
    painter->drawRect(20, cy - 15, size().width() - 40, 30);

#endif
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
