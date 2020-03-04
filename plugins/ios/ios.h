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

class ios : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ios.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ios();
    ~ios();

    QString name() 		{ return "ios"; }
    QString description()	{ return "Native Home Assistant iOS app component."; }

protected:
    	void devices_with_push();
	void enabled_push_ids();
	void devices();
	void device_name_for_push_id();
	void  async_setup();
	void  async_setup_entry();
	void __init__();
	void get();
	void __init__();
	void  post();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif