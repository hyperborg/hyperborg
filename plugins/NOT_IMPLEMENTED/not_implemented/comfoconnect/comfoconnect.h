/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef COMFOCONNECT_H
#define COMFOCONNECT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class comfoconnect : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "comfoconnect.json");
    Q_INTERFACES(HyPluginInterface);
public:
    comfoconnect(QObject *parent=nullptr);
    ~comfoconnect();

    QString name() 		{ return "comfoconnect"; }
    QString description()	{ return "Support to control a Zehnder ComfoAir Q350/450/600 ventilation unit."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void _shutdown();
	void __init__();
	void connect();
	void disconnect();
	void sensor_callback();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif