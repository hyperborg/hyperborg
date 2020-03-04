/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ANDROIDTV_H
#define ANDROIDTV_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class androidtv : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "androidtv.json");
    Q_INTERFACES(HyPluginInterface);
public:
    androidtv();
    ~androidtv();

    QString name() 		{ return "androidtv"; }
    QString description()	{ return "Support for functionality to interact with Android TV/Fire TV devices."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif