/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SMARTY_H
#define SMARTY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class smarty : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "smarty.json");
    Q_INTERFACES(HyPluginInterface);
public:
    smarty(QObject *parent=nullptr);
    ~smarty();

    QString name() 		{ return "smarty"; }
    QString description()	{ return "Support to control a Salda Smarty XP/XV ventilation unit."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void poll_device_update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif