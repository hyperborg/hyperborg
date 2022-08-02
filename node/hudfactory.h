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

protected:
    virtual void mousePressEvent(QMouseEvent* e) 
    {
        qDebug() << "virtual mpe";
    }

public slots:
    void setElementProperty(QString key, QVariant value, int col);

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
        qDebug() << "SETVALUE: " << val;
        _value = val;
        update();
    }

private:
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
    Q_PROPERTY(int value MEMBER _val WRITE setValue)
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

class HUDFactory : public QObject
{
    Q_OBJECT
public:
    HUDFactory();
    ~HUDFactory();

    HUDElement* create(int type);
};

#endif

