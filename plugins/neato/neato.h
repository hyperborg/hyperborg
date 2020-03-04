/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NEATO_H
#define NEATO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class neato : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "neato.json");
    Q_INTERFACES(HyPluginInterface);
public:
    neato();
    ~neato();

    QString name() 		{ return "neato"; }
    QString description()	{ return "Support for Neato botvac connected vacuum cleaners."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void __init__();
	void login();
	void update_robots();
	void download_map();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif