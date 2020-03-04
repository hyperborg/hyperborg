/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VELUX_H
#define VELUX_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class velux : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "velux.json");
    Q_INTERFACES(HyPluginInterface);
public:
    velux();
    ~velux();

    QString name() 		{ return "velux"; }
    QString description()	{ return "Support for VELUX KLF 200 devices."; }

protected:
    	void  async_setup();
	void __init__();
	void setup();
	void  on_hass_stop();
	void  async_start();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif