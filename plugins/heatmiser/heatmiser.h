/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HEATMISER_H
#define HEATMISER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class heatmiser : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "heatmiser.json");
    Q_INTERFACES(HyPluginInterface);
public:
    heatmiser();
    ~heatmiser();

    QString name() 		{ return "heatmiser"; }
    QString description()	{ return "The heatmiser component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif