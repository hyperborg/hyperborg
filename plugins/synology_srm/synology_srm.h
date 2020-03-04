/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SYNOLOGY_SRM_H
#define SYNOLOGY_SRM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class synology_srm : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "synology_srm.json");
    Q_INTERFACES(HyPluginInterface);
public:
    synology_srm();
    ~synology_srm();

    QString name() 		{ return "synology_srm"; }
    QString description()	{ return "The synology_srm component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif