/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ZHONG_HONG_H
#define ZHONG_HONG_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class zhong_hong : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "zhong_hong.json");
    Q_INTERFACES(HyPluginInterface);
public:
    zhong_hong();
    ~zhong_hong();

    QString name() 		{ return "zhong_hong"; }
    QString description()	{ return "The zhong_hong component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif