/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IDTECK_PROX_H
#define IDTECK_PROX_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class idteck_prox : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "idteck_prox.json");
    Q_INTERFACES(HyPluginInterface);
public:
    idteck_prox();
    ~idteck_prox();

    QString name() 		{ return "idteck_prox"; }
    QString description()	{ return "Component for interfacing RFK101 proximity card readers."; }

protected:
    	void setup();
	void __init__();
	void connect();
	void _callback();
	void stop();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif