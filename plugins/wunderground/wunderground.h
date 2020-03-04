/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WUNDERGROUND_H
#define WUNDERGROUND_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class wunderground : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "wunderground.json");
    Q_INTERFACES(HyPluginInterface);
public:
    wunderground();
    ~wunderground();

    QString name() 		{ return "wunderground"; }
    QString description()	{ return "The wunderground component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif