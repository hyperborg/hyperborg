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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class canary : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "canary.json");
    Q_INTERFACES(HyPluginInterface);
public:
    canary(QObject *parent=nullptr);
    ~canary();

    QString name() 		{ return "canary"; }
    QString description()	{ return "Support for Canary devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

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