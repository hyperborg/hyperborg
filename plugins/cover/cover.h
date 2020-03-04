/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef COVER_H
#define COVER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class cover : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "cover.json");
    Q_INTERFACES(HyPluginInterface);
public:
    cover();
    ~cover();

    QString name() 		{ return "cover"; }
    QString description()	{ return "Support for Cover devices."; }

protected:
    	void is_closed();
	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void current_cover_position();
	void current_cover_tilt_position();
	void state();
	void state_attributes();
	void supported_features();
	void is_opening();
	void is_closing();
	void open_cover();
	void async_open_cover();
	void close_cover();
	void async_close_cover();
	void toggle();
	void async_toggle();
	void set_cover_position();
	void async_set_cover_position();
	void stop_cover();
	void async_stop_cover();
	void open_cover_tilt();
	void async_open_cover_tilt();
	void close_cover_tilt();
	void async_close_cover_tilt();
	void set_cover_tilt_position();
	void async_set_cover_tilt_position();
	void stop_cover_tilt();
	void async_stop_cover_tilt();
	void toggle_tilt();
	void async_toggle_tilt();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif