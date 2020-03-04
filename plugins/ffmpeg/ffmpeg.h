/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FFMPEG_H
#define FFMPEG_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ffmpeg : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ffmpeg.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ffmpeg();
    ~ffmpeg();

    QString name() 		{ return "ffmpeg"; }
    QString description()	{ return "Support for FFmpeg."; }

protected:
    	void  async_setup();
	void  async_service_handle();
	void __init__();
	void binary();
	void  async_get_version();
	void ffmpeg_stream_content_type();
	void  async_added_to_hass();
	void available();
	void should_poll();
	void  _async_start_ffmpeg();
	void  _async_stop_ffmpeg();
	void  _async_restart_ffmpeg();
	void _async_register_events();
	void  async_shutdown_handle();
	void  async_start_handle();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif