/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TAHOMA_H
#define TAHOMA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class tahoma : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tahoma.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tahoma();
    ~tahoma();

    QString name() 		{ return "tahoma"; }
    QString description()	{ return "Support for Tahoma devices."; }

protected:
    	void setup();
	void map_tahoma_device();
	void __init__();
	void device_state_attributes();
	void apply_action();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif