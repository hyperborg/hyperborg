/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TAPSAFF_H
#define TAPSAFF_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class tapsaff : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tapsaff.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tapsaff();
    ~tapsaff();

    QString name() 		{ return "tapsaff"; }
    QString description()	{ return "The tapsaff component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif