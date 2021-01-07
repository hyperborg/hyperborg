/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PANEL_CUSTOM_H
#define PANEL_CUSTOM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class panel_custom : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "panel_custom.json");
    Q_INTERFACES(HyPluginInterface);
public:
    panel_custom(QObject *parent=nullptr);
    ~panel_custom();

    QString name() 		{ return "panel_custom"; }
    QString description()	{ return "Register a custom front end panel."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_register_panel();
	void async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif