/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HISTORY_STATS_H
#define HISTORY_STATS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class history_stats : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "history_stats.json");
    Q_INTERFACES(HyPluginInterface);
public:
    history_stats();
    ~history_stats();

    QString name() 		{ return "history_stats"; }
    QString description()	{ return "The history_stats component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif