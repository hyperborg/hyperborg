/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef EMULATED_HUE_H
#define EMULATED_HUE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class emulated_hue : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "emulated_hue.json");
    Q_INTERFACES(HyPluginInterface);
public:
    emulated_hue(QObject *parent=nullptr);
    ~emulated_hue();

    QString name() 		{ return "emulated_hue"; }
    QString description()	{ return "Support for local control of entities by emulating a Philips Hue bridge."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void stop_emulated_hue_bridge();
	void start_emulated_hue_bridge();
	void __init__();
	void entity_id_to_number();
	void number_to_entity_id();
	void get_entity_name();
	void is_entity_exposed();
	void _load_json();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif