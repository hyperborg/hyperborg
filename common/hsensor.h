#pragma once

#ifndef HSENSOR_H
#define HSENSOR_H

#include "common.h"
#include <hactor.h>


class HSensor : public HActor
{
Q_OBJECT
public:
    HSensor(QString basename, QString rawname, SensorInfo sinfo, QObject *parent=nullptr) : HActor(basename, rawname, parent)
    {
        m_rawunit = sinfo.unit;
        m_unit = sinfo.unit;

    }
    virtual ~HSensor()               {}
};

#endif