/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VIAGGIATRENO_H
#define VIAGGIATRENO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class viaggiatreno : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "viaggiatreno.json");
    Q_INTERFACES(HyPluginInterface);
public:
    viaggiatreno(QObject *parent=nullptr);
    ~viaggiatreno();

    QString name() 		{ return "viaggiatreno"; }
    QString description()	{ return "The viaggiatreno component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif