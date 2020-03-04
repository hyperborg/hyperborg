/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GRAPHITE_H
#define GRAPHITE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class graphite : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "graphite.json");
    Q_INTERFACES(HyPluginInterface);
public:
    graphite();
    ~graphite();

    QString name() 		{ return "graphite"; }
    QString description()	{ return "Support for sending data to a Graphite installation."; }

protected:
    	void setup();
	void __init__();
	void start_listen();
	void shutdown();
	void event_listener();
	void _send_to_graphite();
	void _report_attributes();
	void run();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif