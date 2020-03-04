/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TADO_H
#define TADO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class tado : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tado.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tado();
    ~tado();

    QString name() 		{ return "tado"; }
    QString description()	{ return "Support for the (unofficial) Tado API."; }

protected:
    	void setup();
	void __init__();
	void fallback();
	void update();
	void update_sensor();
	void get_capabilities();
	void reset_zone_overlay();
	void set_zone_overlay();
	void set_zone_off();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif