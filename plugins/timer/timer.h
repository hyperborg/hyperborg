/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class timer : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "timer.json");
    Q_INTERFACES(HyPluginInterface);
public:
    timer();
    ~timer();

    QString name() 		{ return "timer"; }
    QString description()	{ return "Support for Timers."; }

protected:
    	void _none_to_empty_dict();
	void  async_setup();
	void  reload_service_handler();
	void  _process_create_data();
	void _get_suggested_id();
	void  _update_data();
	void __init__();
	void from_yaml();
	void should_poll();
	void name();
	void icon();
	void state();
	void state_attributes();
	void unique_id();
	void  async_added_to_hass();
	void  async_start();
	void  async_pause();
	void  async_cancel();
	void  async_finish();
	void  async_finished();
	void  async_update_config();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif