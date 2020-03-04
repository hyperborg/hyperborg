/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef METEO_FRANCE_H
#define METEO_FRANCE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class meteo_france : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "meteo_france.json");
    Q_INTERFACES(HyPluginInterface);
public:
    meteo_france();
    ~meteo_france();

    QString name() 		{ return "meteo_france"; }
    QString description()	{ return "Support for Meteo-France weather data."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void __init__();
	void get_data();
	void update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif