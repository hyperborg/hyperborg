/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MAXCUBE_H
#define MAXCUBE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class maxcube : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "maxcube.json");
    Q_INTERFACES(HyPluginInterface);
public:
    maxcube();
    ~maxcube();

    QString name() 		{ return "maxcube"; }
    QString description()	{ return "Support for the MAX! Cube LAN Gateway."; }

protected:
    	void setup();
	void __init__();
	void update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif