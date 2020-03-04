/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HUNTERDOUGLAS_POWERVIEW_H
#define HUNTERDOUGLAS_POWERVIEW_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class hunterdouglas_powerview : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hunterdouglas_powerview.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hunterdouglas_powerview();
    ~hunterdouglas_powerview();

    QString name() 		{ return "hunterdouglas_powerview"; }
    QString description()	{ return "The hunterdouglas_powerview component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif