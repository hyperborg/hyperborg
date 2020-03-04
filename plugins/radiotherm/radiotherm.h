/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RADIOTHERM_H
#define RADIOTHERM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class radiotherm : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "radiotherm.json");
    Q_INTERFACES(HyPluginInterface);
public:
    radiotherm();
    ~radiotherm();

    QString name() 		{ return "radiotherm"; }
    QString description()	{ return "The radiotherm component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif