/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SSDP_H
#define SSDP_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class ssdp : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ssdp.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ssdp(QObject *parent=nullptr);
    ~ssdp();

    QString name() 		{ return "ssdp"; }
    QString description()	{ return "The SSDP integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void initialize();
	void __init__();
	void async_scan();
	void _process_entries();
	void _process_entry();
	void _fetch_description();
	void info_from_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif