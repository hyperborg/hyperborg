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
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged);
    Q_PROPERTY(Unit unit READ unit WRITE setUnit NOTIFY unitChanged)
    Q_PROPERTY(QVariant rawvalue READ rawvalue WRITE setRawValue NOTIFY rawValueChanged);
    Q_PROPERTY(Unit rawunit READ rawunit WRITE setRawUnit NOTIFY rawUnitChanged)
    Q_PROPERTY(Common_State state READ state NOTIFY stateChanged)
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY isEnabledChanged)

public:
    HActor(QObject* parent = nullptr) : enabled(true), hfs(nullptr)
    {
    }
    virtual ~HActor() {}

    virtual int type() { return 0; }

public slots:
    virtual void setEnabled(bool flag)   {  enabled = flag;    }
    bool isEnabled()                     {  return enabled;    }

    virtual void setHFS(HFS_Interface* hfsi)
    {
        hfs = hfsi;
    }

    QVariant value() const { return m_value; }
    virtual void setValue(QVariant _value)
    {
        qDebug() << "setValue: " << _value;
        value = _value;
        emit changeValueRequested(value);
    }

    QVariant rawvalue() const { return m_rawvalue; }
    virtual void setRawValue(QVariant _value)
    {
        rawvalue = _value;
        if (m_rawunit!=m_unit)
        {
            setProperty("value", QVariant(convert(m_rawunit, n_unit, _value.toDouble())));
        }
        else
        {
            setProperty("value", _value);
        }
    }

    Unit unit() const { return m_unit; }
    virtual void setUnit(Unit _unit)
    {
        m_unit = unit;
    }

    Unit rawunit() const { return m_rawunit; }
    virtual void setRawUnit(Unit _unit)
    {
        m_rawunit = unit;
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
    void stateChanged(Common_State);
    void valueChanged(QVariant);
    void unitChanged(Unit);
    void rawValueChanged(QVariant);
    void rawUnitChanged(Unit);
    void isEnabledChanged(bool);

protected:
    QVariant value;
    HFS_Interface* hfs;
    bool enabled;

    QVariant m_value;
    Unit     m_unit;
    QVariant m_rawvalue;
    Unit     m_rawunit;

};

#endif