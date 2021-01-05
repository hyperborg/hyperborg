#ifndef HYPLUGIN_H
#define HYPLUGIN_H

#include <QObject>
#include <QString>
#include <QByteArray>
#include <QDomNode>

#include "common.h"

// Abstract class for all HyperBorg system plugin
// All plugins should be based on this one

class HyPluginInterface
{
public:
    // REGISTRATION FUNCTIONS
	    HyPluginInterface()		{ _status=Offline;		  }	// Basic initialization for all plugins
    virtual ~HyPluginInterface()	= default;
    virtual QString name() 		= 0;					// Name of the plugin. This should be unique
    virtual QString description()	= 0;					// Description of what this plugin provides, what it supports
    virtual QString version()		{ return "0.0.0";		   }	// Version of the plugin. Used on possible depenceny scans and bug reports.
    virtual int implementation()	{ return NotImplemented; 	   }	// Flag shows the stability of the plugin. NotImplemented plugins are unloaded if they are found
    virtual int powerOptions()		{ return NonCritical; 		   }	// Flag shows how critical this plugin in the whole mesh. Read common.h for more details
    virtual int requiredFeatures()	{ return Standard;		   }	// Shows what hardware requirements the plugin has
    virtual int discover()		{ return 0;			   }	// Discover attached devices if possible (like 1Wire, I2C). Returns the number of disovered devices or -1 on error.

    virtual QString author()		{ return "Unknown author";	    }	// Author(s) of this plugin
    virtual QByteArray pluginPicture()  { return QByteArray();	  	    }	// Icon for this plugin

#if 0
    // CONFIGURATION FUNCTIONS
    virtual QDomNode configurationTemplate()= 0;				// Returns valid XML node that contains all acceptable configuration possibilities (the input validation is done in core)
    virtual QDomNode saveConfiguration()    = 0;				// Returns the currently used configuration (might be modified internally) We do not care what it contains
										                        // as long as it is a parseable XML. The plugin's responsibility is to be able to load what it saved.
    virtual bool loadConfiguration(QDomNode) = 0;				// Function that loads the configuration for this plugin. Returns false at error. Errors are reported via log interface
#endif
    // STATUS FUNCTIONS
    virtual void setSystemState(SystemStates ss)  // If the system has issues, it can be handled over this one
    {
	Q_UNUSED(ss);
    }
    virtual int  status()		{ return _status;		    }

    // SENSOR/ACTOR FUNCTIONS
    virtual void inputs()		{}					// List of events provided by the plugin
    virtual void outputs()		{}					// List of events accepted by the plugin

#if 1
    // QT CONNECTION RELATED FUNCTIONS
    virtual QObject *getObject() 	     = 0;				// used to connect plugin's communication to the core
#endif

protected:
    int _status;

};

#define HyPluginInterface_iid "com.nagyimre.HyperBorg.HyPluginInterface"
Q_DECLARE_INTERFACE(HyPluginInterface, HyPluginInterface_iid);

#endif
