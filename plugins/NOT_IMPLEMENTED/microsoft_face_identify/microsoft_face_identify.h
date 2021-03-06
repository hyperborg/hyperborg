/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MICROSOFT_FACE_IDENTIFY_H
#define MICROSOFT_FACE_IDENTIFY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class microsoft_face_identify : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "microsoft_face_identify.json");
    Q_INTERFACES(HyPluginInterface);
public:
    microsoft_face_identify(QObject *parent=nullptr);
    ~microsoft_face_identify();

    QString name() 		{ return "microsoft_face_identify"; }
    QString description()	{ return "The microsoft_face_identify component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif