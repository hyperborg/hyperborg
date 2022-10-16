#ifndef DeviceTrackerENTITY_H
#define DeviceTrackerENTITY_H

#include "entity.h"

class DeviceTrackerEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(DeviceTrackerEntity);


    Q_PROPERTY(QString sourceType MEMBER _sourceType);			 // The source type, eg gps or router, of the device.
    Q_PROPERTY(float latitude MEMBER _latitude);			 // The latitude coordinate of the device.
    Q_PROPERTY(float longitude MEMBER _longnitude);			 // The longitude coordinate of the device.
    Q_PROPERTY(int batteryLevel MEMBER _batteryLevel);			 // The battery level of the device.
    Q_PROPERTY(int locationAccuracy MEMBER _locationAccurancy);		 // The location accuracy (m) of the device.
    Q_PROPERTY(QString locationName MEMBER _locationName);		 // The location name of the device.

public:
    DeviceTrackerEntity(QObject *parent=NULL);
    ~DeviceTrackerEntity();

private:
    QString _sourceType;
    float _latitude;
    float _longitude;
    int _batteryLevel;
    int _locationAccurancy;
    QString _locationName;
};

#endif