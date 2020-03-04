/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LOOPENERGY_H
#define LOOPENERGY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class loopenergy : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "loopenergy.json");
    Q_INTERFACES(HyPluginInterface);
public:
    loopenergy();
    ~loopenergy();

    QString name() 		{ return "loopenergy"; }
    QString description()	{ return "The loopenergy component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif