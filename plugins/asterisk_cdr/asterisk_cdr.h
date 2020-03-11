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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class asterisk_cdr : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "asterisk_cdr.json");
    Q_INTERFACES(HyPluginInterface);
public:
    asterisk_cdr(QObject *parent=nullptr);
    ~asterisk_cdr();

    QString name() 		{ return "asterisk_cdr"; }
    QString description()	{ return "The asterisk_cdr component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif