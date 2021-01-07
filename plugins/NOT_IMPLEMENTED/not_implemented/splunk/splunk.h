/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SPLUNK_H
#define SPLUNK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class splunk : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "splunk.json");
    Q_INTERFACES(HyPluginInterface);
public:
    splunk(QObject *parent=nullptr);
    ~splunk();

    QString name() 		{ return "splunk"; }
    QString description()	{ return "Support to send data to an Splunk instance."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void post_request();
	void setup();
	void splunk_event_listener();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif