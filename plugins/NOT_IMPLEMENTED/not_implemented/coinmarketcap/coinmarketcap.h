/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef COINMARKETCAP_H
#define COINMARKETCAP_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class coinmarketcap : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "coinmarketcap.json");
    Q_INTERFACES(HyPluginInterface);
public:
    coinmarketcap(QObject *parent=nullptr);
    ~coinmarketcap();

    QString name() 		{ return "coinmarketcap"; }
    QString description()	{ return "The coinmarketcap component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif