/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef EPSONWORKFORCE_H
#define EPSONWORKFORCE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class epsonworkforce : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "epsonworkforce.json");
    Q_INTERFACES(HyPluginInterface);
public:
    epsonworkforce();
    ~epsonworkforce();

    QString name() 		{ return "epsonworkforce"; }
    QString description()	{ return "The epsonworkforce component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif