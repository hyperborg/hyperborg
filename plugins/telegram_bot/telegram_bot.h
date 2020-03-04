/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TELEGRAM_BOT_H
#define TELEGRAM_BOT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class telegram_bot : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "telegram_bot.json");
    Q_INTERFACES(HyPluginInterface);
public:
    telegram_bot();
    ~telegram_bot();

    QString name() 		{ return "telegram_bot"; }
    QString description()	{ return "Support to send and receive Telegram messages."; }

protected:
    	void load_data();
	void async_setup();
	void async_send_telegram_message();
	void _render_template_attr();
	void initialize_bot();
	void __init__();
	void _get_msg_ids();
	void _get_target_chat_ids();
	void _get_msg_kwargs();
	void _make_row_inline_keyboard();
	void _send_msg();
	void send_message();
	void delete_message();
	void edit_message();
	void answer_callback_query();
	void send_file();
	void send_location();
	void leave_chat();
	void _get_message_data();
	void process_message();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif