/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FRITZBOX_H
#define FRITZBOX_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class fritzbox : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "fritzbox.json");
    Q_INTERFACES(HyPluginInterface);
public:
    fritzbox();
    ~fritzbox();

    QString name() 		{ return "fritzbox"; }
    QString description()	{ return "Support for AVM Fritz!Box smarthome devices."; }

protected:
    	void setup();
	void logout_fritzboxes();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif