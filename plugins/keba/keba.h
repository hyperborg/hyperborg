/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef KEBA_H
#define KEBA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class keba : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "keba.json");
    Q_INTERFACES(HyPluginInterface);
public:
    keba();
    ~keba();

    QString name() 		{ return "keba"; }
    QString description()	{ return "Support for KEBA charging stations."; }

protected:
    	void async_setup();
	void execute_service();
	void __init__();
	void start_periodic_request();
	void _periodic_request();
	void setup();
	void hass_callback();
	void _set_fast_polling();
	void add_update_listener();
	void async_set_energy();
	void async_set_current();
	void async_start();
	void async_stop();
	void async_enable_ev();
	void async_disable_ev();
	void async_set_failsafe();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif