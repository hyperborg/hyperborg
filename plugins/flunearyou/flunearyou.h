/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FLUNEARYOU_H
#define FLUNEARYOU_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class flunearyou : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "flunearyou.json");
    Q_INTERFACES(HyPluginInterface);
public:
    flunearyou();
    ~flunearyou();

    QString name() 		{ return "flunearyou"; }
    QString description()	{ return "The flunearyou component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif