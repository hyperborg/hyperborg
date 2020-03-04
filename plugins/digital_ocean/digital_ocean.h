/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DIGITAL_OCEAN_H
#define DIGITAL_OCEAN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class digital_ocean : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "digital_ocean.json");
    Q_INTERFACES(HyPluginInterface);
public:
    digital_ocean();
    ~digital_ocean();

    QString name() 		{ return "digital_ocean"; }
    QString description()	{ return "Support for Digital Ocean."; }

protected:
    	void setup();
	void __init__();
	void get_droplet_id();
	void update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif