/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef STT_H
#define STT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class stt : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "stt.json");
    Q_INTERFACES(HyPluginInterface);
public:
    stt();
    ~stt();

    QString name() 		{ return "stt"; }
    QString description()	{ return "Provide functionality to STT."; }

protected:
    	void  async_setup();
	void  async_setup_platform();
	void  async_platform_discovered();
	void supported_languages();
	void supported_formats();
	void supported_codecs();
	void supported_bit_rates();
	void supported_sample_rates();
	void supported_channels();
	void  async_process_audio_stream();
	void check_metadata();
	void __init__();
	void _metadata_from_header();
	void  post();
	void  get();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif