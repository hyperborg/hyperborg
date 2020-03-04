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

class plum_lightpad : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "plum_lightpad.json");
    Q_INTERFACES(HyPluginInterface);
public:
    plum_lightpad();
    ~plum_lightpad();

    QString name() 		{ return "plum_lightpad"; }
    QString description()	{ return "Support for Plum Lightpad devices."; }

protected:
    	void  async_setup();
	void cleanup();
	void  new_load();
	void  new_lightpad();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif