/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LOGI_CIRCLE_H
#define LOGI_CIRCLE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class logi_circle : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "logi_circle.json");
    Q_INTERFACES(HyPluginInterface);
public:
    logi_circle(QObject *parent=nullptr);
    ~logi_circle();

    QString name() 		{ return "logi_circle"; }
    QString description()	{ return "Support for Logi Circle devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_entry();
	void service_handler();
	void shut_down();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif