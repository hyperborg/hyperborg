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
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QRadialGradient> 

enum HUDElementType
{
    Element = QGraphicsItem::UserType + 1,
    Screen  = QGraphicsItem::UserType + 2,
    Button  = QGraphicsItem::UserType + 3,
    Gauge   = QGraphicsItem::UserType + 4
};

class HUDElement : public QGraphicsWidget
{
    Q_OBJECT
public:
    HUDElement(QGraphicsItem* parent = nullptr, Qt::WindowFlags wFlags = Qt::WindowFlags());
    ~HUDElement();

    virtual void loadConfiguration(QJsonObject& json);
    virtual void saveConfiguration(QJsonObject& json);
    virtual int type() const;

public slots:
	virtual void entityChanged();

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
public:
    HUDButton(QGraphicsItem* parent = nullptr, Qt::WindowFlags wFlags = Qt::WindowFlags());
    ~HUDButton();

    int type() const override { return HUDElementType::Button; }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
    QPainterPath shape() const;
//    QRectF boundingRect() const;

private:
    QString _desc;
    QString _val;

};

class HUDScreen : public HUDElement
{
Q_OBJECT
public:
    HUDScreen(QGraphicsItem* parent = nullptr, Qt::WindowFlags wFlags = Qt::WindowFlags());
    ~HUDScreen();
    int type() const override { return HUDElementType::Screen; }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
    QPainterPath shape() const;

    virtual void loadConfiguration(QJsonObject& json);
    virtual void saveConfiguration(QJsonObject& json);
};

class HUDFactory : public QObject
{
    Q_OBJECT
public:
//    HUDFactory(HUDScene* scene);
    HUDFactory();
    ~HUDFactory();

    HUDElement* create(int type);



};

#endif

