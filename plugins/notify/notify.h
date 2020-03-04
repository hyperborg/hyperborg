/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NOTIFY_H
#define NOTIFY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class notify : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "notify.json");
    Q_INTERFACES(HyPluginInterface);
public:
    notify();
    ~notify();

    QString name() 		{ return "notify"; }
    QString description()	{ return "Provides functionality to notify people."; }

protected:
    	void  async_setup();
	void  async_setup_platform();
	void  async_notify_message();
	void  async_platform_discovered();
	void send_message();
	void  async_send_message();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif