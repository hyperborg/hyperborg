/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FFMPEG_NOISE_H
#define FFMPEG_NOISE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ffmpeg_noise : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ffmpeg_noise.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ffmpeg_noise();
    ~ffmpeg_noise();

    QString name() 		{ return "ffmpeg_noise"; }
    QString description()	{ return "The ffmpeg_noise component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif