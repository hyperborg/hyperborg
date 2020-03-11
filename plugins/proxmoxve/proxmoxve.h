/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PROXMOXVE_H
#define PROXMOXVE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class proxmoxve : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "proxmoxve.json");
    Q_INTERFACES(HyPluginInterface);
public:
    proxmoxve(QObject *parent=nullptr);
    ~proxmoxve();

    QString name() 		{ return "proxmoxve"; }
    QString description()	{ return "Support for Proxmox VE."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void __init__();
	void build_client();
	void get_api_client();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif