/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PANEL_IFRAME_H
#define PANEL_IFRAME_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class panel_iframe : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "panel_iframe.json");
    Q_INTERFACES(HyPluginInterface);
public:
    panel_iframe(QObject *parent=nullptr);
    ~panel_iframe();

    QString name() 		{ return "panel_iframe"; }
    QString description()	{ return "Register an iFrame front end panel."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif