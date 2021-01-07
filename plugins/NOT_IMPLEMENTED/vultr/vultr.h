/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VULTR_H
#define VULTR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class vultr : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "vultr.json");
    Q_INTERFACES(HyPluginInterface);
public:
    vultr(QObject *parent=nullptr);
    ~vultr();

    QString name() 		{ return "vultr"; }
    QString description()	{ return "Support for Vultr."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void __init__();
	void update();
	void _force_update();
	void halt();
	void start();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif