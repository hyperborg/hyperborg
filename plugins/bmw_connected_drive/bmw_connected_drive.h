/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BMW_CONNECTED_DRIVE_H
#define BMW_CONNECTED_DRIVE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class bmw_connected_drive : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "bmw_connected_drive.json");
    Q_INTERFACES(HyPluginInterface);
public:
    bmw_connected_drive();
    ~bmw_connected_drive();

    QString name() 		{ return "bmw_connected_drive"; }
    QString description()	{ return "Reads vehicle status from BMW connected drive portal."; }

protected:
    	void setup();
	void _update_all();
	void setup_account();
	void execute_service();
	void __init__();
	void update();
	void add_update_listener();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif