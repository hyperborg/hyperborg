/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BROTTSPLATSKARTAN_H
#define BROTTSPLATSKARTAN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class brottsplatskartan : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "brottsplatskartan.json");
    Q_INTERFACES(HyPluginInterface);
public:
    brottsplatskartan(QObject *parent=nullptr);
    ~brottsplatskartan();

    QString name() 		{ return "brottsplatskartan"; }
    QString description()	{ return "The brottsplatskartan component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif