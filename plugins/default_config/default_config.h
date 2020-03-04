/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DEFAULT_CONFIG_H
#define DEFAULT_CONFIG_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class default_config : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "default_config.json");
    Q_INTERFACES(HyPluginInterface);
public:
    default_config();
    ~default_config();

    QString name() 		{ return "default_config"; }
    QString description()	{ return "Component providing default configuration for new users."; }

protected:
    	void async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif