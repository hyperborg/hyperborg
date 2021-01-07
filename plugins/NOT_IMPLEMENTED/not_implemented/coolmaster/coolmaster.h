/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef COOLMASTER_H
#define COOLMASTER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class coolmaster : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "coolmaster.json");
    Q_INTERFACES(HyPluginInterface);
public:
    coolmaster(QObject *parent=nullptr);
    ~coolmaster();

    QString name() 		{ return "coolmaster"; }
    QString description()	{ return "The Coolmaster integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif