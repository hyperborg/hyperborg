/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class config : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "config.json");
    Q_INTERFACES(HyPluginInterface);
public:
    config(QObject *parent=nullptr);
    ~config();

    QString name() 		{ return "config"; }
    QString description()	{ return "Component to configure Home Assistant via an API."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void setup_panel();
	void component_loaded();
	void __init__();
	void _empty_config();
	void _get_value();
	void _write_value();
	void _delete_value();
	void post();
	void read_config();
	void _read();
	void _write();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif