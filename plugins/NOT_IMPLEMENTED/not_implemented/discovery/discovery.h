/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DISCOVERY_H
#define DISCOVERY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class discovery : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "discovery.json");
    Q_INTERFACES(HyPluginInterface);
public:
    discovery(QObject *parent=nullptr);
    ~discovery();

    QString name() 		{ return "discovery"; }
    QString description()	{ return ""; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void new_service_found();
	void scan_devices();
	void schedule_first();
	void _discover();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif