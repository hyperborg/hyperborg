/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class arduino : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "arduino.json");
    Q_INTERFACES(HyPluginInterface);
public:
    arduino();
    ~arduino();

    QString name() 		{ return "arduino"; }
    QString description()	{ return "Support for Arduino boards running with the Firmata firmware."; }

protected:
    	void setup();
	void stop_arduino();
	void start_arduino();
	void __init__();
	void set_mode();
	void get_analog_inputs();
	void set_digital_out_high();
	void set_digital_out_low();
	void get_digital_in();
	void get_analog_in();
	void get_firmata();
	void disconnect();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif