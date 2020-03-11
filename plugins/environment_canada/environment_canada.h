/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ENVIRONMENT_CANADA_H
#define ENVIRONMENT_CANADA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class environment_canada : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "environment_canada.json");
    Q_INTERFACES(HyPluginInterface);
public:
    environment_canada(QObject *parent=nullptr);
    ~environment_canada();

    QString name() 		{ return "environment_canada"; }
    QString description()	{ return "A component for Environment Canada weather."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif