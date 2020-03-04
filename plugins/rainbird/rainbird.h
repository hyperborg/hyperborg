/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RAINBIRD_H
#define RAINBIRD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class rainbird : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rainbird.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rainbird();
    ~rainbird();

    QString name() 		{ return "rainbird"; }
    QString description()	{ return "Support for Rain Bird Irrigation system LNK WiFi Module."; }

protected:
    	void setup();
	void _setup_controller();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif