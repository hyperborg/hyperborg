/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MCP23017_H
#define MCP23017_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class mcp23017 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mcp23017.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mcp23017();
    ~mcp23017();

    QString name() 		{ return "mcp23017"; }
    QString description()	{ return "Support for I2C MCP23017 chip."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif