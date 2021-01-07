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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class watson_tts : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "watson_tts.json");
    Q_INTERFACES(HyPluginInterface);
public:
    watson_tts(QObject *parent=nullptr);
    ~watson_tts();

    QString name() 		{ return "watson_tts"; }
    QString description()	{ return "Support for IBM Watson TTS integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif