#ifndef NumberENTITY_H
#define NumberENTITY_H

#include <entity.h>

class NumberEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(NumberEntity)

    Q_PROPERTY(QString deviceClass MEMBER _deviceClass)             // Type of number.
    Q_PROPERTY(QString mode MEMBER _mode)                           // Defines how the number should be displayed in the UI.It's recommended to use the default auto. Can be box or slider to force a display mode.
    Q_PROPERTY(float nativeMaxValue MEMBER _nativeMaxValue)         // The maximum accepted value in the number's native_unit_of_measurement (inclusive)
    Q_PROPERTY(float nativeMinValue MEMBER _nativeMinValue)         // The minimum accepted value in the number's native_unit_of_measurement (inclusive)
    Q_PROPERTY(float nativeStep MEMBER _nativeStep)                 // Defines the resolution of the values, i.e.the smallest increment or decrement in the number's
    Q_PROPERTY(float nativeValue MEMBER _nativeValue)               // The value of the number in the number's native_unit_of_measurement.

public:
    NumberEntity(QObject* parent = NULL);
    virtual ~NumberEntity();

public slots:
    void seValue() {}

protected:
    QString _deviceClass;
    QString _mode;
    float _nativeMaxValue;
    float _nativeMinValue;
    float _nativeStep;
    float _nativeValue;
};

#endif


/*

AVAILABLE DEVICE CLASSES
    
        TEMPERATURE             Supported units: C, F	

*/