/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SOMA_H
#define SOMA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class soma : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "soma.json");
    Q_INTERFACES(HyPluginInterface);
public:
    soma();
    ~soma();

    QString name() 		{ return "soma"; }
    QString description()	{ return "Support for Soma Smartshades."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void __init__();
	void available();
	void unique_id();
	void device_info();
	void async_update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif