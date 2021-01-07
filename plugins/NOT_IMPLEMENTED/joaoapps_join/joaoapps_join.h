/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef JOAOAPPS_JOIN_H
#define JOAOAPPS_JOIN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class joaoapps_join : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "joaoapps_join.json");
    Q_INTERFACES(HyPluginInterface);
public:
    joaoapps_join(QObject *parent=nullptr);
    ~joaoapps_join();

    QString name() 		{ return "joaoapps_join"; }
    QString description()	{ return "Support for Joaoapps Join services."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void register_device();
	void ring_service();
	void set_wallpaper_service();
	void send_file_service();
	void send_url_service();
	void send_tasker_service();
	void send_sms_service();
	void setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif