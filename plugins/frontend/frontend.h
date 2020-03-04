/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FRONTEND_H
#define FRONTEND_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class frontend : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "frontend.json");
    Q_INTERFACES(HyPluginInterface);
public:
    frontend();
    ~frontend();

    QString name() 		{ return "frontend"; }
    QString description()	{ return "Handle the frontend for Home Assistant."; }

protected:
    	void __init__();
	void to_response();
	void async_register_built_in_panel();
	void async_remove_panel();
	void add_extra_html_url();
	void add_extra_js_url();
	void add_manifest_json_key();
	void _frontend_root();
	void  async_setup();
	void _async_setup_themes();
	void update_theme_and_fire_event();
	void set_theme();
	void  reload_themes();
	void __init__();
	void canonical();
	void _route();
	void url_for();
	void  resolve();
	void add_prefix();
	void get_info();
	void freeze();
	void raw_match();
	void get_template();
	void  get();
	void __len__();
	void __iter__();
	void get();
	void websocket_get_panels();
	void websocket_get_themes();
	void  websocket_get_translations();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif