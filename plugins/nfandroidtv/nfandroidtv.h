/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NFANDROIDTV_H
#define NFANDROIDTV_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class nfandroidtv : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nfandroidtv.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nfandroidtv();
    ~nfandroidtv();

    QString name() 		{ return "nfandroidtv"; }
    QString description()	{ return "The nfandroidtv component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif