/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HASSIO_H
#define HASSIO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class hassio : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hassio.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hassio();
    ~hassio();

    QString name() 		{ return "hassio"; }
    QString description()	{ return "Support for Hass.io."; }

protected:
    	void get_homeassistant_version();
	void is_hassio();
	void async_setup();
	void push_config();
	void async_service_handler();
	void update_homeassistant_version();
	void async_handle_core_service();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif