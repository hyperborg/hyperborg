/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HP_ILO_H
#define HP_ILO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class hp_ilo : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hp_ilo.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hp_ilo();
    ~hp_ilo();

    QString name() 		{ return "hp_ilo"; }
    QString description()	{ return "The HP Integrated Lights-Out (iLO) component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif