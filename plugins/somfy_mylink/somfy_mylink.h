/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SOMFY_MYLINK_H
#define SOMFY_MYLINK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class somfy_mylink : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "somfy_mylink.json");
    Q_INTERFACES(HyPluginInterface);
public:
    somfy_mylink();
    ~somfy_mylink();

    QString name() 		{ return "somfy_mylink"; }
    QString description()	{ return "Component for the Somfy MyLink device supporting the Synergy API."; }

protected:
    	void validate_entity_config();
	void async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif