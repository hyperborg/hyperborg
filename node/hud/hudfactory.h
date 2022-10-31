#ifndef HUDFactory_H
#define HUDFactory_H

#include "hudbutton.h"
#include "hudcalendar.h"
#include "hudclock.h"
#include "hudelement.h"
#include "hudeventlist.h"
#include "hudfactory.h"
#include "hudgarbage.h"
#include "hudgauge.h"
#include "hudhfstree.h"
#include "hudlibrary.h"
#include "hudnavigator.h"
#include "hudpowergrid.h"
#include "hudscreen.h"
#include "hudshoppinglist.h"
#include "hudtimetable.h"
#include "hudtodolist.h"
#include "hudweather.h"

class HUDFactory : public QObject
{
    Q_OBJECT
public:
    HUDFactory();
    ~HUDFactory();

    HUDElement* create(int type);
};

#endif
