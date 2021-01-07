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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class google_pubsub : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "google_pubsub.json");
    Q_INTERFACES(HyPluginInterface);
public:
    google_pubsub(QObject *parent=nullptr);
    ~google_pubsub();

    QString name() 		{ return "google_pubsub"; }
    QString description()	{ return "Support for Google Cloud Pub/Sub."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void send_to_pubsub();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif