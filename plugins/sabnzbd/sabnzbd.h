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

class sabnzbd : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sabnzbd.json");
    Q_INTERFACES(HyPluginInterface);
public:
    sabnzbd();
    ~sabnzbd();

    QString name() 		{ return "sabnzbd"; }
    QString description()	{ return "Support for monitoring an SABnzbd NZB client."; }

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