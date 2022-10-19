#ifndef SwitchENTITY_H
#define SwitchENTITY_H

#include <entity.h>

class SwitchEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(SwitchEntity)

    Q_PROPERTY(bool isOn MEMBER _isOn)

public:
    SwitchEntity(QObject *parent=NULL);
    ~SwitchEntity();

public slots:
    virtual void turnOn() {}
    virtual void turnOff() {}
    virtual void toggle() {}

protected:
    bool _isOn;

};

#endif

/*
AVAILABLE DEVICE CLASSES

    outlet  -    Device is an outler for power.
    switch  -   Device is switch for some type of entity.

*/