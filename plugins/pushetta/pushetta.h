/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PUSHETTA_H
#define PUSHETTA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class pushetta : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "pushetta.json");
    Q_INTERFACES(HyPluginInterface);
public:
    pushetta();
    ~pushetta();

    QString name() 		{ return "pushetta"; }
    QString description()	{ return "The pushetta component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif