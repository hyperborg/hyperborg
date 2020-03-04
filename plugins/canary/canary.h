/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CANARY_H
#define CANARY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class canary : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "canary.json");
    Q_INTERFACES(HyPluginInterface);
public:
    canary();
    ~canary();

    QString name() 		{ return "canary"; }
    QString description()	{ return "Support for Canary devices."; }

protected:
    	void setup();
	void __init__();
	void update();
	void locations();
	void get_motion_entries();
	void get_location();
	void get_readings();
	void get_reading();
	void set_location_mode();
	void get_live_stream_session();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif