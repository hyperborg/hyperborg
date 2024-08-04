#ifndef HYVALUE_H
#define HYVALUE_H

#include "common.h"

class HyValue
{
public:
    HyValue(QVariant v = QVariant(), Unit u = Unit::NotDefined)
    {
        value = v;
        unit = u;
    }
    ~HyValue() {}

    QVariant value;
    Unit unit;
};

#endif