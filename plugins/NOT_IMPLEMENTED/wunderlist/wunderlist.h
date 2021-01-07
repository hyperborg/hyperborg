/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WUNDERLIST_H
#define WUNDERLIST_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class wunderlist : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "wunderlist.json");
    Q_INTERFACES(HyPluginInterface);
public:
    wunderlist(QObject *parent=nullptr);
    ~wunderlist();

    QString name() 		{ return "wunderlist"; }
    QString description()	{ return "Support to interact with Wunderlist."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void __init__();
	void check_credentials();
	void create_task();
	void _list_by_name();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif