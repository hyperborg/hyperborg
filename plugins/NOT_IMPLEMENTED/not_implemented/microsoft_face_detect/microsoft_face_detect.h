/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MICROSOFT_FACE_DETECT_H
#define MICROSOFT_FACE_DETECT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class microsoft_face_detect : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "microsoft_face_detect.json");
    Q_INTERFACES(HyPluginInterface);
public:
    microsoft_face_detect(QObject *parent=nullptr);
    ~microsoft_face_detect();

    QString name() 		{ return "microsoft_face_detect"; }
    QString description()	{ return "The microsoft_face_detect component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif