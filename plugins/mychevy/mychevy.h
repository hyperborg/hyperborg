/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MYCHEVY_H
#define MYCHEVY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class mychevy : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mychevy.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mychevy();
    ~mychevy();

    QString name() 		{ return "mychevy"; }
    QString description()	{ return "Support for MyChevy."; }

protected:
    	void __init__();
	void __init__();
	void setup();
	void __init__();
	void update();
	void get_car();
	void run();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif