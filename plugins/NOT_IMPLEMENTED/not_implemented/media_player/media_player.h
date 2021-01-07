/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MEDIA_PLAYER_H
#define MEDIA_PLAYER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class media_player : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "media_player.json");
    Q_INTERFACES(HyPluginInterface);
public:
    media_player(QObject *parent=nullptr);
    ~media_player();

    QString name() 		{ return "media_player"; }
    QString description()	{ return "Component to interface with various media players."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void is_on();
	void _rename_keys();
	void rename();
	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void state();
	void access_token();
	void volume_level();
	void is_volume_muted();
	void media_content_id();
	void media_content_type();
	void media_duration();
	void media_position();
	void media_position_updated_at();
	void media_image_url();
	void media_image_remotely_accessible();
	void media_image_hash();
	void async_get_media_image();
	void media_title();
	void media_artist();
	void media_album_name();
	void media_album_artist();
	void media_track();
	void media_series_title();
	void media_season();
	void media_episode();
	void media_channel();
	void media_playlist();
	void app_id();
	void app_name();
	void source();
	void source_list();
	void sound_mode();
	void sound_mode_list();
	void shuffle();
	void supported_features();
	void turn_on();
	void async_turn_on();
	void turn_off();
	void async_turn_off();
	void mute_volume();
	void async_mute_volume();
	void set_volume_level();
	void async_set_volume_level();
	void media_play();
	void async_media_play();
	void media_pause();
	void async_media_pause();
	void media_stop();
	void async_media_stop();
	void media_previous_track();
	void async_media_previous_track();
	void media_next_track();
	void async_media_next_track();
	void media_seek();
	void async_media_seek();
	void play_media();
	void async_play_media();
	void select_source();
	void async_select_source();
	void select_sound_mode();
	void async_select_sound_mode();
	void clear_playlist();
	void async_clear_playlist();
	void set_shuffle();
	void async_set_shuffle();
	void support_play();
	void support_pause();
	void support_stop();
	void support_seek();
	void support_volume_set();
	void support_volume_mute();
	void support_previous_track();
	void support_next_track();
	void support_play_media();
	void support_select_source();
	void support_select_sound_mode();
	void support_clear_playlist();
	void support_shuffle_set();
	void async_toggle();
	void async_volume_up();
	void async_volume_down();
	void async_media_play_pause();
	void entity_picture();
	void capability_attributes();
	void state_attributes();
	void _async_fetch_image();
	void __init__();
	void websocket_handle_thumbnail();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif