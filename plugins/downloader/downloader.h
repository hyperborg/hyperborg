/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class downloader : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "downloader.json");
    Q_INTERFACES(HyPluginInterface);
public:
    downloader();
    ~downloader();

    QString name() 		{ return "downloader"; }
    QString description()	{ return "Support for functionality to download files."; }

protected:
    	void setup();
	void download_file();
	void do_download();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif