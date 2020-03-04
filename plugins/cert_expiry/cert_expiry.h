/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CERT_EXPIRY_H
#define CERT_EXPIRY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class cert_expiry : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "cert_expiry.json");
    Q_INTERFACES(HyPluginInterface);
public:
    cert_expiry();
    ~cert_expiry();

    QString name() 		{ return "cert_expiry"; }
    QString description()	{ return "The cert_expiry component."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif