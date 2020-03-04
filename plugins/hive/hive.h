/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HIVE_H
#define HIVE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class hive : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hive.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hive();
    ~hive();

    QString name() 		{ return "hive"; }
    QString description()	{ return "Support for the Hive devices and services."; }

protected:
    	void setup();
	void heating_boost();
	void hot_water_boost();
	void refresh_system();
	void wrapper();
	void __init__();
	void  async_added_to_hass();
	void _update_callback();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif