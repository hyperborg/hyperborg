/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SIGHTHOUND_H
#define SIGHTHOUND_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class sighthound : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sighthound.json");
    Q_INTERFACES(HyPluginInterface);
public:
    sighthound();
    ~sighthound();

    QString name() 		{ return "sighthound"; }
    QString description()	{ return "The sighthound integration."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif