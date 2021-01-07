/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SUPLA_H
#define SUPLA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class supla : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "supla.json");
    Q_INTERFACES(HyPluginInterface);
public:
    supla(QObject *parent=nullptr);
    ~supla();

    QString name() 		{ return "supla"; }
    QString description()	{ return "Support for Supla devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void discover_devices();
	void __init__();
	void server();
	void unique_id();
	void available();
	void action();
	void update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif