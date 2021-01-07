/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef YANDEXTTS_H
#define YANDEXTTS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class yandextts : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "yandextts.json");
    Q_INTERFACES(HyPluginInterface);
public:
    yandextts(QObject *parent=nullptr);
    ~yandextts();

    QString name() 		{ return "yandextts"; }
    QString description()	{ return "Support for the yandex speechkit tts integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif