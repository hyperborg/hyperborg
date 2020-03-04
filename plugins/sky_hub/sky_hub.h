/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SKY_HUB_H
#define SKY_HUB_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class sky_hub : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sky_hub.json");
    Q_INTERFACES(HyPluginInterface);
public:
    sky_hub();
    ~sky_hub();

    QString name() 		{ return "sky_hub"; }
    QString description()	{ return "The sky_hub component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif