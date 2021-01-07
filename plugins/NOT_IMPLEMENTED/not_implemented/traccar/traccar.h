/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TRACCAR_H
#define TRACCAR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class traccar : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "traccar.json");
    Q_INTERFACES(HyPluginInterface);
public:
    traccar(QObject *parent=nullptr);
    ~traccar();

    QString name() 		{ return "traccar"; }
    QString description()	{ return "Support for Traccar."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void _id();
	void async_setup();
	void handle_webhook();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif