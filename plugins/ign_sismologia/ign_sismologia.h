/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IGN_SISMOLOGIA_H
#define IGN_SISMOLOGIA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ign_sismologia : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ign_sismologia.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ign_sismologia();
    ~ign_sismologia();

    QString name() 		{ return "ign_sismologia"; }
    QString description()	{ return "The ign_sismologia component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif