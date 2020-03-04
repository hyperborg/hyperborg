/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ENVISALINK_H
#define ENVISALINK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class envisalink : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "envisalink.json");
    Q_INTERFACES(HyPluginInterface);
public:
    envisalink();
    ~envisalink();

    QString name() 		{ return "envisalink"; }
    QString description()	{ return "Support for Envisalink devices."; }

protected:
    	void async_setup();
	void login_fail_callback();
	void connection_fail_callback();
	void connection_success_callback();
	void zones_updated_callback();
	void alarm_data_updated_callback();
	void partition_updated_callback();
	void stop_envisalink();
	void handle_custom_function();
	void __init__();
	void should_poll();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif