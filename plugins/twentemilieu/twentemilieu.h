/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TWENTEMILIEU_H
#define TWENTEMILIEU_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class twentemilieu : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "twentemilieu.json");
    Q_INTERFACES(HyPluginInterface);
public:
    twentemilieu();
    ~twentemilieu();

    QString name() 		{ return "twentemilieu"; }
    QString description()	{ return "Support for Twente Milieu."; }

protected:
    	void _update_twentemilieu();
	void async_setup();
	void update();
	void async_setup_entry();
	void _interval_update();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif