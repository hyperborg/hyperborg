/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TTS_H
#define TTS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class tts : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tts.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tts();
    ~tts();

    QString name() 		{ return "tts"; }
    QString description()	{ return "Provide functionality for TTS."; }

protected:
    	void _deprecated_platform();
	void  async_setup();
	void  async_setup_platform();
	void  async_say_handle();
	void  async_platform_discovered();
	void  async_clear_cache_handle();
	void __init__();
	void  async_init_cache();
	void init_tts_cache_dir();
	void get_cache_files();
	void  async_clear_cache();
	void remove_files();
	void async_register_engine();
	void  async_get_url();
	void  async_get_tts_audio();
	void  async_save_tts_audio();
	void save_speech();
	void  async_file_to_mem();
	void load_speech();
	void _async_store_to_memcache();
	void async_remove_from_mem();
	void  async_read_tts();
	void write_tags();
	void default_language();
	void supported_languages();
	void supported_options();
	void default_options();
	void get_tts_audio();
	void  async_get_tts_audio();
	void __init__();
	void  post();
	void __init__();
	void  get();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif