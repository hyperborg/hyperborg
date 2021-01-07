/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SOUNDTOUCH_H
#define SOUNDTOUCH_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class soundtouch : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "soundtouch.json");
    Q_INTERFACES(HyPluginInterface);
public:
    soundtouch(QObject *parent=nullptr);
    ~soundtouch();

    QString name() 		{ return "soundtouch"; }
    QString description()	{ return "The soundtouch component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif