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

class panel_custom : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "panel_custom.json");
    Q_INTERFACES(HyPluginInterface);
public:
    panel_custom();
    ~panel_custom();

    QString name() 		{ return "panel_custom"; }
    QString description()	{ return "Register a custom front end panel."; }

protected:
    	void async_register_panel();
	void async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif