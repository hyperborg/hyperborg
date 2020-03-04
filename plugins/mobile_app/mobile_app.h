/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MOBILE_APP_H
#define MOBILE_APP_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class mobile_app : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mobile_app.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mobile_app();
    ~mobile_app();

    QString name() 		{ return "mobile_app"; }
    QString description()	{ return "Integrates Native Apps to Home Assistant."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void async_remove_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif