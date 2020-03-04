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

class coinmarketcap : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "coinmarketcap.json");
    Q_INTERFACES(HyPluginInterface);
public:
    coinmarketcap();
    ~coinmarketcap();

    QString name() 		{ return "coinmarketcap"; }
    QString description()	{ return "The coinmarketcap component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif