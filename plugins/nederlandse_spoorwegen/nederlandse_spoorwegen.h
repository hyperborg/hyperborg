/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NEDERLANDSE_SPOORWEGEN_H
#define NEDERLANDSE_SPOORWEGEN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class nederlandse_spoorwegen : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nederlandse_spoorwegen.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nederlandse_spoorwegen();
    ~nederlandse_spoorwegen();

    QString name() 		{ return "nederlandse_spoorwegen"; }
    QString description()	{ return "The nederlandse_spoorwegen component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif