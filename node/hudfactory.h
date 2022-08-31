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
#include <QMouseEvent>
#include <QFontMetrics>
#include <QDateTime>
#include <QPixmap>
#include <QPainterPath>
#include <QPolygon>
#include <QPolygonF>
#include <QPoint>
#include <QPointF>
#include <QLinearGradient>

#include "hfs.h"

enum HUDElementType
{
    Element         = QGraphicsItem::UserType + 1,
    Screen          = QGraphicsItem::UserType + 2,
    Button          = QGraphicsItem::UserType + 3,
    Gauge           = QGraphicsItem::UserType + 4,
    Clock           = QGraphicsItem::UserType + 5,
    Weather         = QGraphicsItem::UserType + 6,
    Garbage         = QGraphicsItem::UserType + 7,
    PowerGrid       = QGraphicsItem::UserType + 8,
    TimeTable       = QGraphicsItem::UserType + 9,
    TodoList        = QGraphicsItem::UserType + 10,
    EventList       = QGraphicsItem::UserType + 11,
    ShoppingList    = QGraphicsItem::UserType + 12
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

protected:
    virtual void mousePressEvent(QMouseEvent* e) 
    {
        qDebug() << "virtual mpe";
    }

public slots:
    void setElementProperty(QString key, QVariant value, int col);

signals:
    void itemChanged(QString path, QString value);              // Signal emitted when element had user or other interaction

protected:
    void reColor(QPixmap *px, QColor c);
	
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
        QML_NAMED_ELEMENT(HUDGauge)

        Q_PROPERTY(int mainMode MEMBER _mainMode WRITE setMainMode)
        Q_PROPERTY(int bidi     MEMBER _bidi     WRITE setBidi)
        Q_PROPERTY(int degFrom  MEMBER _degFrom  WRITE setDegFrom)
        Q_PROPERTY(int degTo    MEMBER _degTo    WRITE setDegTo)
        Q_PROPERTY(int rotFrom  MEMBER _rotFrom  WRITE setRotFrom)
        Q_PROPERTY(int rotTo    MEMBER _rotTo    /*WRITE setRotTo*/)
        Q_PROPERTY(int gFrame   MEMBER _gFrame   /*WRITE setGFrame*/)
        Q_PROPERTY(int ticks    MEMBER _ticks    /*WRITE setTicks*/)
        Q_PROPERTY(int subticks MEMBER _subticks /*WRITE setSubTicks*/)
        Q_PROPERTY(int rangeMin MEMBER _rangeMin /*WRITE setRangeMin*/)
        Q_PROPERTY(int rangeMax MEMBER _rangeMax /*WRITE setRangeMax*/)
        Q_PROPERTY(double  value    MEMBER _value    WRITE setValue)
        Q_PROPERTY(QString name MEMBER _name     /*WRITE setName*/) 
        Q_PROPERTY(QString unit MEMBER _unit     /*WRITE setUnitStr*/)

public:
    HUDGauge(int mmode=1, int smode=0, QQuickItem* parent = nullptr);
    ~HUDGauge();
    void paint(QPainter* painter) override;

    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;
    int type() const override { return HUDElementType::Gauge;  }

    void setMainMode(int mode);
    void setBidi(int bidi)      { _bidi = bidi;     }
    void setDegFrom(int deg)    { _degFrom = deg;   }
    void setDegTo(int deg)      { _degTo = deg;     }
    void setRotFrom(int deg)    { _rotFrom = deg;   }
    void setValue(double val )  
    {
        _value = val;
        update();
    }

public slots:
    void setHFS(HFS* hfs);

private:
    HFS* _hfs;
    int _mainMode;                  // There are some predefined modes, like: 1 - temp, 2 humidity, 3-UV index, 4-pressure, 5-wind direction, 6-windspeed
    int _bidi;                      // bidi -> BiDirectional ... when true -> clockwise, otherwise anti-clockwise
    int _degFrom;
    int _degTo;
    int _rotFrom;                   // angle arc starting from, should be multiplied by 16
    int _rotTo;                     // angle arcs ends at, should be multiplied by 16
    int _gFrame;                    // gauge frame thickness
    int _ticks;
    int _subticks;
    QList<ColorRange> colors;
    QList<QVariant> tickvalues;
    double _rangeMin;               // minimum value at needle 0%
    double _rangeMax;               // maximum vakue at needle 100%
    double _value;                  // actual displayed value of the gauge
    QString _name;
    QString _unit;
    QString gauge_value;
};

class HUDButton : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDButton)
    Q_PROPERTY(QString text MEMBER _text)
    Q_PROPERTY(QColor colorOff MEMBER color_off)
    Q_PROPERTY(QColor colorPending MEMBER color_pend)
    Q_PROPERTY(QColor colorForbidden MEMBER color_forbidden)
    Q_PROPERTY(QColor colorOn MEMBER color_on)
    Q_PROPERTY(QVariant value MEMBER _val WRITE setValue)

public:
    HUDButton(QQuickItem* parent = nullptr);
    ~HUDButton();

    int type() const override { return HUDElementType::Button; }
    void paint(QPainter* painter) override;


    void setValue(double val)
    {
        qDebug() << "SETVALUE: " << val;
        _val = val;
        update();
    }

public slots:
    void setHFS(HFS* hfs);
    Q_INVOKABLE void mousePressed(int x, int y, int butt);
    void setValue(QVariant var)
    {
        setValue(var.toDouble());
    }

private:
    HFS* _hfs;
    QString _text;
    int _val;

    QColor color_off;           // these should be in some list
    QColor color_pend;
    QColor color_forbidden;
    QColor color_on;
};

class HUDScreen : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDScreen)
public:
    HUDScreen(QQuickItem* parent = nullptr);
    ~HUDScreen();
    int type() const override { return HUDElementType::Screen; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;
};

class HUDClock : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDClock)

public:
    HUDClock(QQuickItem* parent = nullptr);
    ~HUDClock();

    int type() const override { return HUDElementType::Clock; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;

protected slots:
    void updateTime();

private:
    QTimer timer;
};

class HUDWeather : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDWeather)

public:
    HUDWeather(QQuickItem* parent = nullptr);
    ~HUDWeather();

    int type() const override { return HUDElementType::Weather; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;

private:
    QString _temperature;
    QString _humidity;
    QString _pressure;
    QString _sunrise;
    QString _wind;
    QString _visibility;
    QString _sunset;

    QPixmap _px_weather;
    QPixmap _px_humidity;
    QPixmap _px_pressure;
    QPixmap _px_sunrise;
    QPixmap _px_wind;
    QPixmap _px_visibility;
    QPixmap _px_sunset;
};

class HUDGarbage : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDGarbage)

public:
    HUDGarbage(QQuickItem* parent = nullptr);
    ~HUDGarbage();

    int type() const override { return HUDElementType::Garbage; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;
};

class HUDTimeTable : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDTimeTable)

public:
    HUDTimeTable(QQuickItem* parent = nullptr);
    ~HUDTimeTable();

    int type() const override { return HUDElementType::TimeTable; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;

protected:
    void parseStationInfo(QString str);
    QStringList timetable_lst;  // Very simple presentation of timetable lines: CSV with ; as delimiters (scheduled_time;delayed_time;name;origin;destination;peron
};

class HUDTodoList : public HUDElement
{
    Q_OBJECT
        QML_NAMED_ELEMENT(HUDTodoList)

public:
    HUDTodoList(QQuickItem* parent = nullptr);
    ~HUDTodoList();

    int type() const override { return HUDElementType::TodoList; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;
};

class HUDEventList : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDEventList)

public:
    HUDEventList(QQuickItem* parent = nullptr);
    ~HUDEventList();

    int type() const override { return HUDElementType::TodoList; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;
};

class HUDShoppingList : public HUDElement
{
    Q_OBJECT
        QML_NAMED_ELEMENT(HUDShoppingList)

public:
    HUDShoppingList(QQuickItem* parent = nullptr);
    ~HUDShoppingList();

    int type() const override { return HUDElementType::ShoppingList; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;
};

class HUDPowerGrid : public HUDElement
{
    Q_OBJECT
        QML_NAMED_ELEMENT(HUDPowerGrid)

public:
    HUDPowerGrid(QQuickItem* parent = nullptr);
    ~HUDPowerGrid();

    int type() const override { return HUDElementType::PowerGrid; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;

private:
    QPainterPath pv_batt;
    QPainterPath pv_grid;
    QPainterPath pv_load;
    QPainterPath batt_load;
    QPainterPath grid_load;
    QPainterPath batt_grid;

    QColor color_pv;
    QColor color_batt;
    QColor color_load;
    QColor color_grid;
    QColor color_icon;

    double d_width, d_height;
    int cx, cy;                     // center x and y lines
    int cr;                         // circle radius
    int cg;                         // gap between lines
    int bg;                         // Bezier gap
    int xo[3] = { 80, 225, 370 };
    int yo[3] = { 80, 225, 370 };

    QPixmap px_batt;
    QPixmap px_grid;
    QPixmap px_load;
    QPixmap px_pv;

    double val_batt_power;
    double val_batt_soc;
    double val_pv;
    double val_grid;
    double val_load;
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

/*
class HUDBase : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDBase)

public:
    HUDBase(QQuickItem* parent = nullptr);
    ~HUDBase();

    int type() const override { return HUDElementType::Base; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;
};

*/