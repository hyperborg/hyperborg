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

class switcher_kis : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "switcher_kis.json");
    Q_INTERFACES(HyPluginInterface);
public:
    switcher_kis();
    ~switcher_kis();

    QString name() 		{ return "switcher_kis"; }
    QString description()	{ return "Home Assistant Switcher Component."; }

protected:
    	void  _validate_edit_permission();
	void  async_setup();
	void  async_stop_bridge();
	void  async_switch_platform_discovered();
	void  async_set_auto_off_service();
	void device_updates();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif