/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HEOS_H
#define HEOS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class heos : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "heos.json");
    Q_INTERFACES(HyPluginInterface);
public:
    heos();
    ~heos();

    QString name() 		{ return "heos"; }
    QString description()	{ return "Denon HEOS Media Player."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  disconnect_controller();
	void  async_unload_entry();
	void __init__();
	void  connect_listeners();
	void  disconnect();
	void  _controller_event();
	void  _heos_event();
	void update_ids();
	void _build_source_list();
	void  play_source();
	void get_current_source();
	void connect_update();
	void  get_sources();
	void  update_sources();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif