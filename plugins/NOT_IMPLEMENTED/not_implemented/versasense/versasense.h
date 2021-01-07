/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VERSASENSE_H
#define VERSASENSE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class versasense : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "versasense.json");
    Q_INTERFACES(HyPluginInterface);
public:
    versasense(QObject *parent=nullptr);
    ~versasense();

    QString name() 		{ return "versasense"; }
    QString description()	{ return "Support for VersaSense MicroPnP devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void _configure_entities();
	void _add_entity_info_to_list();
	void _load_platform();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif