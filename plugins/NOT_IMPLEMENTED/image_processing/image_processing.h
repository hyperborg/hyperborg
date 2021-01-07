/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class image_processing : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "image_processing.json");
    Q_INTERFACES(HyPluginInterface);
public:
    image_processing(QObject *parent=nullptr);
    ~image_processing();

    QString name() 		{ return "image_processing"; }
    QString description()	{ return "Provides functionality to interact with image processing services."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_scan_service();
	void camera_entity();
	void confidence();
	void process_image();
	void async_process_image();
	void async_update();
	void __init__();
	void state();
	void device_class();
	void state_attributes();
	void process_faces();
	void async_process_faces();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif