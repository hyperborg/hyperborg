/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FREEBOX_H
#define FREEBOX_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class freebox : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "freebox.json");
    Q_INTERFACES(HyPluginInterface);
public:
    freebox(QObject *parent=nullptr);
    ~freebox();

    QString name() 		{ return "freebox"; }
    QString description()	{ return "Support for Freebox devices (Freebox v6 and Freebox mini 4K)."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void discovery_dispatch();
	void async_setup_freebox();
	void async_freebox_reboot();
	void close_fbx();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif