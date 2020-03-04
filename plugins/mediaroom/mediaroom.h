/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MEDIAROOM_H
#define MEDIAROOM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class mediaroom : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mediaroom.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mediaroom();
    ~mediaroom();

    QString name() 		{ return "mediaroom"; }
    QString description()	{ return "The mediaroom component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif