#pragma once

#ifndef HUDENGINE_H
#define HUDENGINE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QColor>
#include <QPen>
#include <QBrush>
#include <QGraphicsEffect>
#include <QGraphicsItem>
#include <QString>
#include <QStringList>
#include <QHash>
#include <QHashIterator>
#include <QMap>
#include <QPalette>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QLineF>
#include <QVariant>
#include <QFont>
#include <QFontMetrics>

class HUDElement : public QGraphicsWidget
{
    Q_OBJECT
public:
    HUDElement(QGraphicsItem* parent = nullptr, Qt::WindowFlags wFlags = Qt::WindowFlags());
    ~HUDElement();
};

class ColorRange
{
public:
    ColorRange(double _from, double _to, QColor c)
    {
        from = _from;
        to = _to;
        color = c;

    }
    ColorRange(QColor c)
    {
        from = 0;
        to = 100;
        color = c;
    }
    ColorRange(double _to, QColor c)
    {
        from = 0;
        to = _to;
        color = c;
    }

    ~ColorRange() {}

    double from;
    double to;
    QColor color;

};

class HUDGauge : public HUDElement
{
    Q_OBJECT
public:
    HUDGauge(int mmode, int smode, QGraphicsItem* parent = nullptr, Qt::WindowFlags wFlags = Qt::WindowFlags());
    ~HUDGauge();

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
    QPainterPath shape() const;

private:
    int deg_from;
    int deg_to;
    int rot_from;   // angle arc starting from, should be multiplied by 16
    int rot_to;     // angle arcs ends at, should be multiplied by 16
    int g_frame;    // gauge frame thickness
    int ticks;
    int subticks;
    QList<ColorRange> colors;
    QList<QVariant> tickvalues;
    double rangeMin;    // minimum value at needle 0%
    double rangeMax;    // maximum vakue at needle 100%
    double rangeValue;  // actual displayed value of the gauge
    QString gauge_name;
    QString gauge_unit;
    QString gauge_value;
    int main_mode;
    int style_mode;
};

class HUDButton : public HUDElement
{
    Q_OBJECT
public:
    HUDButton(QGraphicsItem* parent = nullptr, Qt::WindowFlags wFlags = Qt::WindowFlags());
    ~HUDButton();
};

class HUDEngine : public QGraphicsScene
{
    Q_OBJECT
public:
    HUDEngine(QObject* parent = nullptr);
    ~HUDEngine();

    void setupDemo();

};

#endif

