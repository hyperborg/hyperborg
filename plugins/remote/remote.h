/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef REMOTE_H
#define REMOTE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class remote : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "remote.json");
    Q_INTERFACES(HyPluginInterface);
public:
    remote();
    ~remote();

    QString name() 		{ return "remote"; }
    QString description()	{ return "Support to interface with universal remote control devices."; }

protected:
    	void is_on();
	void async_setup();
	void supported_features();
	void send_command();
	void async_send_command();
	void learn_command();
	void async_learn_command();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif