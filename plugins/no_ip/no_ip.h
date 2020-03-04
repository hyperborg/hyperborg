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

class no_ip : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "no_ip.json");
    Q_INTERFACES(HyPluginInterface);
public:
    no_ip();
    ~no_ip();

    QString name() 		{ return "no_ip"; }
    QString description()	{ return "Integrate with NO-IP Dynamic DNS service."; }

protected:
    	void async_setup();
	void update_domain_interval();
	void _update_no_ip();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif