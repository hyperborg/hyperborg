/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ASTERISK_CDR_H
#define ASTERISK_CDR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class asterisk_cdr : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "asterisk_cdr.json");
    Q_INTERFACES(HyPluginInterface);
public:
    asterisk_cdr();
    ~asterisk_cdr();

    QString name() 		{ return "asterisk_cdr"; }
    QString description()	{ return "The asterisk_cdr component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif