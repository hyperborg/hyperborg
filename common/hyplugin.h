#ifndef HYPLUGIN_H

#define HYPLUGIN_H

#include "common.h"

#include <QObject>
#include <QString>
#include <QByteArray>
#include <QFile>
#include <QStringList>
#include "hentity.h"
#include "hentityfactory.h"

// Abstract class for all HyperBorg system plugin
// All plugins should be based on this one

class HyPluginInterface
{
public:
    // REGISTRATION FUNCTIONS, DRIVER FEATURES
    HyPluginInterface()             { _status=Offline;              // Basic initialization for all plugins
				      he_factory = NULL;	}
    virtual ~HyPluginInterface()    = default;
    virtual QString name()          = 0;                            // Name of the plugin. This should be unique
    virtual QString description()   = 0;                            // Description of what this plugin provides, what it supports
    virtual QString version()       { return "0.0.0";           }   // Version of the plugin. Used on possible depenceny scans and bug reports.
    virtual int implementation()    { return NotImplemented;    }   // Flag shows the stability of the plugin. NotImplemented plugins are unloaded if they are found
    virtual int powerOptions()      { return NonCritical;       }   // Flag shows how critical this plugin in the whole mesh. Read common.h for more details
    virtual int requiredFeatures()  { return Standard;          }   // Shows what hardware requirements the plugin has
    virtual int discover()          { return 0;                 }   // Discover attached devices if possible (like 1Wire, I2C). Returns the number of disovered devices or -1 on error.

    virtual QString author()        { return "Unknown author";  }   // Author(s) of this plugin
    virtual QByteArray pluginPicture()  { return QByteArray();  }   // Icon for this plugin
    virtual void setSystemState(SystemStates ss)                    // If the system has issues, it can be handled over this one
    {
        Q_UNUSED(ss);
    }
    virtual int  status()           { return _status;           }


    // CONFIGURATION FUNCTIONS FOR JSON
    virtual QJsonObject configurationTemplate()         = 0;        // Returns valid JSON node that contains all acceptable configuration possibilities (the input validation is done in core)
    virtual bool loadConfiguration(QJsonObject json)    = 0;        // Function that loads the configuration for this plugin. Returns false at error. Errors are reported via log interface
    virtual void saveConfiguration(QJsonObject &json)   = 0;        // Returns the currently used configuration (might be modified internally) We do not care what it contains
                                                                    // as long as it is a parseable JSON. The plugin's responsibility is to be able to load what it saved.
    virtual void setupDemo() {}                                     // When writing a plugin for a Hyperborg system, most of the time the actual device is already installed and the implementation
                                                                    // of the driver preceeds the finalization of the configuration functions. So instead of using JSON editor to update all the time,
                                                                    // this function could be used to setup with the existing devices then used saveConfiguration() for creating the first JSON 
                                                                    // configuration file

    // ENITITY HANDLING FUNCTIONS
    void setEntityFactory(HEntityFactory *fact)
    {
	he_factory = fact;
    }

    // SENSOR/ACTOR FUNCTIONS
    virtual void inputs()   {}                                        // List of events provided by the plugin
    virtual void outputs()  {}                                        // List of events accepted by the plugin

    // QT CONNECTION RELATED FUNCTIONS
    virtual QObject *getObject()    = 0;   			   // used to connect plugin's communication to the core


    virtual bool checkConfigurationIO()                            // This function check if the plugin can load the configuration it just saved. 
    {
        bool retval = true;
        QJsonObject obj;
        saveConfiguration(obj);
        retval = loadConfiguration(obj);
        return retval;
    }

    virtual bool dumpConfigurationToFile()                         // Writes our current configuration in the file debug/<plugin_name>.json. Returns false if file could not be created
    {
        QFile f("debug/"+name()+".json");
        if (!f.open(QIODevice::WriteOnly))
        {
            return false;
        }

        QJsonObject obj;
        saveConfiguration(obj);
        f.write(QJsonDocument(obj).toJson());

        f.close();
        return true;
    }

protected:
    int _status;
    HEntityFactory *he_factory;

};

#define HyPluginInterface_iid "com.nagyimre.HyperBorg.HyPluginInterface"
Q_DECLARE_INTERFACE(HyPluginInterface, HyPluginInterface_iid);

#endif
