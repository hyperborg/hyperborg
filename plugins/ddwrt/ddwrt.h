/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DDWRT_H
#define DDWRT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ddwrt : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ddwrt.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ddwrt();
    ~ddwrt();

    QString name() 		{ return "ddwrt"; }
    QString description()	{ return "The ddwrt component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif