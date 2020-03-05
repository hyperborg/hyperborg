#ifndef adminpanel_H
#define adminpanel_H

#include <QObject>
#include <QString>
#include <QtPlugin>

#include <hyplugin.h>

class AdminPanel : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "adminpanel.json");
    Q_INTERFACES(HyPluginInterface);

public:
    AdminPanel() {}
    ~AdminPanel() {}

    QString name() 	   { return "AdminPanel"; 		    	}
    QString description()  { return "HyperBorg Administrator Panel"; 	}
    int requiredFeatures() { return GUISupport; 			}
    int implementation()   { return Developement;		    	}
};


#endif