/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FFMPEG_MOTION_H
#define FFMPEG_MOTION_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class ffmpeg_motion : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ffmpeg_motion.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ffmpeg_motion(QObject *parent=nullptr);
    ~ffmpeg_motion();

    QString name() 		{ return "ffmpeg_motion"; }
    QString description()	{ return "The ffmpeg_motion component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif