/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SIMPLEPUSH_H
#define SIMPLEPUSH_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class simplepush : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "simplepush.json");
    Q_INTERFACES(HyPluginInterface);
public:
    simplepush();
    ~simplepush();

    QString name() 		{ return "simplepush"; }
    QString description()	{ return "The simplepush component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif