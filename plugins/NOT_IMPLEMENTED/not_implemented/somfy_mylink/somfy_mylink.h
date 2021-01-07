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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class somfy_mylink : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "somfy_mylink.json");
    Q_INTERFACES(HyPluginInterface);
public:
    somfy_mylink(QObject *parent=nullptr);
    ~somfy_mylink();

    QString name() 		{ return "somfy_mylink"; }
    QString description()	{ return "Component for the Somfy MyLink device supporting the Synergy API."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void validate_entity_config();
	void async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif