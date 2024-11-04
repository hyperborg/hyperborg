#ifndef HYPLUGIN_H
#define HYPLUGIN_H

#include "common.h"
#include "hfsitem.h"

#include <QObject>
#include <QString>
#include <QByteArray>
#include <QFile>
#include <QStringList>

// Abstract class for all HyperBorg system plugin
// All plugins should be based on this one

class HyPluginInterface
{
public:
    // REGISTRATION FUNCTIONS, DRIVER FEATURES
    HyPluginInterface()
    {}

    virtual ~HyPluginInterface()        = default;
    virtual QString name()              = 0;                                // Name of the plugin. This should be unique
    virtual QString description()       = 0;                                // Description of what this plugin provides, what it supports
    virtual QString version()           { return "0.0.0";           }       // Version of the plugin. Used on possible depenceny scans and bug reports.
    virtual int implementation()        { return NotImplemented;    }       // Flag shows the stability of the plugin. NotImplemented plugins are unloaded if they are found
    virtual int requiredFeatures()      { return Standard;          }       // Shows what hardware requirements the plugin has
    virtual int discover()              { return 0;                 }       // Discover attached devices if possible (like 1Wire, I2C). Returns the number of disovered devices or -1 on error.

    virtual QString author()            { return "Unknown author";  }       // Author(s) of this plugin
    virtual QByteArray pluginPicture()  { return QByteArray();  }           // Icon for this plugin
    virtual QString basePath()          { return "plugins" + QString(PATH_SEPARATOR) + name(); }

    // QT CONNECTION RELATED FUNCTIONS
    virtual QObject *getObject()    = 0;                                    // used to connect plugin's communication to the core

};

#define HyPluginInterface_iid "com.nagyimre.HyperBorg.HyPluginInterface"
Q_DECLARE_INTERFACE(HyPluginInterface, HyPluginInterface_iid);
#endif

