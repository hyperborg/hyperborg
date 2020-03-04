/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DSMR_READER_H
#define DSMR_READER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class dsmr_reader : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dsmr_reader.json");
    Q_INTERFACES(HyPluginInterface);
public:
    dsmr_reader();
    ~dsmr_reader();

    QString name() 		{ return "dsmr_reader"; }
    QString description()	{ return "The DSMR Reader component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif