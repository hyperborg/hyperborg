/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UNIFILED_H
#define UNIFILED_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class unifiled : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "unifiled.json");
    Q_INTERFACES(HyPluginInterface);
public:
    unifiled();
    ~unifiled();

    QString name() 		{ return "unifiled"; }
    QString description()	{ return "Unifi LED Lights integration."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif