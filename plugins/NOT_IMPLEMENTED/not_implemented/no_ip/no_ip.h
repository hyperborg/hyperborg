/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NO_IP_H
#define NO_IP_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class no_ip : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "no_ip.json");
    Q_INTERFACES(HyPluginInterface);
public:
    no_ip(QObject *parent=nullptr);
    ~no_ip();

    QString name() 		{ return "no_ip"; }
    QString description()	{ return "Integrate with NO-IP Dynamic DNS service."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void update_domain_interval();
	void _update_no_ip();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif