/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AMAZON_POLLY_H
#define AMAZON_POLLY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class amazon_polly : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "amazon_polly.json");
    Q_INTERFACES(HyPluginInterface);
public:
    amazon_polly(QObject *parent=nullptr);
    ~amazon_polly();

    QString name() 		{ return "amazon_polly"; }
    QString description()	{ return "Support for Amazon Polly integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif