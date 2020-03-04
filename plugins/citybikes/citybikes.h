/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CITYBIKES_H
#define CITYBIKES_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class citybikes : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "citybikes.json");
    Q_INTERFACES(HyPluginInterface);
public:
    citybikes();
    ~citybikes();

    QString name() 		{ return "citybikes"; }
    QString description()	{ return "The citybikes component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif