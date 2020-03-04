/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SHELL_COMMAND_H
#define SHELL_COMMAND_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class shell_command : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "shell_command.json");
    Q_INTERFACES(HyPluginInterface);
public:
    shell_command();
    ~shell_command();

    QString name() 		{ return "shell_command"; }
    QString description()	{ return "Expose regular shell commands as services."; }

protected:
    	void async_setup();
	void async_service_handler();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif