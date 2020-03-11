/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WEBSOCKET_API_H
#define WEBSOCKET_API_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class websocket_api : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "websocket_api.json");
    Q_INTERFACES(HyPluginInterface);
public:
    websocket_api(QObject *parent=nullptr);
    ~websocket_api();

    QString name() 		{ return "websocket_api"; }
    QString description()	{ return "WebSocket based API for Home Assistant."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_register_command();
	void async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif