/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UPCLOUD_H
#define UPCLOUD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class upcloud : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "upcloud.json");
    Q_INTERFACES(HyPluginInterface);
public:
    upcloud(QObject *parent=nullptr);
    ~upcloud();

    QString name() 		{ return "upcloud"; }
    QString description()	{ return "Support for UpCloud."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void upcloud_update();
	void __init__();
	void update();
	void unique_id();
	void async_added_to_hass();
	void async_will_remove_from_hass();
	void _update_callback();
	void icon();
	void state();
	void is_on();
	void device_class();
	void device_state_attributes();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif