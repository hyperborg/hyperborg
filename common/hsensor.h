#pragma once

#ifndef HSENSOR_H
#define HSENSOR_H

#include "common.h"
#include <hactor.h>


class HSensor : public HActor
{
Q_OBJECT
public:
    HSensor(SensorInfo sinfo, QObject *parent=nullptr) 
    {
    }
    virtual ~HSensor()               {}
};

#endif