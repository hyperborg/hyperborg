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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class danfoss_air : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "danfoss_air.json");
    Q_INTERFACES(HyPluginInterface);
public:
    danfoss_air(QObject *parent=nullptr);
    ~danfoss_air();

    QString name() 		{ return "danfoss_air"; }
    QString description()	{ return "Support for Danfoss Air HRV."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

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