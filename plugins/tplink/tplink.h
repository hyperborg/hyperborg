/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TPLINK_H
#define TPLINK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class tplink : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tplink.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tplink();
    ~tplink();

    QString name() 		{ return "tplink"; }
    QString description()	{ return "Component to embed TP-Link smart home devices."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif