/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BROADLINK_H
#define BROADLINK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class broadlink : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "broadlink.json");
    Q_INTERFACES(HyPluginInterface);
public:
    broadlink(QObject *parent=nullptr);
    ~broadlink();

    QString name() 		{ return "broadlink"; }
    QString description()	{ return "The broadlink component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void data_packet();
	void hostname();
	void mac_address();
	void async_setup_service();
	void _learn_command();
	void _send_packet();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif