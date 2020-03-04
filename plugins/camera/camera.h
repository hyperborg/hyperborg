/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class camera : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "camera.json");
    Q_INTERFACES(HyPluginInterface);
public:
    camera();
    ~camera();

    QString name() 		{ return "camera"; }
    QString description()	{ return "Component to interface with cameras."; }

protected:
    	void  async_request_stream();
	void  async_get_image();
	void  async_get_mjpeg_stream();
	void  async_get_still_stream();
	void  write_to_mjpeg_stream();
	void _get_camera_from_entity_id();
	void  async_setup();
	void  preload_stream();
	void update_tokens();
	void  async_setup_entry();
	void  async_unload_entry();
	void __init__();
	void should_poll();
	void entity_picture();
	void supported_features();
	void is_recording();
	void brand();
	void motion_detection_enabled();
	void model();
	void frame_interval();
	void  stream_source();
	void camera_image();
	void  async_camera_image();
	void  handle_async_still_stream();
	void  handle_async_mjpeg_stream();
	void state();
	void is_on();
	void turn_off();
	void  async_turn_off();
	void turn_on();
	void  async_turn_on();
	void enable_motion_detection();
	void async_enable_motion_detection();
	void disable_motion_detection();
	void async_disable_motion_detection();
	void state_attributes();
	void async_update_token();
	void __init__();
	void  get();
	void  handle();
	void  handle();
	void  handle();
	void  websocket_camera_thumbnail();
	void  ws_camera_stream();
	void  websocket_get_prefs();
	void  websocket_update_prefs();
	void  async_handle_snapshot_service();
	void _write_image();
	void  async_handle_play_stream_service();
	void  async_handle_record_service();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif