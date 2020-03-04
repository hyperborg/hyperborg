/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DLIB_FACE_IDENTIFY_H
#define DLIB_FACE_IDENTIFY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class dlib_face_identify : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dlib_face_identify.json");
    Q_INTERFACES(HyPluginInterface);
public:
    dlib_face_identify();
    ~dlib_face_identify();

    QString name() 		{ return "dlib_face_identify"; }
    QString description()	{ return "The dlib_face_identify component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif