/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ACTIONTEC_H
#define ACTIONTEC_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class actiontec : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "actiontec.json");
    Q_INTERFACES(HyPluginInterface);
public:
    actiontec();
    ~actiontec();

    QString name() 		{ return "actiontec"; }
    QString description()	{ return "The actiontec component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif