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

class konnected : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "konnected.json");
    Q_INTERFACES(HyPluginInterface);
public:
    konnected();
    ~konnected();

    QString name() 		{ return "konnected"; }
    QString description()	{ return "Support for Konnected devices."; }

protected:
    	void ensure_pin();
	void ensure_zone();
	void import_validator();
	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();
	void  async_entry_updated();
	void __init__();
	void binary_value();
	void  update_sensor();
	void  get();
	void  put();
	void  post();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif