/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NETGEAR_LTE_H
#define NETGEAR_LTE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class netgear_lte : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "netgear_lte.json");
    Q_INTERFACES(HyPluginInterface);
public:
    netgear_lte();
    ~netgear_lte();

    QString name() 		{ return "netgear_lte"; }
    QString description()	{ return "Support for Netgear LTE modems."; }

protected:
    	void  async_update();
	void get_modem_data();
	void  async_setup();
	void  service_handler();
	void  _setup_lte();
	void cleanup_retry();
	void  _login();
	void fire_sms_event();
	void  cleanup();
	void  _update();
	void  _retry_login();
	void _init_unique_id();
	void  async_added_to_hass();
	void should_poll();
	void available();
	void unique_id();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif