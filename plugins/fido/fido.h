/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FIDO_H
#define FIDO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class fido : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "fido.json");
    Q_INTERFACES(HyPluginInterface);
public:
    fido();
    ~fido();

    QString name() 		{ return "fido"; }
    QString description()	{ return "The fido component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif