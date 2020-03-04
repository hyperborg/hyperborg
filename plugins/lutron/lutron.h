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

class lutron : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lutron.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lutron();
    ~lutron();

    QString name() 		{ return "lutron"; }
    QString description()	{ return "Component for interacting with a Lutron RadioRA 2 system."; }

protected:
    	void setup();
	void __init__();
	void  async_added_to_hass();
	void _update_callback();
	void name();
	void should_poll();
	void __init__();
	void button_callback();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif