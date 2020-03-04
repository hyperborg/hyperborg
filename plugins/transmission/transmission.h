/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class transmission : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "transmission.json");
    Q_INTERFACES(HyPluginInterface);
public:
    transmission();
    ~transmission();

    QString name() 		{ return "transmission"; }
    QString description()	{ return "Support for the Transmission BitTorrent client API."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();
	void  get_api();
	void __init__();
	void api();
	void add_torrent();
	void add_options();
	void set_scan_interval();
	void refresh();
	void  async_options_updated();
	void host();
	void signal_update();
	void update();
	void init_torrent_list();
	void check_completed_torrent();
	void check_started_torrent();
	void check_started_torrent_info();
	void get_started_torrent_count();
	void get_completed_torrent_count();
	void start_torrents();
	void stop_torrents();
	void set_alt_speed_enabled();
	void get_alt_speed_enabled();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif