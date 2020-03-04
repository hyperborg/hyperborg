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

class viaggiatreno : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "viaggiatreno.json");
    Q_INTERFACES(HyPluginInterface);
public:
    viaggiatreno();
    ~viaggiatreno();

    QString name() 		{ return "viaggiatreno"; }
    QString description()	{ return "The viaggiatreno component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif