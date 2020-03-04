/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CISCO_WEBEX_TEAMS_H
#define CISCO_WEBEX_TEAMS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class cisco_webex_teams : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "cisco_webex_teams.json");
    Q_INTERFACES(HyPluginInterface);
public:
    cisco_webex_teams();
    ~cisco_webex_teams();

    QString name() 		{ return "cisco_webex_teams"; }
    QString description()	{ return "Component to integrate the Cisco Webex Teams cloud."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif