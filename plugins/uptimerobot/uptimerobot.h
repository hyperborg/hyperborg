/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UPTIMEROBOT_H
#define UPTIMEROBOT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class uptimerobot : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "uptimerobot.json");
    Q_INTERFACES(HyPluginInterface);
public:
    uptimerobot();
    ~uptimerobot();

    QString name() 		{ return "uptimerobot"; }
    QString description()	{ return "The uptimerobot component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif