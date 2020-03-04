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

class nuimo_controller : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nuimo_controller.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nuimo_controller();
    ~nuimo_controller();

    QString name() 		{ return "nuimo_controller"; }
    QString description()	{ return "Support for Nuimo device over Bluetooth LE."; }

protected:
    	void setup();
	void __init__();
	void received_gesture_event();
	void __init__();
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