/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ASTERISK_MBOX_H
#define ASTERISK_MBOX_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class asterisk_mbox : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "asterisk_mbox.json");
    Q_INTERFACES(HyPluginInterface);
public:
    asterisk_mbox(QObject *parent=nullptr);
    ~asterisk_mbox();

    QString name() 		{ return "asterisk_mbox"; }
    QString description()	{ return "Support for Asterisk Voicemail interface."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void __init__();
	void _discover_platform();
	void handle_data();
	void _request_messages();
	void _request_cdr();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif