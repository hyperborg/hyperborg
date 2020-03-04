/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DEMO_H
#define DEMO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class demo : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "demo.json");
    Q_INTERFACES(HyPluginInterface);
public:
    demo();
    ~demo();

    QString name() 		{ return "demo"; }
    QString description()	{ return "Set up the demo environment that mimics interaction with devices."; }

protected:
    	void  async_setup();
	void hue_configuration_callback();
	void  demo_start_listener();
	void  async_setup_entry();
	void  finish_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif