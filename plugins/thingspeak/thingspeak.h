/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef THINGSPEAK_H
#define THINGSPEAK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class thingspeak : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "thingspeak.json");
    Q_INTERFACES(HyPluginInterface);
public:
    thingspeak();
    ~thingspeak();

    QString name() 		{ return "thingspeak"; }
    QString description()	{ return "Support for submitting data to Thingspeak."; }

protected:
    	void setup();
	void thingspeak_listener();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif