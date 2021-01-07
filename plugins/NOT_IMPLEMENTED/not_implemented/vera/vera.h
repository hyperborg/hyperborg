/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VERA_H
#define VERA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class vera : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "vera.json");
    Q_INTERFACES(HyPluginInterface);
public:
    vera(QObject *parent=nullptr);
    ~vera();

    QString name() 		{ return "vera"; }
    QString description()	{ return "Support for Vera devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void stop_subscription();
	void map_vera_device();
	void __init__();
	void _update_callback();
	void should_poll();
	void device_state_attributes();
	void unique_id();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif