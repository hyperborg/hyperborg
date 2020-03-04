/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HDDTEMP_H
#define HDDTEMP_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class hddtemp : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hddtemp.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hddtemp();
    ~hddtemp();

    QString name() 		{ return "hddtemp"; }
    QString description()	{ return "The hddtemp component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif