/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PILIGHT_H
#define PILIGHT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class pilight : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "pilight.json");
    Q_INTERFACES(HyPluginInterface);
public:
    pilight(QObject *parent=nullptr);
    ~pilight();

    QString name() 		{ return "pilight"; }
    QString description()	{ return "Component to create an interface to a Pilight daemon."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void start_pilight_client();
	void stop_pilight_client();
	void send_code();
	void handle_received_code();
	void __init__();
	void limited();
	void decorated();
	void action();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif