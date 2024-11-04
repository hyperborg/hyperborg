#pragma once

#ifndef HACTOR_H
#define HACTOR_H

#include "common.h"
#include "hfs_interface.h"

#include <QObject>
#include <QVariant>
#include <QString>

class HActor : public QObject
{
    Q_OBJECT
public:
    HActor(QObject* parent = nullptr) : enabled(true), hfs(nullptr)
    {
    }
    virtual ~HActor() {}

    virtual int type() { return 0; }

public slots:
    virtual void setEnabled(bool flag) 
    {
        enabled = flag;
    }

    virtual void setHFS(HFS_Interface* hfsi)
    {
    }

    virtual void setValue(QVariant _value)
    {
        value = _value;
        emit changeValueRequested(value);
    }

protected slots:
    void emitStateChanged(Common_State state)
    {
        emit stateChanged(state);
    }

    void changeValueRequested(QVariant var)
    {
    }

signals:
    void stateChanged(Common_State state);

protected:
    QVariant value;
    HFS_Interface* hfs;
    bool enabled; 
    

};

#endif