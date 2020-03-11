/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PI_HOLE_H
#define PI_HOLE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class pi_hole : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "pi_hole.json");
    Q_INTERFACES(HyPluginInterface);
public:
    pi_hole(QObject *parent=nullptr);
    ~pi_hole();

    QString name() 		{ return "pi_hole"; }
    QString description()	{ return "The pi_hole component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void ensure_unique_names_and_slugs();
	void coerce_slug();
	void async_setup();
	void get_data();
	void ensure_api_token();
	void disable_service_handler();
	void do_disable();
	void enable_service_handler();
	void do_enable();
	void __init__();
	void async_update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif