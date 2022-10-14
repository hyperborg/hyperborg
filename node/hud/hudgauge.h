#ifndef HUDGauge_H
#define HUDGauge_H

#include "hudelement.h"

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

#endif
