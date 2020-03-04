/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MJPEG_H
#define MJPEG_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class mjpeg : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mjpeg.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mjpeg();
    ~mjpeg();

    QString name() 		{ return "mjpeg"; }
    QString description()	{ return "The mjpeg component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif