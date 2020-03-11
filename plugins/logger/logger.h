/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class logger : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "logger.json");
    Q_INTERFACES(HyPluginInterface);
public:
    logger(QObject *parent=nullptr);
    ~logger();

    QString name() 		{ return "logger"; }
    QString description()	{ return "Support for setting the level of logging for components."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void __init__();
	void filter();
	void async_setup();
	void set_default_log_level();
	void set_log_levels();
	void async_service_handler();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif