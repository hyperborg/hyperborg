/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LG_SOUNDBAR_H
#define LG_SOUNDBAR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class lg_soundbar : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lg_soundbar.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lg_soundbar();
    ~lg_soundbar();

    QString name() 		{ return "lg_soundbar"; }
    QString description()	{ return "The lg_soundbar component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif