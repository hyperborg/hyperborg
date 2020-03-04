/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RAINCLOUD_H
#define RAINCLOUD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class raincloud : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "raincloud.json");
    Q_INTERFACES(HyPluginInterface);
public:
    raincloud();
    ~raincloud();

    QString name() 		{ return "raincloud"; }
    QString description()	{ return "Support for Melnor RainCloud sprinkler water timer."; }

protected:
    	void setup();
	void hub_refresh();
	void __init__();
	void __init__();
	void name();
	void  async_added_to_hass();
	void _update_callback();
	void unit_of_measurement();
	void device_state_attributes();
	void icon();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif