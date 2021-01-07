/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PLUM_LIGHTPAD_H
#define PLUM_LIGHTPAD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class plum_lightpad : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "plum_lightpad.json");
    Q_INTERFACES(HyPluginInterface);
public:
    plum_lightpad(QObject *parent=nullptr);
    ~plum_lightpad();

    QString name() 		{ return "plum_lightpad"; }
    QString description()	{ return "Support for Plum Lightpad devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void cleanup();
	void new_load();
	void new_lightpad();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif