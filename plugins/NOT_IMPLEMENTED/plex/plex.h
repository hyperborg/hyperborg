/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PLEX_H
#define PLEX_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class plex : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "plex.json");
    Q_INTERFACES(HyPluginInterface);
public:
    plex(QObject *parent=nullptr);
    ~plex();

    QString name() 		{ return "plex"; }
    QString description()	{ return "Support to embed Plex."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void _async_setup_plex();
	void async_setup_entry();
	void update_plex();
	void start_websocket_session();
	void close_websocket_session();
	void async_unload_entry();
	void async_options_updated();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif