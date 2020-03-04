/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ALPHA_VANTAGE_H
#define ALPHA_VANTAGE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class alpha_vantage : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "alpha_vantage.json");
    Q_INTERFACES(HyPluginInterface);
public:
    alpha_vantage();
    ~alpha_vantage();

    QString name() 		{ return "alpha_vantage"; }
    QString description()	{ return "The Alpha Vantage component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif