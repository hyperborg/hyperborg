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

class websocket_api : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "websocket_api.json");
    Q_INTERFACES(HyPluginInterface);
public:
    websocket_api();
    ~websocket_api();

    QString name() 		{ return "websocket_api"; }
    QString description()	{ return "WebSocket based API for Home Assistant."; }

protected:
    	void async_register_command();
	void  async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif