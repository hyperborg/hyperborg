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

class amazon_polly : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "amazon_polly.json");
    Q_INTERFACES(HyPluginInterface);
public:
    amazon_polly();
    ~amazon_polly();

    QString name() 		{ return "amazon_polly"; }
    QString description()	{ return "Support for Amazon Polly integration."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif