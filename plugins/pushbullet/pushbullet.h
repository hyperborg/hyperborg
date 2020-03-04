/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PUSHBULLET_H
#define PUSHBULLET_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class pushbullet : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "pushbullet.json");
    Q_INTERFACES(HyPluginInterface);
public:
    pushbullet();
    ~pushbullet();

    QString name() 		{ return "pushbullet"; }
    QString description()	{ return "The pushbullet component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif