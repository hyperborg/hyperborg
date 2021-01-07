/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef KONNECTED_H
#define KONNECTED_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class konnected : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "konnected.json");
    Q_INTERFACES(HyPluginInterface);
public:
    konnected(QObject *parent=nullptr);
    ~konnected();

    QString name() 		{ return "konnected"; }
    QString description()	{ return "Support for Konnected devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void ensure_pin();
	void ensure_zone();
	void import_validator();
	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void async_entry_updated();
	void __init__();
	void binary_value();
	void update_sensor();
	void put();
	void post();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif