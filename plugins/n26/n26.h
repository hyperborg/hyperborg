/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef N26_H
#define N26_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class n26 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "n26.json");
    Q_INTERFACES(HyPluginInterface);
public:
    n26();
    ~n26();

    QString name() 		{ return "n26"; }
    QString description()	{ return "Support for N26 bank accounts."; }

protected:
    	void setup();
	void timestamp_ms_to_date();
	void __init__();
	void api();
	void account_info();
	void balance();
	void limits();
	void account_statuses();
	void cards();
	void card();
	void spaces();
	void space();
	void update_account();
	void update_cards();
	void update_spaces();
	void update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif