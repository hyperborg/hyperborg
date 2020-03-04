/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HAVEIBEENPWNED_H
#define HAVEIBEENPWNED_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class haveibeenpwned : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "haveibeenpwned.json");
    Q_INTERFACES(HyPluginInterface);
public:
    haveibeenpwned();
    ~haveibeenpwned();

    QString name() 		{ return "haveibeenpwned"; }
    QString description()	{ return "The haveibeenpwned component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif