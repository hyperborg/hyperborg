/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IHC_H
#define IHC_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class ihc : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ihc.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ihc(QObject *parent=nullptr);
    ~ihc();

    QString name() 		{ return "ihc"; }
    QString description()	{ return "Support for IHC devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void validate_name();
	void setup();
	void ihc_setup();
	void get_manual_configuration();
	void autosetup_ihc_products();
	void get_discovery_info();
	void setup_service_functions();
	void set_runtime_value_bool();
	void set_runtime_value_int();
	void set_runtime_value_float();
	void async_pulse_runtime_input();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif