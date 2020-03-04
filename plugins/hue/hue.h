/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HUE_H
#define HUE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class hue : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hue.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hue();
    ~hue();

    QString name() 		{ return "hue"; }
    QString description()	{ return "Support for the Philips Hue system."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif