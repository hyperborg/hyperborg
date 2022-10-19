#ifndef RemoteENTITY_H
#define RemoveENTITY_H

#include <entity.h>

class RemoteEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(RemoteEntity)

    Q_PROPERTY(QString current_activity MEMBER _currentActivity)       // Return the current active activity
    Q_PROPERTY(QStringList activityList	MEMBER _activityList)          // Return the list of available activities

public:
    RemoteEntity(QObject *parent=NULL);
    ~RemoteEntity();

public slots:
    virtual void turOn() {}
    virtual void turnOff() {}
    virtual void toggle() {}
    virtual void sendCommand() {}
    virtual void learnCommand() {}
    virtual void deleteCommand() {}

protected:
    QString _currentActivity;
    QStringList _activityList;
};

#endif


/*
SUPPORTED FEATURES

    LEARN_COMMAND	// - Entity allows learning commands from devices.
    DELETE_COMMAND	// - Entity allows deleting commands from devices.
    ACTIVITY	    // - Entity supports activities.

*/