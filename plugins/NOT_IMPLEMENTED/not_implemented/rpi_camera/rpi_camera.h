/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RPI_CAMERA_H
#define RPI_CAMERA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class rpi_camera : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rpi_camera.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rpi_camera(QObject *parent=nullptr);
    ~rpi_camera();

    QString name() 		{ return "rpi_camera"; }
    QString description()	{ return "The rpi_camera component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif