#include "hudpowergrid.h"

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


