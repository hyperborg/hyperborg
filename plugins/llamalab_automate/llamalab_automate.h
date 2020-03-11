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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class llamalab_automate : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "llamalab_automate.json");
    Q_INTERFACES(HyPluginInterface);
public:
    llamalab_automate(QObject *parent=nullptr);
    ~llamalab_automate();

    QString name() 		{ return "llamalab_automate"; }
    QString description()	{ return "The llamalab_automate component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif