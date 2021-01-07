/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SPEEDTESTDOTNET_H
#define SPEEDTESTDOTNET_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class speedtestdotnet : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "speedtestdotnet.json");
    Q_INTERFACES(HyPluginInterface);
public:
    speedtestdotnet(QObject *parent=nullptr);
    ~speedtestdotnet();

    QString name() 		{ return "speedtestdotnet"; }
    QString description()	{ return "Support for testing internet speed via Speedtest.net."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void update();
	void __init__();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif