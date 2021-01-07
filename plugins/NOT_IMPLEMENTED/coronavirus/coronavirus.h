/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CORONAVIRUS_H
#define CORONAVIRUS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class coronavirus : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "coronavirus.json");
    Q_INTERFACES(HyPluginInterface);
public:
    coronavirus(QObject *parent=nullptr);
    ~coronavirus();

    QString name() 		{ return "coronavirus"; }
    QString description()	{ return "The Coronavirus integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_entry();
	void _async_migrator();
	void async_unload_entry();
	void get_coordinator();
	void async_get_cases();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif