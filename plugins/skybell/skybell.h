/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SKYBELL_H
#define SKYBELL_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class skybell : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "skybell.json");
    Q_INTERFACES(HyPluginInterface);
public:
    skybell();
    ~skybell();

    QString name() 		{ return "skybell"; }
    QString description()	{ return "Support for the Skybell HD Doorbell."; }

protected:
    	void setup();
	void __init__();
	void should_poll();
	void update();
	void device_state_attributes();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif