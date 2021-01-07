/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NUIMO_CONTROLLER_H
#define NUIMO_CONTROLLER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class nuimo_controller : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nuimo_controller.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nuimo_controller(QObject *parent=nullptr);
    ~nuimo_controller();

    QString name() 		{ return "nuimo_controller"; }
    QString description()	{ return "Support for Nuimo device over Bluetooth LE."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void __init__();
	void received_gesture_event();
	void run();
	void stop();
	void _attach();
	void _connect();
	void handle_write_matrix();
	void discovery_started();
	void discovery_finished();
	void controller_added();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif