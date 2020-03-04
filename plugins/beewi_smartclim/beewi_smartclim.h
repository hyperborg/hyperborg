/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BEEWI_SMARTCLIM_H
#define BEEWI_SMARTCLIM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class beewi_smartclim : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "beewi_smartclim.json");
    Q_INTERFACES(HyPluginInterface);
public:
    beewi_smartclim();
    ~beewi_smartclim();

    QString name() 		{ return "beewi_smartclim"; }
    QString description()	{ return "The beewi_smartclim component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif