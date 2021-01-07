/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DLIB_FACE_DETECT_H
#define DLIB_FACE_DETECT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class dlib_face_detect : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dlib_face_detect.json");
    Q_INTERFACES(HyPluginInterface);
public:
    dlib_face_detect(QObject *parent=nullptr);
    ~dlib_face_detect();

    QString name() 		{ return "dlib_face_detect"; }
    QString description()	{ return "The dlib_face_detect component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif