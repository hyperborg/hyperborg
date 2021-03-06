/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SATEL_INTEGRA_H
#define SATEL_INTEGRA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class satel_integra : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "satel_integra.json");
    Q_INTERFACES(HyPluginInterface);
public:
    satel_integra(QObject *parent=nullptr);
    ~satel_integra();

    QString name() 		{ return "satel_integra"; }
    QString description()	{ return "Support for Satel Integra devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void is_alarm_code_necessary();
	void async_setup();
	void _close();
	void alarm_status_update_callback();
	void zones_update_callback();
	void outputs_update_callback();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif