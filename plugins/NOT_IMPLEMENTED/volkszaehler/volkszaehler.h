/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VOLKSZAEHLER_H
#define VOLKSZAEHLER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class volkszaehler : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "volkszaehler.json");
    Q_INTERFACES(HyPluginInterface);
public:
    volkszaehler(QObject *parent=nullptr);
    ~volkszaehler();

    QString name() 		{ return "volkszaehler"; }
    QString description()	{ return "The volkszaehler component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif