/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VULTR_H
#define VULTR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class vultr : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "vultr.json");
    Q_INTERFACES(HyPluginInterface);
public:
    vultr();
    ~vultr();

    QString name() 		{ return "vultr"; }
    QString description()	{ return "Support for Vultr."; }

protected:
    	void setup();
	void __init__();
	void update();
	void _force_update();
	void halt();
	void start();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif