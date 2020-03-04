/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SPOTCRIME_H
#define SPOTCRIME_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class spotcrime : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "spotcrime.json");
    Q_INTERFACES(HyPluginInterface);
public:
    spotcrime();
    ~spotcrime();

    QString name() 		{ return "spotcrime"; }
    QString description()	{ return "The spotcrime component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif