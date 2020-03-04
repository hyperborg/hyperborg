/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VERISURE_H
#define VERISURE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class verisure : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "verisure.json");
    Q_INTERFACES(HyPluginInterface);
public:
    verisure();
    ~verisure();

    QString name() 		{ return "verisure"; }
    QString description()	{ return "Support for Verisure devices."; }

protected:
    	void setup();
	void  capture_smartcam();
	void  disable_autolock();
	void  enable_autolock();
	void __init__();
	void login();
	void logout();
	void set_giid();
	void update_overview();
	void update_smartcam_imageseries();
	void smartcam_capture();
	void disable_autolock();
	void enable_autolock();
	void get_first();
	void get_image_info();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif