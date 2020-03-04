/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TRADFRI_H
#define TRADFRI_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class tradfri : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tradfri.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tradfri();
    ~tradfri();

    QString name() 		{ return "tradfri"; }
    QString description()	{ return "Support for IKEA Tradfri."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void on_hass_stop();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif