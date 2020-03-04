/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HIKVISIONCAM_H
#define HIKVISIONCAM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class hikvisioncam : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hikvisioncam.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hikvisioncam();
    ~hikvisioncam();

    QString name() 		{ return "hikvisioncam"; }
    QString description()	{ return "The hikvisioncam component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif