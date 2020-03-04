/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BLOOMSKY_H
#define BLOOMSKY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class bloomsky : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "bloomsky.json");
    Q_INTERFACES(HyPluginInterface);
public:
    bloomsky();
    ~bloomsky();

    QString name() 		{ return "bloomsky"; }
    QString description()	{ return "Support for BloomSky weather station."; }

protected:
    	void setup();
	void __init__();
	void refresh_devices();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif