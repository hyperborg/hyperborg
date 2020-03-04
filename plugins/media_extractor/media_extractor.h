/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MEDIA_EXTRACTOR_H
#define MEDIA_EXTRACTOR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class media_extractor : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "media_extractor.json");
    Q_INTERFACES(HyPluginInterface);
public:
    media_extractor();
    ~media_extractor();

    QString name() 		{ return "media_extractor"; }
    QString description()	{ return "Decorator service for the media_player.play_media service."; }

protected:
    	void setup();
	void play_media();
	void __init__();
	void get_media_url();
	void get_entities();
	void extract_and_send();
	void get_stream_selector();
	void stream_selector();
	void call_media_player_service();
	void get_stream_query_for_entity();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif