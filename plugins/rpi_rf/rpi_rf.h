/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RPI_RF_H
#define RPI_RF_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class rpi_rf : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rpi_rf.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rpi_rf();
    ~rpi_rf();

    QString name() 		{ return "rpi_rf"; }
    QString description()	{ return "The rpi_rf component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif