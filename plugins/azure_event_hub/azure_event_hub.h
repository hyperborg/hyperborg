/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AZURE_EVENT_HUB_H
#define AZURE_EVENT_HUB_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class azure_event_hub : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "azure_event_hub.json");
    Q_INTERFACES(HyPluginInterface);
public:
    azure_event_hub();
    ~azure_event_hub();

    QString name() 		{ return "azure_event_hub"; }
    QString description()	{ return "Support for Azure Event Hubs."; }

protected:
    	void  async_setup();
	void  async_send_to_event_hub();
	void  async_shutdown();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif