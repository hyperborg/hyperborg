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
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY isEnabledChanged)
    Q_PROPERTY(QString rawname MEMBER m_rawname)

public:
    HActor(QString basename, QString rawname, QObject* parent = nullptr) : enabled(true), hfs(nullptr)
    {
        setObjectName(basename);
        m_rawname = rawname;
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
        qDebug() << objectName() << " setValue: " << _value << " unit: " << m_unit;
        m_value = _value;
        emit changeValueRequested(m_value);
    }

    QVariant rawvalue() const { return m_rawvalue; }
    virtual void setRawValue(QVariant _value)
    {
        m_rawvalue = _value;
        qDebug() << objectName() << " setRawValue: " << m_rawvalue << " rawunit: " << m_rawunit;

        if (m_rawunit!=m_unit)
        {
            setProperty("value", QVariant(convert(m_rawunit, m_unit, _value.toDouble())));
        }
        else
        {
            setProperty("value", _value);
        }
    }

    Unit unit() const { return m_unit; }
    virtual void setUnit(Unit _unit)
    {
        m_unit = _unit;
    }

    Unit rawunit() const { return m_rawunit; }
    virtual void setRawUnit(Unit _unit)
    {
        m_rawunit = _unit;
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
    HFS_Interface* hfs;
    bool enabled;

    QString  m_rawname;
    QVariant m_value;
    Unit     m_unit;
    QVariant m_rawvalue;
    Unit     m_rawunit;

};

#endif