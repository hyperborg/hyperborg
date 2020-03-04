/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SMARTHAB_H
#define SMARTHAB_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class smarthab : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "smarthab.json");
    Q_INTERFACES(HyPluginInterface);
public:
    smarthab();
    ~smarthab();

    QString name() 		{ return "smarthab"; }
    QString description()	{ return "Support for SmartHab device integration."; }

protected:
    	void setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif