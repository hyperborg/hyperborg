/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ANDROID_IP_WEBCAM_H
#define ANDROID_IP_WEBCAM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class android_ip_webcam : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "android_ip_webcam.json");
    Q_INTERFACES(HyPluginInterface);
public:
    android_ip_webcam();
    ~android_ip_webcam();

    QString name() 		{ return "android_ip_webcam"; }
    QString description()	{ return "Support for Android IP Webcam."; }

protected:
    	void  async_setup();
	void  async_setup_ipcamera();
	void  async_update_data();
	void __init__();
	void  async_added_to_hass();
	void async_ipcam_update();
	void should_poll();
	void available();
	void device_state_attributes();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif