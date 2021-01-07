/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CURRENCYLAYER_H
#define CURRENCYLAYER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class currencylayer : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "currencylayer.json");
    Q_INTERFACES(HyPluginInterface);
public:
    currencylayer(QObject *parent=nullptr);
    ~currencylayer();

    QString name() 		{ return "currencylayer"; }
    QString description()	{ return "The currencylayer component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif