/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ELIQONLINE_H
#define ELIQONLINE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class eliqonline : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "eliqonline.json");
    Q_INTERFACES(HyPluginInterface);
public:
    eliqonline();
    ~eliqonline();

    QString name() 		{ return "eliqonline"; }
    QString description()	{ return "The eliqonline component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif