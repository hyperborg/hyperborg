/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HDMI_CEC_H
#define HDMI_CEC_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class hdmi_cec : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hdmi_cec.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hdmi_cec();
    ~hdmi_cec();

    QString name() 		{ return "hdmi_cec"; }
    QString description()	{ return "Support for HDMI CEC."; }

protected:
    	void pad_physical_address();
	void parse_mapping();
	void setup();
	void _volume();
	void _process_volume();
	void _tx();
	void _standby();
	void _power_on();
	void _select_device();
	void _update();
	void _new_device();
	void _shutdown();
	void _start_cec();
	void __init__();
	void update();
	void  async_added_to_hass();
	void _update();
	void name();
	void vendor_id();
	void vendor_name();
	void physical_address();
	void type();
	void type_id();
	void icon();
	void device_state_attributes();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif