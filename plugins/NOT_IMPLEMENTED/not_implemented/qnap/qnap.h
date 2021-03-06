/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef QNAP_H
#define QNAP_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class qnap : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "qnap.json");
    Q_INTERFACES(HyPluginInterface);
public:
    qnap(QObject *parent=nullptr);
    ~qnap();

    QString name() 		{ return "qnap"; }
    QString description()	{ return "The qnap component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif