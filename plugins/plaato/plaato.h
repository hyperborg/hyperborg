/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PLAATO_H
#define PLAATO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class plaato : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "plaato.json");
    Q_INTERFACES(HyPluginInterface);
public:
    plaato();
    ~plaato();

    QString name() 		{ return "plaato"; }
    QString description()	{ return "Support for Plaato Airlock."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void handle_webhook();
	void _device_id();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif