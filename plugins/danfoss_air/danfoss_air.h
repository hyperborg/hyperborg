/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DANFOSS_AIR_H
#define DANFOSS_AIR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class danfoss_air : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "danfoss_air.json");
    Q_INTERFACES(HyPluginInterface);
public:
    danfoss_air();
    ~danfoss_air();

    QString name() 		{ return "danfoss_air"; }
    QString description()	{ return "Support for Danfoss Air HRV."; }

protected:
    	void setup();
	void __init__();
	void get_value();
	void update_state();
	void update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif