/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class configurator : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "configurator.json");
    Q_INTERFACES(HyPluginInterface);
public:
    configurator(QObject *parent=nullptr);
    ~configurator();

    QString name() 		{ return "configurator"; }
    QString description()	{ return ""; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_request_config();
	void request_config();
	void async_notify_errors();
	void notify_errors();
	void async_request_done();
	void request_done();
	void async_setup();
	void __init__();
	void deferred_remove();
	void async_handle_service_call();
	void _generate_unique_id();
	void _validate_request_id();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif