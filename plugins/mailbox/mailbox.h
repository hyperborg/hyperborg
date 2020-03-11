/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MAILBOX_H
#define MAILBOX_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class mailbox : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mailbox.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mailbox(QObject *parent=nullptr);
    ~mailbox();

    QString name() 		{ return "mailbox"; }
    QString description()	{ return "Support for Voice mailboxes."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_platform();
	void async_platform_discovered();
	void __init__();
	void async_added_to_hass();
	void _mailbox_updated();
	void state();
	void async_update();
	void media_type();
	void can_delete();
	void has_media();
	void async_get_media();
	void async_get_messages();
	void async_delete();
	void get_mailbox();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif