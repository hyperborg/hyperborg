/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TRAFIKVERKET_TRAIN_H
#define TRAFIKVERKET_TRAIN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class trafikverket_train : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "trafikverket_train.json");
    Q_INTERFACES(HyPluginInterface);
public:
    trafikverket_train(QObject *parent=nullptr);
    ~trafikverket_train();

    QString name() 		{ return "trafikverket_train"; }
    QString description()	{ return "The trafikverket_train component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif