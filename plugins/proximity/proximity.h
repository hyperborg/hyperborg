/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PROXIMITY_H
#define PROXIMITY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class proximity : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "proximity.json");
    Q_INTERFACES(HyPluginInterface);
public:
    proximity();
    ~proximity();

    QString name() 		{ return "proximity"; }
    QString description()	{ return "Support for tracking the proximity of a device."; }

protected:
    	void setup_proximity_component();
	void setup();
	void __init__();
	void state();
	void unit_of_measurement();
	void state_attributes();
	void check_proximity_state_change();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif