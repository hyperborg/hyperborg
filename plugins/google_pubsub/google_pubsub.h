/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GOOGLE_PUBSUB_H
#define GOOGLE_PUBSUB_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class google_pubsub : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "google_pubsub.json");
    Q_INTERFACES(HyPluginInterface);
public:
    google_pubsub();
    ~google_pubsub();

    QString name() 		{ return "google_pubsub"; }
    QString description()	{ return "Support for Google Cloud Pub/Sub."; }

protected:
    	void setup();
	void send_to_pubsub();
	void default();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif