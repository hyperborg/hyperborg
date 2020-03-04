/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HLK_SW16_H
#define HLK_SW16_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class hlk_sw16 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hlk_sw16.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hlk_sw16();
    ~hlk_sw16();

    QString name() 		{ return "hlk_sw16"; }
    QString description()	{ return "Support for HLK-SW16 relay switches."; }

protected:
    	void async_setup();
	void add_device();
	void disconnected();
	void reconnected();
	void connect();
	void __init__();
	void handle_event_callback();
	void should_poll();
	void available();
	void _availability_callback();
	void async_added_to_hass();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif