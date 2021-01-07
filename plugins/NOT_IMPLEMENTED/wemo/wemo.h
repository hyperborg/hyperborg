/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WEMO_H
#define WEMO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class wemo : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "wemo.json");
    Q_INTERFACES(HyPluginInterface);
public:
    wemo(QObject *parent=nullptr);
    ~wemo();

    QString name() 		{ return "wemo"; }
    QString description()	{ return "Support for WeMo device discovery."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void coerce_host_port();
	void async_setup();
	void async_setup_entry();
	void stop_wemo();
	void validate_static_config();
	void setup_url_for_address();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif