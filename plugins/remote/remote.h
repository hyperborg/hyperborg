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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class remote : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "remote.json");
    Q_INTERFACES(HyPluginInterface);
public:
    remote(QObject *parent=nullptr);
    ~remote();

    QString name() 		{ return "remote"; }
    QString description()	{ return "Support to interface with universal remote control devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

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