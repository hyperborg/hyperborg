/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ADS_H
#define ADS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class ads : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ads.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ads(QObject *parent=nullptr);
    ~ads();

    QString name() 		{ return "ads"; }
    QString description()	{ return "Support for Automation Device Specification (ADS)."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void handle_write_data_by_name();
	void __init__();
	void shutdown();
	void register_device();
	void write_by_name();
	void read_by_name();
	void add_device_notification();
	void _device_notification_callback();
	void async_initialize_device();
	void update();
	void async_event_set();
	void unique_id();
	void should_poll();
	void available();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif