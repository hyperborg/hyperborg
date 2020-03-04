/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class weather : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "weather.json");
    Q_INTERFACES(HyPluginInterface);
public:
    weather();
    ~weather();

    QString name() 		{ return "weather"; }
    QString description()	{ return "Weather component that handles meteorological data for your location."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();
	void temperature();
	void temperature_unit();
	void pressure();
	void humidity();
	void wind_speed();
	void wind_bearing();
	void ozone();
	void attribution();
	void visibility();
	void forecast();
	void precision();
	void state_attributes();
	void state();
	void condition();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif