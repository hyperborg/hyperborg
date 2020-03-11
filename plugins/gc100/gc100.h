/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GC100_H
#define GC100_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class gc100 : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "gc100.json");
    Q_INTERFACES(HyPluginInterface);
public:
    gc100(QObject *parent=nullptr);
    ~gc100();

    QString name() 		{ return "gc100"; }
    QString description()	{ return "Support for controlling Global Cache gc100."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void cleanup_gc100();
	void __init__();
	void read_sensor();
	void write_switch();
	void subscribe();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif