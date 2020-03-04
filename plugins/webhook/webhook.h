/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WEBHOOK_H
#define WEBHOOK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class webhook : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "webhook.json");
    Q_INTERFACES(HyPluginInterface);
public:
    webhook();
    ~webhook();

    QString name() 		{ return "webhook"; }
    QString description()	{ return "Webhooks for Home Assistant."; }

protected:
    	void async_register();
	void async_unregister();
	void async_generate_id();
	void async_generate_url();
	void async_generate_path();
	void  async_handle_webhook();
	void  async_setup();
	void  _handle();
	void websocket_list();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif