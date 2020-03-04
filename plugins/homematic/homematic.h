/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HOMEMATIC_H
#define HOMEMATIC_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class homematic : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "homematic.json");
    Q_INTERFACES(HyPluginInterface);
public:
    homematic();
    ~homematic();

    QString name() 		{ return "homematic"; }
    QString description()	{ return "Support for HomeMatic devices."; }

protected:
    	void setup();
	void _hm_service_virtualkey();
	void _service_handle_value();
	void _service_handle_reconnect();
	void _service_handle_device();
	void _service_handle_install_mode();
	void _service_put_paramset();
	void _system_callback_handler();
	void _get_devices();
	void _create_ha_id();
	void _hm_event_handler();
	void _device_from_servicecall();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif