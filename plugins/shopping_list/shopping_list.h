/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class shopping_list : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "shopping_list.json");
    Q_INTERFACES(HyPluginInterface);
public:
    shopping_list();
    ~shopping_list();

    QString name() 		{ return "shopping_list"; }
    QString description()	{ return "Support to manage a shopping list."; }

protected:
    	void async_setup();
	void add_item_service();
	void complete_item_service();
	void __init__();
	void async_add();
	void async_update();
	void async_clear_completed();
	void async_load();
	void load();
	void save();
	void post();
	void websocket_handle_items();
	void websocket_handle_add();
	void websocket_handle_update();
	void websocket_handle_clear();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif