/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FOLDER_WATCHER_H
#define FOLDER_WATCHER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class folder_watcher : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "folder_watcher.json");
    Q_INTERFACES(HyPluginInterface);
public:
    folder_watcher();
    ~folder_watcher();

    QString name() 		{ return "folder_watcher"; }
    QString description()	{ return "Component for monitoring activity on a folder."; }

protected:
    	void setup();
	void create_event_handler();
	void __init__();
	void process();
	void on_modified();
	void on_moved();
	void on_created();
	void on_deleted();
	void startup();
	void shutdown();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif