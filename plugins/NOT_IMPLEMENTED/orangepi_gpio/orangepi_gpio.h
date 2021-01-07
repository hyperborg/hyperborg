/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ORANGEPI_GPIO_H
#define ORANGEPI_GPIO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class orangepi_gpio : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "orangepi_gpio.json");
    Q_INTERFACES(HyPluginInterface);
public:
    orangepi_gpio(QObject *parent=nullptr);
    ~orangepi_gpio();

    QString name() 		{ return "orangepi_gpio"; }
    QString description()	{ return "Support for controlling GPIO pins of a Orange Pi."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void cleanup_gpio();
	void prepare_gpio();
	void setup_mode();
	void setup_input();
	void read_input();
	void edge_detect();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif