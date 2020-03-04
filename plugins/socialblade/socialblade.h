/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SOCIALBLADE_H
#define SOCIALBLADE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class socialblade : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "socialblade.json");
    Q_INTERFACES(HyPluginInterface);
public:
    socialblade();
    ~socialblade();

    QString name() 		{ return "socialblade"; }
    QString description()	{ return "The socialblade component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif