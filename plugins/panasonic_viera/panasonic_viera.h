/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PANASONIC_VIERA_H
#define PANASONIC_VIERA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class panasonic_viera : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "panasonic_viera.json");
    Q_INTERFACES(HyPluginInterface);
public:
    panasonic_viera();
    ~panasonic_viera();

    QString name() 		{ return "panasonic_viera"; }
    QString description()	{ return "The panasonic_viera component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif