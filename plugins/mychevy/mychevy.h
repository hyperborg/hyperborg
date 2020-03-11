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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class mychevy : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mychevy.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mychevy(QObject *parent=nullptr);
    ~mychevy();

    QString name() 		{ return "mychevy"; }
    QString description()	{ return "Support for MyChevy."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void __init__();
	void setup();
	void update();
	void get_car();
	void run();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif