/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GITLAB_CI_H
#define GITLAB_CI_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class gitlab_ci : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "gitlab_ci.json");
    Q_INTERFACES(HyPluginInterface);
public:
    gitlab_ci(QObject *parent=nullptr);
    ~gitlab_ci();

    QString name() 		{ return "gitlab_ci"; }
    QString description()	{ return "The gitlab_ci component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif