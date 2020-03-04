/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef EIGHT_SLEEP_H
#define EIGHT_SLEEP_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class eight_sleep : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "eight_sleep.json");
    Q_INTERFACES(HyPluginInterface);
public:
    eight_sleep();
    ~eight_sleep();

    QString name() 		{ return "eight_sleep"; }
    QString description()	{ return "Support for Eight smart mattress covers and mattresses."; }

protected:
    	void async_setup();
	void async_update_heat_data();
	void async_update_user_data();
	void async_service_handler();
	void stop_eight();
	void __init__();
	void async_added_to_hass();
	void async_eight_user_update();
	void should_poll();
	void async_eight_heat_update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif