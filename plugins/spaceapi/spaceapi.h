/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SPACEAPI_H
#define SPACEAPI_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class spaceapi : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "spaceapi.json");
    Q_INTERFACES(HyPluginInterface);
public:
    spaceapi();
    ~spaceapi();

    QString name() 		{ return "spaceapi"; }
    QString description()	{ return "Support for the SpaceAPI."; }

protected:
    	void setup();
	void get_sensor_data();
	void get();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif