/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MOCHAD_H
#define MOCHAD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class mochad : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mochad.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mochad(QObject *parent=nullptr);
    ~mochad();

    QString name() 		{ return "mochad"; }
    QString description()	{ return "Support for CM15A/CM19A X10 Controller using mochad daemon."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void stop_mochad();
	void start_mochad();
	void __init__();
	void host();
	void port();
	void disconnect();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif