/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GLANCES_H
#define GLANCES_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class glances : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "glances.json");
    Q_INTERFACES(HyPluginInterface);
public:
    glances(QObject *parent=nullptr);
    ~glances();

    QString name() 		{ return "glances"; }
    QString description()	{ return "The Glances component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void __init__();
	void host();
	void async_update();
	void add_options();
	void set_scan_interval();
	void refresh();
	void async_options_updated();
	void get_api();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif