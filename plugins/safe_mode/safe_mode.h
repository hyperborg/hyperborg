/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SAFE_MODE_H
#define SAFE_MODE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class safe_mode : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "safe_mode.json");
    Q_INTERFACES(HyPluginInterface);
public:
    safe_mode();
    ~safe_mode();

    QString name() 		{ return "safe_mode"; }
    QString description()	{ return "The Safe Mode integration."; }

protected:
    	void async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif