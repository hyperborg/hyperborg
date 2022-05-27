#ifndef HUDFactory_H
#define HUDFactory_H

#include <QObject>
#include <QQuickPaintedItem>
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
#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QLineF>
#include <QVariant>
#include <QFont>
#include <QFontMetrics>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QRadialGradient> 

#include "hfs.h"

enum HUDElementType
{
    Element = QGraphicsItem::UserType + 1,
    Screen  = QGraphicsItem::UserType + 2,
    Button  = QGraphicsItem::UserType + 3,
    Gauge   = QGraphicsItem::UserType + 4
};

class HUDElement : public QQuickPaintedItem
{
    Q_OBJECT
public:
    HUDElement(QQuickItem* parent = nullptr);
    ~HUDElement();

    virtual void loadConfiguration(QJsonObject& json);
    virtual void saveConfiguration(QJsonObject& json);
    virtual int type() const;
    virtual void paint(QPainter* painter) {}

signals:
    void itemChanged(QString path, QString value);              // Signal emitted when element had user or other interaction

public slots:
	//NI virtual void entityChanged(QString path, QString value);    // Slot to accept new values from HFS

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
    QML_NAMED_ELEMENT(Gauge)
public:
    HUDGauge(int mmode=1, int smode=0, QQuickItem* parent = nullptr);
    ~HUDGauge();

    void paint(QPainter* painter);

    virtual void loadConfiguration(QJsonObject& json);
    virtual void saveConfiguration(QJsonObject& json);
    int type() const override { return HUDElementType::Gauge;  }

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
    QML_ELEMENT
public:
    HUDButton(QQuickItem* parent = nullptr);
    ~HUDButton();

    int type() const override { return HUDElementType::Button; }
    void paint(QPainter* painter);

private:
    QString _desc;
    QString _val;

};

class HUDScreen : public HUDElement
{
Q_OBJECT
QML_ELEMENT
public:
    HUDScreen(QQuickItem* parent = nullptr);
    ~HUDScreen();
    int type() const override { return HUDElementType::Screen; }

    void paint(QPainter* painter);

    virtual void loadConfiguration(QJsonObject& json);
    virtual void saveConfiguration(QJsonObject& json);
};

class HUDFactory : public QObject
{
    Q_OBJECT
public:
    HUDFactory();
    ~HUDFactory();

    HUDElement* create(int type);
};

#endif

