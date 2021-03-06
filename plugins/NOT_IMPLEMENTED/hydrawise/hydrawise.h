/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HYDRAWISE_H
#define HYDRAWISE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class hydrawise : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hydrawise.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hydrawise(QObject *parent=nullptr);
    ~hydrawise();

    QString name() 		{ return "hydrawise"; }
    QString description()	{ return "Support for Hydrawise cloud."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void hub_refresh();
	void __init__();
	void async_added_to_hass();
	void _update_callback();
	void unit_of_measurement();
	void device_state_attributes();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif