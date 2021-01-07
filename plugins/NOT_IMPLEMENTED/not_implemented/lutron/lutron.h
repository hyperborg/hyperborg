/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LUTRON_H
#define LUTRON_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class lutron : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lutron.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lutron(QObject *parent=nullptr);
    ~lutron();

    QString name() 		{ return "lutron"; }
    QString description()	{ return "Component for interacting with a Lutron RadioRA 2 system."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void __init__();
	void async_added_to_hass();
	void _update_callback();
	void should_poll();
	void button_callback();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif