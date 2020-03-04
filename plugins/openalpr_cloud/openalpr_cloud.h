/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OPENALPR_CLOUD_H
#define OPENALPR_CLOUD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class openalpr_cloud : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "openalpr_cloud.json");
    Q_INTERFACES(HyPluginInterface);
public:
    openalpr_cloud();
    ~openalpr_cloud();

    QString name() 		{ return "openalpr_cloud"; }
    QString description()	{ return "The openalpr_cloud component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif