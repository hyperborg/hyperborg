/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ANEL_PWRCTRL_H
#define ANEL_PWRCTRL_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class anel_pwrctrl : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "anel_pwrctrl.json");
    Q_INTERFACES(HyPluginInterface);
public:
    anel_pwrctrl();
    ~anel_pwrctrl();

    QString name() 		{ return "anel_pwrctrl"; }
    QString description()	{ return "The anel_pwrctrl component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif