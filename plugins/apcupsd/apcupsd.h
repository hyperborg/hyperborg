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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class apcupsd : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "apcupsd.json");
    Q_INTERFACES(HyPluginInterface);
public:
    apcupsd(QObject *parent=nullptr);
    ~apcupsd();

    QString name() 		{ return "apcupsd"; }
    QString description()	{ return "Support for APCUPSd via its Network Information Server (NIS)."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

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