/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VOICERSS_H
#define VOICERSS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class voicerss : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "voicerss.json");
    Q_INTERFACES(HyPluginInterface);
public:
    voicerss();
    ~voicerss();

    QString name() 		{ return "voicerss"; }
    QString description()	{ return "Support for VoiceRSS integration."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif