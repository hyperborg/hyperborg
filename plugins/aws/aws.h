/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AWS_H
#define AWS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class aws : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "aws.json");
    Q_INTERFACES(HyPluginInterface);
public:
    aws();
    ~aws();

    QString name() 		{ return "aws"; }
    QString description()	{ return "Support for Amazon Web Services (AWS)."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  _validate_aws_credentials();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif