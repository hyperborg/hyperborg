/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VOLVOONCALL_H
#define VOLVOONCALL_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class volvooncall : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "volvooncall.json");
    Q_INTERFACES(HyPluginInterface);
public:
    volvooncall(QObject *parent=nullptr);
    ~volvooncall();

    QString name() 		{ return "volvooncall"; }
    QString description()	{ return "Support for Volvo On Call."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void is_enabled();
	void discover_vehicle();
	void update();
	void __init__();
	void instrument();
	void vehicle_name();
	void async_added_to_hass();
	void icon();
	void vehicle();
	void _entity_name();
	void _vehicle_name();
	void should_poll();
	void assumed_state();
	void device_state_attributes();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif