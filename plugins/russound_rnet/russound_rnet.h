/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RUSSOUND_RNET_H
#define RUSSOUND_RNET_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class russound_rnet : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "russound_rnet.json");
    Q_INTERFACES(HyPluginInterface);
public:
    russound_rnet();
    ~russound_rnet();

    QString name() 		{ return "russound_rnet"; }
    QString description()	{ return "The russound_rnet component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif