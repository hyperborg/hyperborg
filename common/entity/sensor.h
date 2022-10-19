#ifndef SensorENTITY_H
#define SensorENTITY_H

#include <entity.h>

class SensorEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(SensorEntity)

    Q_PROPERTY(QDateTime lastReset MEMBER _lastReset)                              // - The time when an accumulating sensor such as an electricity usage meter, gas meter, water meter etc.was initialized.If the time of initialization is unknown, set it to None.Note that the datetime.datetime returned by the last_reset property will be converted to an ISO 8601 - formatted string when the entity's state attributes are updated. When changing last_reset, the state must be a valid number.
    Q_PROPERTY(QString nativeValue	 MEMBER _nativeValue)                          // - The value of the sensor in the sensor's native_unit_of_measurement. Using a device_class may restrict the types that can be returned by this property.
    Q_PROPERTY(QString nativeUnitOfMeasurement  MEMBER _nativeUnitOfMeasurement)   // - The unit of measurement that the sensor's value is expressed in. If the native_unit_of_measurement is C or F, and its device_class is temperature, the sensor's unit_of_measurement will be the preferred temperature unit configured by the user and the sensor's state will be the native_value after an optional unit conversion. If not None, the sensor is assumed to be numerical and will be displayed as a line-chart in the frontend instead of as discrete values.
    Q_PROPERTY(QString stateClass  MEMBER _stateClass)                             // - Type of state.If not None, the sensor is assumed to be numericaland will be displayed as a line - chart in the frontend instead of as discrete values.

public:
    SensorEntity(QObject *parent=NULL);
    ~SensorEntity();

protected:
    QDateTime _lastReset;
    QString _nativeValue;
    QString _nativeUnitOfMeasurement;
    QString _stateClass;
};

#endif

/*

AVAILABLE DEVICE CLASSES

    
*/