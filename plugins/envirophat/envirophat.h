/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ENVIROPHAT_H
#define ENVIROPHAT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class envirophat : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "envirophat.json");
    Q_INTERFACES(HyPluginInterface);
public:
    envirophat();
    ~envirophat();

    QString name() 		{ return "envirophat"; }
    QString description()	{ return "The envirophat component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif