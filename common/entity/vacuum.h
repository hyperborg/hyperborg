#ifndef VacuumENTITY_H
#define VacuumENTITY_H

#include <entity.h>

class VacuumEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(VacuumEntity)

    Q_PROPERTY(QString name MEMBER _name)                      // - Name of the device.
    Q_PROPERTY(QString state MEMBER _state)                    // - One of the states listed in the states section.
    Q_PROPERTY(int batteryLevel MEMBER _batteryLevel)          // - Current battery level.
    Q_PROPERTY(QString batteryIcon MEMBER _batteryIcon)        // - Battery icon to show in UI.
    Q_PROPERTY(QString fanSpeed MEMBER _fanSpeed)              // - The current fan speed.
    Q_PROPERTY(QStringList fanSpeedList MEMBER _fanSpeedList)  // - List of available fan speeds.
    Q_PROPERTY(QString error MEMBER _error)                    // - An error message if the vacuum is in STATE_ERROR.

public:
    VacuumEntity(QObject *parent=NULL);
    ~VacuumEntity();

protected:
    QString _name;
    QString _state;
    int _batteryLevel;
    QString _batteryIcon;
    QString _fanSpeed;
    QStringList _fanSpeedList;
    QString _error;
};

#endif