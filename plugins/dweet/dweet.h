/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DWEET_H
#define DWEET_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class dweet : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dweet.json");
    Q_INTERFACES(HyPluginInterface);
public:
    dweet();
    ~dweet();

    QString name() 		{ return "dweet"; }
    QString description()	{ return "Support for sending data to Dweet.io."; }

protected:
    	void setup();
	void dweet_event_listener();
	void send_data();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif