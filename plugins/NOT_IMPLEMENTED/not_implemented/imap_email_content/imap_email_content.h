/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IMAP_EMAIL_CONTENT_H
#define IMAP_EMAIL_CONTENT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class imap_email_content : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "imap_email_content.json");
    Q_INTERFACES(HyPluginInterface);
public:
    imap_email_content(QObject *parent=nullptr);
    ~imap_email_content();

    QString name() 		{ return "imap_email_content"; }
    QString description()	{ return "The imap_email_content component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif