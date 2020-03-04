/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FUTURENOW_H
#define FUTURENOW_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class futurenow : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "futurenow.json");
    Q_INTERFACES(HyPluginInterface);
public:
    futurenow();
    ~futurenow();

    QString name() 		{ return "futurenow"; }
    QString description()	{ return "The futurenow component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif