/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ETHERSCAN_H
#define ETHERSCAN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class etherscan : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "etherscan.json");
    Q_INTERFACES(HyPluginInterface);
public:
    etherscan();
    ~etherscan();

    QString name() 		{ return "etherscan"; }
    QString description()	{ return "The etherscan component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif