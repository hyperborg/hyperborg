/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HOMEWORKS_H
#define HOMEWORKS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class homeworks : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "homeworks.json");
    Q_INTERFACES(HyPluginInterface);
public:
    homeworks();
    ~homeworks();

    QString name() 		{ return "homeworks"; }
    QString description()	{ return "Support for Lutron Homeworks Series 4 and 8 systems."; }

protected:
    	void setup();
	void hw_callback();
	void cleanup();
	void __init__();
	void unique_id();
	void should_poll();
	void _update_callback();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif