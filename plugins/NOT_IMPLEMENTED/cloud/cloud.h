/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CLOUD_H
#define CLOUD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class cloud : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "cloud.json");
    Q_INTERFACES(HyPluginInterface);
public:
    cloud(QObject *parent=nullptr);
    ~cloud();

    QString name() 		{ return "cloud"; }
    QString description()	{ return "Component to integrate the Home Assistant cloud."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_is_logged_in();
	void async_active_subscription();
	void async_create_cloudhook();
	void async_delete_cloudhook();
	void async_remote_ui_url();
	void is_cloudhook_request();
	void async_setup();
	void _startup();
	void _shutdown();
	void _service_handler();
	void _on_connect();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif