/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SYNOLOGYDSM_H
#define SYNOLOGYDSM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class synologydsm : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "synologydsm.json");
    Q_INTERFACES(HyPluginInterface);
public:
    synologydsm();
    ~synologydsm();

    QString name() 		{ return "synologydsm"; }
    QString description()	{ return "The synologydsm component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif