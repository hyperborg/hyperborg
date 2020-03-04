/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef EBUSD_H
#define EBUSD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ebusd : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ebusd.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ebusd();
    ~ebusd();

    QString name() 		{ return "ebusd"; }
    QString description()	{ return "Support for Ebusd daemon for communication with eBUS heating systems."; }

protected:
    	void verify_ebusd_config();
	void setup();
	void __init__();
	void update();
	void write();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif