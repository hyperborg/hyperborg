/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LIFE360_H
#define LIFE360_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class life360 : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "life360.json");
    Q_INTERFACES(HyPluginInterface);
public:
    life360(QObject *parent=nullptr);
    ~life360();

    QString name() 		{ return "life360"; }
    QString description()	{ return "Life360 integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void _excl_incl_list_to_filter_dict();
	void _prefix();
	void _thresholds();
	void setup();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif