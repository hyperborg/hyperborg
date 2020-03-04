/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UTILITY_METER_H
#define UTILITY_METER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class utility_meter : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "utility_meter.json");
    Q_INTERFACES(HyPluginInterface);
public:
    utility_meter();
    ~utility_meter();

    QString name() 		{ return "utility_meter"; }
    QString description()	{ return "Support for tracking consumption over given periods of time."; }

protected:
    	void async_setup();
	void __init__();
	void async_added_to_hass();
	void should_poll();
	void icon();
	void state();
	void state_attributes();
	void async_reset_meters();
	void async_select_tariff();
	void async_next_tariff();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif