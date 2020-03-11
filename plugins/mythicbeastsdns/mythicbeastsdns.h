/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MYTHICBEASTSDNS_H
#define MYTHICBEASTSDNS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class mythicbeastsdns : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mythicbeastsdns.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mythicbeastsdns(QObject *parent=nullptr);
    ~mythicbeastsdns();

    QString name() 		{ return "mythicbeastsdns"; }
    QString description()	{ return "Support for Mythic Beasts Dynamic DNS service."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void update_domain_interval();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif