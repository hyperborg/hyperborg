/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SABNZBD_H
#define SABNZBD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class sabnzbd : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sabnzbd.json");
    Q_INTERFACES(HyPluginInterface);
public:
    sabnzbd(QObject *parent=nullptr);
    ~sabnzbd();

    QString name() 		{ return "sabnzbd"; }
    QString description()	{ return "Support for monitoring an SABnzbd NZB client."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_check_sabnzbd();
	void async_configure_sabnzbd();
	void async_setup();
	void sabnzbd_discovered();
	void async_setup_sabnzbd();
	void async_service_handler();
	void async_update_sabnzbd();
	void async_request_configuration();
	void async_configuration_callback();
	void success();
	void __init__();
	void async_pause_queue();
	void async_resume_queue();
	void async_set_queue_speed();
	void get_queue_field();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif