/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IOTA_H
#define IOTA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class iota : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "iota.json");
    Q_INTERFACES(HyPluginInterface);
public:
    iota();
    ~iota();

    QString name() 		{ return "iota"; }
    QString description()	{ return "Support for IOTA wallets."; }

protected:
    	void setup();
	void __init__();
	void device_state_attributes();
	void api();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif