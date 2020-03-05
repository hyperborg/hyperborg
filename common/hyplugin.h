#ifndef HYPLUGIN_H
#define HYPLUGIN_H

#include <QObject>
#include <QString>
#include <QByteArray>

#include "common.h"

// Abstract class for all HyperBorg system plugin
// All plugins should be based on this one

class HyPluginInterface 
{
public:
    virtual ~HyPluginInterface()	= default;
    virtual QString name() 		= 0;
    virtual QString description()	= 0;
    virtual int implementation()	{ return NotImplemented; }
    virtual int powerOptions()		{ return NonCritical; 	}
    virtual int requiredFeatures()	{ return Standard;	}

//    virtual QString author()		  = 0;
//    virtual QByteArray pluginPicture()  = 0;
//    virtual int powerOptions() { return PowerOptions::NonCritical; }
//    virtual void setSystemState(SystemStates ss) {}
};

#define HyPluginInterface_iid "com.nagyimre.HyperBorg.HyPluginInterface"
Q_DECLARE_INTERFACE(HyPluginInterface, HyPluginInterface_iid);

#endif
