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

class logentries : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "logentries.json");
    Q_INTERFACES(HyPluginInterface);
public:
    logentries();
    ~logentries();

    QString name() 		{ return "logentries"; }
    QString description()	{ return "Support for sending data to Logentries webhook endpoint."; }

protected:
    	void setup();
	void logentries_event_listener();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif