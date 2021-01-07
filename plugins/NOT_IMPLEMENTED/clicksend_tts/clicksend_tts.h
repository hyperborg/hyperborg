/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CLICKSEND_TTS_H
#define CLICKSEND_TTS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class clicksend_tts : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "clicksend_tts.json");
    Q_INTERFACES(HyPluginInterface);
public:
    clicksend_tts(QObject *parent=nullptr);
    ~clicksend_tts();

    QString name() 		{ return "clicksend_tts"; }
    QString description()	{ return "The clicksend_tts component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif