/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LOGENTRIES_H
#define LOGENTRIES_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class logentries : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "logentries.json");
    Q_INTERFACES(HyPluginInterface);
public:
    logentries(QObject *parent=nullptr);
    ~logentries();

    QString name() 		{ return "logentries"; }
    QString description()	{ return "Support for sending data to Logentries webhook endpoint."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void logentries_event_listener();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif