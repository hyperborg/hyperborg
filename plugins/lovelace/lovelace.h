/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LOVELACE_H
#define LOVELACE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class lovelace : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lovelace.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lovelace(QObject *parent=nullptr);
    ~lovelace();

    QString name() 		{ return "lovelace"; }
    QString description()	{ return "Support for the Lovelace UI."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void storage_dashboard_changed();
	void system_health_info();
	void _register_panel();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif