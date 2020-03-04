/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef INTESISHOME_H
#define INTESISHOME_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class intesishome : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "intesishome.json");
    Q_INTERFACES(HyPluginInterface);
public:
    intesishome();
    ~intesishome();

    QString name() 		{ return "intesishome"; }
    QString description()	{ return "Intesishome platform."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif