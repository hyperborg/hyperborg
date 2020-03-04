/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ANTHEMAV_H
#define ANTHEMAV_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class anthemav : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "anthemav.json");
    Q_INTERFACES(HyPluginInterface);
public:
    anthemav();
    ~anthemav();

    QString name() 		{ return "anthemav"; }
    QString description()	{ return "The anthemav component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif