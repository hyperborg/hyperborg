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

class yandextts : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "yandextts.json");
    Q_INTERFACES(HyPluginInterface);
public:
    yandextts();
    ~yandextts();

    QString name() 		{ return "yandextts"; }
    QString description()	{ return "Support for the yandex speechkit tts integration."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif