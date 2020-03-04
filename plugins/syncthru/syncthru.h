/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SYNCTHRU_H
#define SYNCTHRU_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class syncthru : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "syncthru.json");
    Q_INTERFACES(HyPluginInterface);
public:
    syncthru();
    ~syncthru();

    QString name() 		{ return "syncthru"; }
    QString description()	{ return "The syncthru component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif