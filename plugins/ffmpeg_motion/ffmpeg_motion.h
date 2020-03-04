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

class ffmpeg_motion : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ffmpeg_motion.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ffmpeg_motion();
    ~ffmpeg_motion();

    QString name() 		{ return "ffmpeg_motion"; }
    QString description()	{ return "The ffmpeg_motion component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif