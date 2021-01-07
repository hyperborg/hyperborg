/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GREENEYE_MONITOR_H
#define GREENEYE_MONITOR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class greeneye_monitor : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "greeneye_monitor.json");
    Q_INTERFACES(HyPluginInterface);
public:
    greeneye_monitor(QObject *parent=nullptr);
    ~greeneye_monitor();

    QString name() 		{ return "greeneye_monitor"; }
    QString description()	{ return "Support for monitoring a GreenEye Monitor energy monitor."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void close_server();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif