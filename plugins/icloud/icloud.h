/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ICLOUD_H
#define ICLOUD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class icloud : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "icloud.json");
    Q_INTERFACES(HyPluginInterface);
public:
    icloud();
    ~icloud();

    QString name() 		{ return "icloud"; }
    QString description()	{ return "The iCloud component."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void play_sound();
	void display_message();
	void lost_device();
	void update_account();
	void _get_account();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif