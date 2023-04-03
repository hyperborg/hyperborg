/* The concept here is the following. HyperBorg would like to use both Widget and QML for 
* its visual interface, but there is one major difference. By default QGraphicsItem does 
* not inherit from QObject, while QQuickPainterItem does (mainly for the property system that is
* the backbone of QML usage. On source code level it makes the paint function not-really-reusable.
*  
* In order to keep the necesseary amount of code rewrite when switching from widgets to QML, 
* the paint feature is based on its own base class called PainterBase. Both carriers 
* (HUDItem for widget, HUDElement for QML) would be (re)designed to handle this for their
* paint operations. Althoug this does not cease the necessity to modify all classes when
* switching, but it would make that a lot easier. 
*/

#ifndef PAINTERBASE_H
#define PAINTERBASE_H

#include <QObject>
#include <QPainter>
#include <QString>
#include <QDateTime>
#include <QTime>
#include <QDateTime>

#include "common.h"
#include "guicommon.h"

class PainterBase : public QObject
{
    Q_OBJECT
public:
    PainterBase(QObject* parent = nullptr) : QObject(parent) {}
    virtual ~PainterBase() {}

    virtual void update() {}


    virtual void paint(QPainter* painter, QRectF boundingrect) = 0;
};


class HUDButtonPainter : public PainterBase
{
    Q_OBJECT
public:
    HUDButtonPainter(QObject* parent = nullptr) : PainterBase(parent) 
    {
        _text = "TEST";
    }
    ~HUDButtonPainter() {}

    void paint(QPainter* painter, QRectF boundingrect) override;
private:
    QString _text;
};

class HUDCalendarPainter : public PainterBase
{
    Q_OBJECT
public:
    HUDCalendarPainter(QObject* parent = nullptr) : PainterBase(parent) {}
    ~HUDCalendarPainter() {}

    void paint(QPainter* painter, QRectF boundingrect) override;
};

class HUDClockPainter : public PainterBase
{
    Q_OBJECT
public:
    HUDClockPainter(QObject* parent = nullptr) : PainterBase(parent) {}
    ~HUDClockPainter() {}

    void paint(QPainter* painter, QRectF boundingrect) override;
};

class HUDTimeTablePainter : public PainterBase
{
    Q_OBJECT
public:
    HUDTimeTablePainter(QObject* parent = nullptr) : PainterBase(parent) {}
    ~HUDTimeTablePainter() {}

    void paint(QPainter* painter, QRectF boundingrect) override;
private:
    QStringList timetable_lst;
    QString _stationName;
};

class HUDWeatherPainter : public PainterBase
{
Q_OBJECT
    Q_PROPERTY(double temperature MEMBER _temperature WRITE setTemperature)
    Q_PROPERTY(QString temperatureUnit MEMBER _temperatureUnit WRITE setTemperatureUnit)
    Q_PROPERTY(double temperatureOutdoor MEMBER _temperatureOutdoor WRITE setTemperatureOutdoor)
    Q_PROPERTY(QString temperatureOutdoorUnit MEMBER _temperatureOutdoorUnit WRITE setTemperatureOutdoorUnit)
    Q_PROPERTY(double humidity MEMBER _humidity WRITE setHumidity)
    Q_PROPERTY(double humidityOutdoor MEMBER _humidityOutdoor WRITE setHumidityOutdoor)
    Q_PROPERTY(double pressure MEMBER _pressure WRITE setPressure)
    Q_PROPERTY(QString pressureUnit MEMBER _pressureUnit WRITE setPressureUnit)
    Q_PROPERTY(QTime sunrise MEMBER _sunrise WRITE setSunrise)
    Q_PROPERTY(QTime sunset  MEMBER _sunset  WRITE setSunset)
    Q_PROPERTY(double wind MEMBER _wind WRITE setWind)
    Q_PROPERTY(QString windUnit MEMBER _windUnit WRITE setWindUnit)
    Q_PROPERTY(double dewPt MEMBER _dewPt WRITE setDewPt)
    Q_PROPERTY(QString dewPtUnit MEMBER _dewPtUnit WRITE setDewPtUnit)
    Q_PROPERTY(double solarRadiation MEMBER _solarRadiation WRITE setSolarRadiation)
    Q_PROPERTY(int UVLevel MEMBER _UVLevel WRITE setUVLevel)
    Q_PROPERTY(double windChill MEMBER _windChill WRITE setWindChill)
    
public:
    HUDWeatherPainter(QObject* parent = nullptr) : PainterBase(parent) {}
    ~HUDWeatherPainter() {}

    void init();
    void paint(QPainter* painter, QRectF boundingrect) override;

    void setTemperature(double val)             { _temperatureOutdoor = val;    update();     }
    void setTemperatureUnit(QString s)          { _temperatureOutdoorUnit=s;    update();     }
    void setTemperatureOutdoor(double val)      { _temperature = val;           update();     }
    void setTemperatureOutdoorUnit(QString s)   { _temperatureUnit=s;           update();     }
    void setHumidity(double val)                { _humidity = val;              update();     }
    void setHumidityOutdoor(double val)         { _humidity = val;              update();     }
    void setPressure(double val)                { _pressure = val;              update();     }
    void setPressureUnit(QString s)             { _pressureUnit = s;            update();     }
    void setSunrise(QTime v)                    { _sunrise = v;                 update();     }
    void setSunset(QTime v)                     { _sunset = v;                  update();     }
    void setWind(double d)                      { _wind = d;                    update();     }
    void setWindUnit(QString s)                 { _windUnit = s;                update();     }
    void setDewPt(double d)                     { _dewPt = d;                   update();     }
    void setDewPtUnit(QString s)                { _dewPtUnit = s;               update();     }
    void setSolarRadiation(double d)            { _solarRadiation = d;          update();     }
    void setUVLevel(int level)                  { _UVLevel = level;             update();     }
    void setWindChill(double d)                 { _windChill = d;               update();     }


private:
    double  _temperature;
    QString _temperatureUnit;
    double  _temperatureOutdoor;
    QString _temperatureOutdoorUnit;
    double  _dewPt;
    QString _dewPtUnit;
    double  _humidity;
    double  _humidityOutdoor;
    double  _pressure;
    QString _pressureUnit;
    QTime   _sunrise;
    QTime   _sunset;
    double  _wind;
    QString _windUnit;
    double  _solarRadiation;
    double _UVLevel;
    double _windChill;

    QPixmap _px_weather;
    QPixmap _px_visibility;
    QPixmap _px_humidity;
    QPixmap _px_pressure;
    QPixmap _px_sunrise;
    QPixmap _px_wind;
    QPixmap _px_sunset;


};


#endif