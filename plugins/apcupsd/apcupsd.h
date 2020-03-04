/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef APCUPSD_H
#define APCUPSD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class apcupsd : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "apcupsd.json");
    Q_INTERFACES(HyPluginInterface);
public:
    apcupsd();
    ~apcupsd();

    QString name() 		{ return "apcupsd"; }
    QString description()	{ return "Support for APCUPSd via its Network Information Server (NIS)."; }

protected:
    	void setup();
	void __init__();
	void status();
	void _get_status();
	void update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif