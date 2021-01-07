/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VALLOX_H
#define VALLOX_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class vallox : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "vallox.json");
    Q_INTERFACES(HyPluginInterface);
public:
    vallox(QObject *parent=nullptr);
    ~vallox();

    QString name() 		{ return "vallox"; }
    QString description()	{ return "Support for Vallox ventilation units."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void __init__();
	void fetch_metric();
	void get_profile();
	void async_update();
	void async_set_profile();
	void async_set_profile_fan_speed_home();
	void async_set_profile_fan_speed_away();
	void async_set_profile_fan_speed_boost();
	void async_handle();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif