/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef STARLINGBANK_H
#define STARLINGBANK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class starlingbank : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "starlingbank.json");
    Q_INTERFACES(HyPluginInterface);
public:
    starlingbank();
    ~starlingbank();

    QString name() 		{ return "starlingbank"; }
    QString description()	{ return "The starlingbank component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif