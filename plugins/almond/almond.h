/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ALMOND_H
#define ALMOND_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class almond : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "almond.json");
    Q_INTERFACES(HyPluginInterface);
public:
    almond(QObject *parent=nullptr);
    ~almond();

    QString name() 		{ return "almond"; }
    QString description()	{ return "Support for Almond."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_entry();
	void configure_almond();
	void almond_hass_start();
	void _configure_almond_for_ha();
	void async_unload_entry();
	void __init__();
	void async_get_access_token();
	void attribution();
	void async_get_onboarding();
	void async_set_onboarding();
	void async_process();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif