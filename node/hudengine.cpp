
#include "hudengine.h"

// ======================================================================== HUDELEMENT ===================================================

HUDElement::HUDElement(QGraphicsItem* parent, Qt::WindowFlags wFlags) : QGraphicsWidget(parent, wFlags)
{
    setFlag(QGraphicsItem::ItemIsMovable);
}

HUDElement::~HUDElement()
{
}

// ======================================================================== HUDGAUGE ======================================================
HUDGauge::HUDGauge(int mmode, int smode, QGraphicsItem* parent, Qt::WindowFlags wFlags) : HUDElement(parent, wFlags)
{
    main_mode = mmode;
    style_mode = smode;
    if (1)              // left to right
    {
        deg_from = 225;
        deg_to = -45;
    }
    else                // right to left
    {
        deg_from = -45;
        deg_to = 225;
    }
    g_frame = 8;
    ticks = 10;
    subticks = 5;

    switch (main_mode)
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
        ticks = colors.count();
        gauge_name = "Temperature";
        gauge_unit = "C°";
        gauge_value = "0";
        rangeMin = -10;
        rangeMax = 50;
        rangeValue = 0.0;
    }
    break;
    case 2:         // humidity
    {
        colors << ColorRange(0, 0.45, QColor(17, 254, 255));
        colors << ColorRange(0.45, 0.75, QColor(0, 255, 0));
        colors << ColorRange(0.75, 1.0, QColor(255, 14, 4));
        subticks = 2;

        gauge_name = "Humidity";
        gauge_unit = "%";
        gauge_value = "0";
        rangeMin = 0;
        rangeMax = 80;
        rangeValue = 60.0;
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
        subticks = 0;
        ticks = 14;

        gauge_name = "UV index";
        gauge_unit = "";
        gauge_value = "0";
        rangeMin = 0;
        rangeMax = 14;
        rangeValue = 6.0;
    }
    break;
    case 4:         // pressure
    {
        double s = 1.0 / 10.0;
        colors << ColorRange(0 * s, 3 * s, QColor(8, 253, 8));
        colors << ColorRange(3 * s, 6 * s, QColor(253, 253, 8));
        colors << ColorRange(6 * s, 10 * s, QColor(253, 8, 3));

        gauge_name = "Pressure";
        gauge_unit = "Hgmm";
        gauge_value = "1000";
        rangeMin = 950;
        rangeMax = 1050;
        rangeValue = 1011.0;
    }
    break;
    case 5:         // wind direction
    {
        deg_from = 0;
        deg_to = 359;
        colors << ColorRange(0, 1, QColor(253, 253, 8));
        ticks = 4;
        subticks = 2;

        gauge_name = "Wind direction";
        gauge_unit = "";
        gauge_value = "0";
        rangeMin = 0;
        rangeMax = 360;
        rangeValue = 77;

    }
    break;
    case 6:         // wind speed
    {
        double s = 1.0 / 48.0;
        for (int i = 0; i < 48; i++)
        {
            colors << ColorRange(i * s, (i + 1) * s, QColor(255 - i * 5, 255 - i * 5, 253));
        }
        ticks = 8;
        subticks = 2;

        gauge_name = "Wind speed";
        gauge_unit = "km/h";
        gauge_value = "0";
        rangeMin = 0;
        rangeMax = 80;
        rangeValue = 30.0;
    }
    break;
    default:
        break;
    }
    rot_from = deg_from * 16;
    rot_to = deg_to * 16;
    rangeValue = rangeMin + (rangeMax - rangeMin) / 4.0;

    //    setScale(3);

}

HUDGauge::~HUDGauge()
{
}

void HUDGauge::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
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
    int arc_off = g_frame + 13; // gap between the frame and the outer perimeter of the arc
    int arc_in = g_frame + 33;  // thickness of the arc

    // calculate values
    double dtotal = deg_to - deg_from;
    double stotal = rot_to - rot_from;
    double dValue = rangeValue;
    dValue = qBound(rangeMin, dValue, rangeMax);
    double valPer = 0;  // value percentage
    if (rangeMax != rangeMin)
    {
        valPer = (dValue - rangeMin) / (rangeMax - rangeMin);
    }
    double vtotal = rot_from + valPer * stotal;

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
    painter->drawEllipse(sx + g_frame, sy + g_frame, d - g_frame * 2, d - g_frame * 2);

    // draw arcs
    QPen apen;
    apen.setWidth(1);
    QBrush rbrush;
    rbrush.setStyle(Qt::SolidPattern);
    int cc = colors.count();

    if (style_mode == 0)
    {
        for (int i = 0; i < cc; i++)
        {
            ColorRange cr = colors.at(i);
            QColor ccolor = cr.color;
            apen.setColor(ccolor);
            painter->setPen(apen);
            rbrush.setColor(ccolor);
            painter->setBrush(ccolor);
            double cfrom = rot_from + cr.from * stotal;
            double cto = rot_from + cr.to * stotal;
            painter->drawPie(sx + arc_off, sy + arc_off, mx - arc_off * 2, my - arc_off * 2, cfrom, cto - cfrom);
        }
    }
    else if (style_mode == 1)
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
                double cfrom = rot_from;
                double cto = rot_from + valPer * stotal;
                painter->drawPie(sx + arc_off, sy + arc_off, mx - arc_off * 2, my - arc_off * 2, cfrom, cto - cfrom);
            }
        }
    }

    // draw inner disc
    painter->setBrush(bbrush);
    painter->setPen(bpen);
    painter->drawEllipse(sx + arc_in, sy + arc_in, d - arc_in * 2, d - arc_in * 2);

    // draw subticks
    bpen.setWidth(1);
    painter->setPen(bpen);
    QLineF slinef(-70, 0, -80, 0);

    if (subticks && style_mode == 0)
    {
        int ticksnum = qMax(1, ticks) * subticks;
        double substep = dtotal / ticksnum;
        painter->save();
        painter->translate(cx, cy);
        painter->rotate(deg_from);
        for (int i = 0; i < ticksnum; i++)
        {
            painter->drawLine(slinef);
            painter->rotate(substep);
        }
        painter->drawLine(slinef);
        painter->restore();
    }

    // draw main ticks
    bpen.setWidth(2);
    painter->setPen(bpen);
    QLineF linef(-60, 0, -80, 0);

    if (ticks && style_mode == 0)
    {
        double substep = dtotal / ticks;
        painter->save();
        painter->translate(cx, cy);
        painter->rotate(deg_from);
        for (int i = 0; i < ticks; i++)
        {
            painter->drawLine(linef);
            painter->rotate(substep);
        }
        painter->drawLine(slinef);
        painter->restore();
    }

    // draw measurement units
    if (style_mode==0)
    {
        painter->setPen(wpen);
        for (int i = 0; i < 13; i++)
        {
            double rot = deg_from + i * 1.0 / 12.0 * (deg_from - deg_to);
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
    int gn = cx - fm.width(gauge_name) / 2;
    painter->setFont(f);
    painter->drawText(gn, cy - 20, gauge_name);

    // draw gauge unit
    gn = cx - fm.width(gauge_unit) / 2;
    painter->setFont(f);
    painter->drawText(gn, cy + 70, gauge_unit);

    // draw gauge value text
    if (style_mode == 1)
    {
        f.setPointSize(20);
        QFontMetrics fms(f);
        gauge_value = QString::number(rangeValue, 'f', 1);
        gn = cx - fms.width(gauge_value) / 2;
        painter->setFont(f);
        painter->drawText(gn, cy + 15, gauge_value);
    }

    // draw needle
    static const QPoint needle[3] = {
            QPoint(5, 8),
            QPoint(-5, 8),
            QPoint(0, -80)
    };
    
        if (style_mode==0)
        {
            painter->save();
            QBrush nbrush(QColor(255, 150, 150, 128));
            painter->setBrush(nbrush);
            QPen npen(QColor(255, 150, 150, 100));
            painter->setPen(npen);
            painter->translate(cx, cy);
            painter->rotate(deg_from+valPer*(deg_from-deg_to));
            painter->drawConvexPolygon(needle, 3);
            painter->restore();
        }

        // draw needle hat
        if (style_mode==0)
        {
            painter->setBrush(wbrush);
            painter->setPen(bpen);
            int nh = cx - 10;
            painter->drawEllipse(sx + nh, sy + nh, d - nh * 2, d - nh * 2);
        }
    
}

QPainterPath HUDGauge::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

// ======================================================================== HUDBUTTON =====================================================
HUDButton::HUDButton(QGraphicsItem* parent, Qt::WindowFlags wFlags) : HUDElement(parent, wFlags)
{}

HUDButton::~HUDButton()
{
}

// ======================================================================== HUDENGINE =====================================================


HUDEngine::HUDEngine(QObject* parent) : QGraphicsScene(parent)
{
    setSceneRect(0, 0, 1000, 1000);

}

HUDEngine::~HUDEngine()
{
}

void HUDEngine::setupDemo()
{
    QBrush bgbrush(QColor(58, 66, 138));
    bgbrush.setStyle(Qt::SolidPattern);
    setBackgroundBrush(bgbrush);

#if 0
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    QGraphicsRectItem* rectangle = addRect(100, 0, 80, 100, outlinePen, blueBrush);

    // addEllipse(x,y,w,h,pen,brush)
    addEllipse(0, -100, 300, 60, outlinePen, greenBrush);

    QGraphicsTextItem* text = addText("bogotobogo.com", QFont("Arial", 20));
    // movable text
    text->setFlag(QGraphicsItem::ItemIsMovable);
#endif

    HUDGauge* gauge;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            int main, smode;
            smode = y % 2;
            if (y < 2) main = x + 1;
            else main = x + 3;
            if (y + x == 0)
            {
                gauge = new HUDGauge(main, smode);
                this->addItem(gauge);
                gauge->resize(200 + 1, 200);
                gauge->setPos(x * 200 + 1, y * 200 + 1);
                gauge->show();
            }
        }
    }

}













