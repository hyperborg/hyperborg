/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ROUTE53_H
#define ROUTE53_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class route53 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "route53.json");
    Q_INTERFACES(HyPluginInterface);
public:
    route53();
    ~route53();

    QString name() 		{ return "route53"; }
    QString description()	{ return "Update the IP addresses of your Route53 DNS records."; }

protected:
    	void setup();
	void update_records_interval();
	void update_records_service();
	void _update_route53();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif