/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RACHIO_H
#define RACHIO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class rachio : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rachio.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rachio();
    ~rachio();

    QString name() 		{ return "rachio"; }
    QString description()	{ return "Integration with the Rachio Iro sprinkler system controller."; }

protected:
    	void setup();
	void __init__();
	void user_id();
	void controllers();
	void _init_webhooks();
	void _deinit_webhooks();
	void __str__();
	void controller_id();
	void current_schedule();
	void init_data();
	void list_zones();
	void get_zone();
	void stop_watering();
	void  post();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif