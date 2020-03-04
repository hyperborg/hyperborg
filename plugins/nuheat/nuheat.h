/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NUHEAT_H
#define NUHEAT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class nuheat : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nuheat.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nuheat();
    ~nuheat();

    QString name() 		{ return "nuheat"; }
    QString description()	{ return "Support for NuHeat thermostats."; }

protected:
    	void setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif