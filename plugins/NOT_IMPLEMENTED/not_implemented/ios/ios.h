/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IOS_H
#define IOS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class ios : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ios.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ios(QObject *parent=nullptr);
    ~ios();

    QString name() 		{ return "ios"; }
    QString description()	{ return "Native Home Assistant iOS app component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void devices_with_push();
	void enabled_push_ids();
	void devices();
	void device_name_for_push_id();
	void async_setup();
	void async_setup_entry();
	void __init__();
	void post();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif