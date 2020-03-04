/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BITCOIN_H
#define BITCOIN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class bitcoin : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "bitcoin.json");
    Q_INTERFACES(HyPluginInterface);
public:
    bitcoin();
    ~bitcoin();

    QString name() 		{ return "bitcoin"; }
    QString description()	{ return "The bitcoin component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif