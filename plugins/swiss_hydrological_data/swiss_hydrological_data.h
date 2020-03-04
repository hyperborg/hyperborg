/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SWISS_HYDROLOGICAL_DATA_H
#define SWISS_HYDROLOGICAL_DATA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class swiss_hydrological_data : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "swiss_hydrological_data.json");
    Q_INTERFACES(HyPluginInterface);
public:
    swiss_hydrological_data();
    ~swiss_hydrological_data();

    QString name() 		{ return "swiss_hydrological_data"; }
    QString description()	{ return "The swiss_hydrological_data component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif