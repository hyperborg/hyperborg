/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WATSON_TTS_H
#define WATSON_TTS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class watson_tts : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "watson_tts.json");
    Q_INTERFACES(HyPluginInterface);
public:
    watson_tts();
    ~watson_tts();

    QString name() 		{ return "watson_tts"; }
    QString description()	{ return "Support for IBM Watson TTS integration."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif