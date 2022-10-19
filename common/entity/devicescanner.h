#ifndef DeviceScannerENTITY_H
#define DeviceScannerENTITY_H

#include <entity.h>

class DeviceScannerEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(DeviceScannerEntity)

    Q_PROPERTY(QString sourceType MEMBER _sourceType)			// The source type, eg gps or router, of the device.
    Q_PROPERTY(bool isConnected MEMBER _isConnected)			// 	The connection state of the device.
    Q_PROPERTY(int batteryLevel MEMBER _batteryLevel)			// The battery level of the device.
    Q_PROPERTY(QString ipAddress MEMBER _ipAddress)			    // The IP address of the device.
    Q_PROPERTY(QString macAddress MEMBER _macAddress)			// The MAC address of the device.
    Q_PROPERTY(QString hostname MEMBER _hostname)			    // The hostname of the device.

public:
    DeviceScannerEntity(QObject *parent=NULL);
    ~DeviceScannerEntity();

protected:
    QString _sourceType;
    bool _isConnected;
    int _batteryLevel;
    QString _ipAddress;
    QString _macAddress;
    QString _hostname;
};

#endif