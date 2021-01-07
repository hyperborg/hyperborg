#ifndef HDEVICE_H
#define HDEVICE_H

#include "common.h"
#include "hyobject.h"

#include <QJsonObject>
#include <QJsonArray>

class HDevice : public HyObject
{
Q_OBJECT
public:
    HDevice(QObject *parent=nullptr);
    virtual ~HDevice();

    QJsonObject configurationTemplate();
    void saveConfiguration(QJsonObject &json);
    bool loadConfiguration(QJsonObject &json);

};

#endif