/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SLEEPIQ_H
#define SLEEPIQ_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class sleepiq : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sleepiq.json");
    Q_INTERFACES(HyPluginInterface);
public:
    sleepiq();
    ~sleepiq();

    QString name() 		{ return "sleepiq"; }
    QString description()	{ return "Support for SleepIQ from SleepNumber."; }

protected:
    	void setup();
	void __init__();
	void update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif