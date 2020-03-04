/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef XIAOMI_TV_H
#define XIAOMI_TV_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class xiaomi_tv : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "xiaomi_tv.json");
    Q_INTERFACES(HyPluginInterface);
public:
    xiaomi_tv();
    ~xiaomi_tv();

    QString name() 		{ return "xiaomi_tv"; }
    QString description()	{ return "The xiaomi_tv component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif