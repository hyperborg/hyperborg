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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class sleepiq : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sleepiq.json");
    Q_INTERFACES(HyPluginInterface);
public:
    sleepiq(QObject *parent=nullptr);
    ~sleepiq();

    QString name() 		{ return "sleepiq"; }
    QString description()	{ return "Support for SleepIQ from SleepNumber."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void __init__();
	void update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif