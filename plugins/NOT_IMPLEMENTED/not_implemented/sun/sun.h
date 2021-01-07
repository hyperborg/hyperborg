/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SUN_H
#define SUN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class sun : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sun.json");
    Q_INTERFACES(HyPluginInterface);
public:
    sun(QObject *parent=nullptr);
    ~sun();

    QString name() 		{ return "sun"; }
    QString description()	{ return "Support for functionality to keep track of the sun."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void __init__();
	void update_location();
	void state();
	void state_attributes();
	void _check_event();
	void update_events();
	void update_sun_position();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif