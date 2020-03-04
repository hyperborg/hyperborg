/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class scene : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "scene.json");
    Q_INTERFACES(HyPluginInterface);
public:
    scene();
    ~scene();

    QString name() 		{ return "scene"; }
    QString description()	{ return "Allow users to set and activate scenes."; }

protected:
    	void _hass_domain_validator();
	void _platform_validator();
	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();
	void should_poll();
	void state();
	void activate();
	void  async_activate();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif