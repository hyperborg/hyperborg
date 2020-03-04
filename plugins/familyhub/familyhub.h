/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FAMILYHUB_H
#define FAMILYHUB_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class familyhub : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "familyhub.json");
    Q_INTERFACES(HyPluginInterface);
public:
    familyhub();
    ~familyhub();

    QString name() 		{ return "familyhub"; }
    QString description()	{ return "The familyhub component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif