/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef REMOTE_RPI_GPIO_H
#define REMOTE_RPI_GPIO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class remote_rpi_gpio : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "remote_rpi_gpio.json");
    Q_INTERFACES(HyPluginInterface);
public:
    remote_rpi_gpio();
    ~remote_rpi_gpio();

    QString name() 		{ return "remote_rpi_gpio"; }
    QString description()	{ return "Support for controlling GPIO pins of a Raspberry Pi."; }

protected:
    	void setup();
	void setup_output();
	void setup_input();
	void write_output();
	void read_input();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif