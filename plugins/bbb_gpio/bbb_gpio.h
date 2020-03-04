/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BBB_GPIO_H
#define BBB_GPIO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class bbb_gpio : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "bbb_gpio.json");
    Q_INTERFACES(HyPluginInterface);
public:
    bbb_gpio();
    ~bbb_gpio();

    QString name() 		{ return "bbb_gpio"; }
    QString description()	{ return "Support for controlling GPIO pins of a Beaglebone Black."; }

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