/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WATSON_IOT_H
#define WATSON_IOT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class watson_iot : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "watson_iot.json");
    Q_INTERFACES(HyPluginInterface);
public:
    watson_iot();
    ~watson_iot();

    QString name() 		{ return "watson_iot"; }
    QString description()	{ return "Support for the IBM Watson IoT Platform."; }

protected:
    	void setup();
	void event_to_json();
	void shutdown();
	void __init__();
	void _event_listener();
	void get_events_json();
	void write_to_watson();
	void run();
	void block_till_done();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif