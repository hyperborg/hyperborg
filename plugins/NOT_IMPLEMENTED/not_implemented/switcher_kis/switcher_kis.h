/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SWITCHER_KIS_H
#define SWITCHER_KIS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class switcher_kis : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "switcher_kis.json");
    Q_INTERFACES(HyPluginInterface);
public:
    switcher_kis(QObject *parent=nullptr);
    ~switcher_kis();

    QString name() 		{ return "switcher_kis"; }
    QString description()	{ return "Home Assistant Switcher Component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void _validate_edit_permission();
	void async_setup();
	void async_stop_bridge();
	void async_switch_platform_discovered();
	void async_set_auto_off_service();
	void device_updates();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif