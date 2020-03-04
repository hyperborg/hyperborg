/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SWITCHBOT_H
#define SWITCHBOT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class switchbot : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "switchbot.json");
    Q_INTERFACES(HyPluginInterface);
public:
    switchbot();
    ~switchbot();

    QString name() 		{ return "switchbot"; }
    QString description()	{ return "The switchbot component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif