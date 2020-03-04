/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SUREPETCARE_H
#define SUREPETCARE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class surepetcare : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "surepetcare.json");
    Q_INTERFACES(HyPluginInterface);
public:
    surepetcare();
    ~surepetcare();

    QString name() 		{ return "surepetcare"; }
    QString description()	{ return "Support for Sure Petcare cat/pet flaps."; }

protected:
    	void async_setup();
	void __init__();
	void async_update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif