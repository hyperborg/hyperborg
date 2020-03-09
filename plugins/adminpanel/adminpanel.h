#ifndef adminpanel_H
#define adminpanel_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QTimer>
#include <QDebug>

#include <hyplugin.h>
#include <hyobject.h>

class AdminPanel : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "adminpanel.json");
    Q_INTERFACES(HyPluginInterface);

public:
    AdminPanel() {}
    ~AdminPanel() {}

    QString name() 	   { return "AdminPanel"; 		    	}
    QString description()  { return "HyperBorg Administrator Panel"; 	}
    QObject *getObject()   { return this;				}
//    int requiredFeatures() { return GUISupport; 			}
    int implementation()   { return Developement;		    	}
    void init()
    {
	QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));
	timer.setSingleShot(false);
	timer.start(1000);
    }

protected slots:
    void timeout()
    {
	qDebug() << "adminpanel timeout";
	log(Info, "adminpanel timeout through log");
    }

private:
    QTimer timer;

};


#endif