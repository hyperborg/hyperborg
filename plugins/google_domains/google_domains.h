/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GOOGLE_DOMAINS_H
#define GOOGLE_DOMAINS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class google_domains : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "google_domains.json");
    Q_INTERFACES(HyPluginInterface);
public:
    google_domains();
    ~google_domains();

    QString name() 		{ return "google_domains"; }
    QString description()	{ return "Support for Google Domains."; }

protected:
    	void  async_setup();
	void  update_domain_interval();
	void  _update_google_domains();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif