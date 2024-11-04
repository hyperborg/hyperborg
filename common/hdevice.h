#pragma once

#ifndef HDEVICE_H
#define HDEVICE_H

#include "common.h"
#include "hfs_interface.h"
#include "hactor.h"

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>

class HDevice : public QObject
{
    Q_OBJECT
public:
    HDevice(QObject* parent = nullptr);
    virtual ~HDevice();

public slots:
    virtual void loadConfiguration(QString str);                            // (re)load configuration (including clearing up)
    virtual void setEnabled(bool flag) {}
    void setHFS(HFS_Interface* h);
    void log(int severity, QString logline);

protected slots:
    void emitStateChanged(Common_State state)
    {
        emit stateChanged(state);
    }

signals:
    void stateChanged(Common_State state);                                  // plugin state changed
    void signal_log(int severity, QString logline, QString id);             // log signal to core

    void attachActor(HActor* actor);
    void detachActor(HActor* actor);


protected:
    QString _id;
    HFS_Interface* hfs;
};

#endif