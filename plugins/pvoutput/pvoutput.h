/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PVOUTPUT_H
#define PVOUTPUT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class pvoutput : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "pvoutput.json");
    Q_INTERFACES(HyPluginInterface);
public:
    pvoutput();
    ~pvoutput();

    QString name() 		{ return "pvoutput"; }
    QString description()	{ return "The pvoutput component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif