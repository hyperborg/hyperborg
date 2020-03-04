/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MITEMP_BT_H
#define MITEMP_BT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class mitemp_bt : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mitemp_bt.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mitemp_bt();
    ~mitemp_bt();

    QString name() 		{ return "mitemp_bt"; }
    QString description()	{ return "The mitemp_bt component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif