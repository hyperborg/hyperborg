#ifndef HRELAY_H
#define HRELAY_H

#include <QObject>
#include "hyobject.h"

class HRelay : public HyObject
{
Q_OBJECT
public:
    HRelay(QObject *parent=nullptr) : HyObject(parent) {}
    ~HRelay() {}

signals:
    void relayChanged();

public:
    void setState(bool state);
};


#endif