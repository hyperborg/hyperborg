/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef STATISTICS_H
#define STATISTICS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class statistics : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "statistics.json");
    Q_INTERFACES(HyPluginInterface);
public:
    statistics();
    ~statistics();

    QString name() 		{ return "statistics"; }
    QString description()	{ return "The statistics component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif