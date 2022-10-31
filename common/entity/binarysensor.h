#ifndef BinarySensorENTITY_H
#define BinarySensorENTITY_H

#include <entity.h>
#include <QString>

class BinarySensorEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(BinarySensorEntity)

    Q_PROPERTY(bool isOn MEMBER _isOn)                          // If the binary sensor is currently on or off.
    Q_PROPERTY(QString deviceClass MEMBER _deviceClass)          // Type of binary sensor.

public:
    BinarySensorEntity(QObject *parent=NULL);
    ~BinarySensorEntity();

protected:
    bool _isOn;
    QString _deviceClass;

};

#endif

/*
    Available device classes: 

    "battery"			- On means low, Off means normal.
    "batteryCharging"		- On means charging, Off means not charging.
    "CO"			- On means carbon monoxide detected, Off means no carbon monoxide (clear).
    "cold"			- On means cold, Off means normal.
    "connectivity"		- On means connected, Off means disconnected.
    "door"			- On means open, Off means closed.
    "garageDoor"		- On means open, Off means closed.
    "gas"			- On means gas detected, Off means no gas (clear).
    "heat"			- On means light detected, Off means no light.
    "hot"			- On means hot, Off means normal.
    "light"			- On means light detected, Off means no light.
    "lock"			- On means open (unlocked), Off means closed (locked).
    "moisture" 			- On means wet, Off means dry
    "motion"			- On means motion detected, Off means no motion (clear).
    "moving" 			- On means moving, Off means not moving (stopped).
    "occupancy"			- On means occupied, Off means not occupied (clear).
    "opening"			- On means open, Off means closed.
    "plug"			- On means plugged in, Off means unplugged.
    "power"			- On means power detected, Off means no power.
    "presence"			- On means home, Off means away.
    "problem"			- On means problem detected, Off means no problem (OK).
    "running"			- On means running, Off means not running.
    "safety"			- On means unsafe, Off means safe.
    "smoke"			- On means smoke detected, Off means no smoke (clear).
    "sound"			- On means sound detected, Off means no sound (clear).
    "tamper"			- On means tampering detected, Off means no tampering (clear)
    "update"			- On means update available, Off means up-to-date. The use of this device class should be avoided, please consider using the update entity instead.
    "vibration"			- On means vibration detected, Off means no vibration.
    "window"			- On means open, Off means closed.

*/