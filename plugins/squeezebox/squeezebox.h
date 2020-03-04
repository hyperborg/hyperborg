/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SQUEEZEBOX_H
#define SQUEEZEBOX_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class squeezebox : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "squeezebox.json");
    Q_INTERFACES(HyPluginInterface);
public:
    squeezebox();
    ~squeezebox();

    QString name() 		{ return "squeezebox"; }
    QString description()	{ return "The squeezebox component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif