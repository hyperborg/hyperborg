/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DOMINOS_H
#define DOMINOS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class dominos : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dominos.json");
    Q_INTERFACES(HyPluginInterface);
public:
    dominos();
    ~dominos();

    QString name() 		{ return "dominos"; }
    QString description()	{ return "Support for Dominos Pizza ordering."; }

protected:
    	void setup();
	void __init__();
	void handle_order();
	void update_closest_store();
	void get_menu();
	void __init__();
	void get();
	void __init__();
	void name();
	void product_codes();
	void orderable();
	void state();
	void update();
	void order();
	void place();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif