/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LLAMALAB_AUTOMATE_H
#define LLAMALAB_AUTOMATE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class llamalab_automate : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "llamalab_automate.json");
    Q_INTERFACES(HyPluginInterface);
public:
    llamalab_automate();
    ~llamalab_automate();

    QString name() 		{ return "llamalab_automate"; }
    QString description()	{ return "The llamalab_automate component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif