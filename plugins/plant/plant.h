/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PLANT_H
#define PLANT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class plant : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "plant.json");
    Q_INTERFACES(HyPluginInterface);
public:
    plant(QObject *parent=nullptr);
    ~plant();

    QString name() 		{ return "plant"; }
    QString description()	{ return "Support for monitoring plants."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void __init__();
	void state_changed();
	void _update_state();
	void _check_min();
	void _check_max();
	void async_added_to_hass();
	void _load_history_from_db();
	void should_poll();
	void state();
	void state_attributes();
	void add_measurement();
	void _add_day();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif