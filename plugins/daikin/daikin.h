/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DAIKIN_H
#define DAIKIN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class daikin : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "daikin.json");
    Q_INTERFACES(HyPluginInterface);
public:
    daikin(QObject *parent=nullptr);
    ~daikin();

    QString name() 		{ return "daikin"; }
    QString description()	{ return "Platform for the Daikin AC."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void daikin_api_setup();
	void __init__();
	void async_update();
	void available();
	void mac();
	void device_info();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif