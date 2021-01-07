/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RPI_GPIO_H
#define RPI_GPIO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class rpi_gpio : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rpi_gpio.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rpi_gpio(QObject *parent=nullptr);
    ~rpi_gpio();

    QString name() 		{ return "rpi_gpio"; }
    QString description()	{ return "Support for controlling GPIO pins of a Raspberry Pi."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void cleanup_gpio();
	void prepare_gpio();
	void setup_output();
	void setup_input();
	void write_output();
	void read_input();
	void edge_detect();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif