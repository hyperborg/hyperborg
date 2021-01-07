/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef REST_COMMAND_H
#define REST_COMMAND_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class rest_command : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rest_command.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rest_command(QObject *parent=nullptr);
    ~rest_command();

    QString name() 		{ return "rest_command"; }
    QString description()	{ return "Support for exposing regular REST commands as services."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_register_rest_command();
	void async_service_handler();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif