/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VIVOTEK_H
#define VIVOTEK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class vivotek : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "vivotek.json");
    Q_INTERFACES(HyPluginInterface);
public:
    vivotek();
    ~vivotek();

    QString name() 		{ return "vivotek"; }
    QString description()	{ return "The Vivotek camera component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif