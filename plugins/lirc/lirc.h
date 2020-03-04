/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LIRC_H
#define LIRC_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class lirc : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lirc.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lirc();
    ~lirc();

    QString name() 		{ return "lirc"; }
    QString description()	{ return "Support for LIRC devices."; }

protected:
    	void setup();
	void _start_lirc();
	void _stop_lirc();
	void __init__();
	void run();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif