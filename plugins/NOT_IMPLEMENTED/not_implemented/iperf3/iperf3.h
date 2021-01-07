/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IPERF3_H
#define IPERF3_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class iperf3 : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "iperf3.json");
    Q_INTERFACES(HyPluginInterface);
public:
    iperf3(QObject *parent=nullptr);
    ~iperf3();

    QString name() 		{ return "iperf3"; }
    QString description()	{ return "Support for Iperf3 network measurement tool."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void update();
	void __init__();
	void create_client();
	void protocol();
	void host();
	void port();
	void _run_test();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif