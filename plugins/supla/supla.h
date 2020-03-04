/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SUPLA_H
#define SUPLA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class supla : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "supla.json");
    Q_INTERFACES(HyPluginInterface);
public:
    supla();
    ~supla();

    QString name() 		{ return "supla"; }
    QString description()	{ return "Support for Supla devices."; }

protected:
    	void setup();
	void discover_devices();
	void __init__();
	void server();
	void unique_id();
	void name();
	void available();
	void action();
	void update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif