/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef APPLE_TV_H
#define APPLE_TV_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class apple_tv : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "apple_tv.json");
    Q_INTERFACES(HyPluginInterface);
public:
    apple_tv(QObject *parent=nullptr);
    ~apple_tv();

    QString name() 		{ return "apple_tv"; }
    QString description()	{ return "Support for Apple TV."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void ensure_list();
	void request_configuration();
	void configuration_callback();
	void scan_apple_tvs();
	void async_setup();
	void async_service_handler();
	void atv_discovered();
	void _setup_atv();
	void __init__();
	void init();
	void turned_on();
	void set_power_on();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif