/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HOMEMATICIP_CLOUD_H
#define HOMEMATICIP_CLOUD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class homematicip_cloud : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "homematicip_cloud.json");
    Q_INTERFACES(HyPluginInterface);
public:
    homematicip_cloud(QObject *parent=nullptr);
    ~homematicip_cloud();

    QString name() 		{ return "homematicip_cloud"; }
    QString description()	{ return "Support for HomematicIP Cloud devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif