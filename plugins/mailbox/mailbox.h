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

class mailbox : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mailbox.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mailbox();
    ~mailbox();

    QString name() 		{ return "mailbox"; }
    QString description()	{ return "Support for Voice mailboxes."; }

protected:
    	void  async_setup();
	void  async_setup_platform();
	void  async_platform_discovered();
	void __init__();
	void  async_added_to_hass();
	void _mailbox_updated();
	void state();
	void name();
	void  async_update();
	void __init__();
	void async_update();
	void media_type();
	void can_delete();
	void has_media();
	void  async_get_media();
	void  async_get_messages();
	void  async_delete();
	void __init__();
	void get_mailbox();
	void  get();
	void  get();
	void  delete();
	void  get();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif