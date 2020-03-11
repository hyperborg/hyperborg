/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VICARE_H
#define VICARE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class vicare : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "vicare.json");
    Q_INTERFACES(HyPluginInterface);
public:
    vicare(QObject *parent=nullptr);
    ~vicare();

    QString name() 		{ return "vicare"; }
    QString description()	{ return "The ViCare integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif