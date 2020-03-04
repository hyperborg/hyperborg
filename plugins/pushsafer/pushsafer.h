/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PUSHSAFER_H
#define PUSHSAFER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class pushsafer : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "pushsafer.json");
    Q_INTERFACES(HyPluginInterface);
public:
    pushsafer();
    ~pushsafer();

    QString name() 		{ return "pushsafer"; }
    QString description()	{ return "The pushsafer component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif