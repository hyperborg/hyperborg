/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HOMEKIT_H
#define HOMEKIT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class homekit : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "homekit.json");
    Q_INTERFACES(HyPluginInterface);
public:
    homekit(QObject *parent=nullptr);
    ~homekit();

    QString name() 		{ return "homekit"; }
    QString description()	{ return "Support for Apple HomeKit."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void handle_homekit_reset_accessory();
	void handle_homekit_service_start();
	void get_accessory();
	void generate_aid();
	void __init__();
	void setup();
	void reset_accessories();
	void add_bridge_accessory();
	void remove_bridge_accessory();
	void start();
	void stop();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif