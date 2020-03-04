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

class iperf3 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "iperf3.json");
    Q_INTERFACES(HyPluginInterface);
public:
    iperf3();
    ~iperf3();

    QString name() 		{ return "iperf3"; }
    QString description()	{ return "Support for Iperf3 network measurement tool."; }

protected:
    	void  async_setup();
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