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

class brottsplatskartan : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "brottsplatskartan.json");
    Q_INTERFACES(HyPluginInterface);
public:
    brottsplatskartan();
    ~brottsplatskartan();

    QString name() 		{ return "brottsplatskartan"; }
    QString description()	{ return "The brottsplatskartan component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif