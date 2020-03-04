/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DLNA_DMR_H
#define DLNA_DMR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class dlna_dmr : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dlna_dmr.json");
    Q_INTERFACES(HyPluginInterface);
public:
    dlna_dmr();
    ~dlna_dmr();

    QString name() 		{ return "dlna_dmr"; }
    QString description()	{ return "The dlna_dmr component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif