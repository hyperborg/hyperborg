/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DATADOG_H
#define DATADOG_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class datadog : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "datadog.json");
    Q_INTERFACES(HyPluginInterface);
public:
    datadog();
    ~datadog();

    QString name() 		{ return "datadog"; }
    QString description()	{ return "Support for sending data to Datadog."; }

protected:
    	void setup();
	void logbook_entry_listener();
	void state_changed_listener();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif