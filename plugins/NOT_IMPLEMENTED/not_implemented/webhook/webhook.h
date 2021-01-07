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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class webhook : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "webhook.json");
    Q_INTERFACES(HyPluginInterface);
public:
    webhook(QObject *parent=nullptr);
    ~webhook();

    QString name() 		{ return "webhook"; }
    QString description()	{ return "Webhooks for Home Assistant."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_register();
	void async_unregister();
	void async_generate_id();
	void async_generate_url();
	void async_generate_path();
	void async_handle_webhook();
	void async_setup();
	void _handle();
	void websocket_list();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif