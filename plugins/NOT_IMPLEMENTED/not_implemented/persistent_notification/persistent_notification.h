/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PERSISTENT_NOTIFICATION_H
#define PERSISTENT_NOTIFICATION_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class persistent_notification : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "persistent_notification.json");
    Q_INTERFACES(HyPluginInterface);
public:
    persistent_notification(QObject *parent=nullptr);
    ~persistent_notification();

    QString name() 		{ return "persistent_notification"; }
    QString description()	{ return "Support for displaying persistent notifications."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void create();
	void dismiss();
	void async_create();
	void async_dismiss();
	void async_setup();
	void create_service();
	void dismiss_service();
	void mark_read_service();
	void websocket_get_notifications();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif