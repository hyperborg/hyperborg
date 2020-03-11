/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HOMEASSISTANT_H
#define HOMEASSISTANT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class homeassistant : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "homeassistant.json");
    Q_INTERFACES(HyPluginInterface);
public:
    homeassistant(QObject *parent=nullptr);
    ~homeassistant();

    QString name() 		{ return "homeassistant"; }
    QString description()	{ return "Integration providing core pieces of infrastructure."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_handle_turn_service();
	void async_handle_core_service();
	void async_handle_update_service();
	void async_handle_reload_config();
	void async_set_location();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif