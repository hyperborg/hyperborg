/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CLOUDFLARE_H
#define CLOUDFLARE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class cloudflare : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "cloudflare.json");
    Q_INTERFACES(HyPluginInterface);
public:
    cloudflare(QObject *parent=nullptr);
    ~cloudflare();

    QString name() 		{ return "cloudflare"; }
    QString description()	{ return "Update the IP addresses of your Cloudflare DNS records."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void update_records_interval();
	void update_records_service();
	void _update_cloudflare();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif