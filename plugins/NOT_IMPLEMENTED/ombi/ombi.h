/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OMBI_H
#define OMBI_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class ombi : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ombi.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ombi(QObject *parent=nullptr);
    ~ombi();

    QString name() 		{ return "ombi"; }
    QString description()	{ return "Support for Ombi."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void urlbase();
	void setup();
	void submit_movie_request();
	void submit_tv_request();
	void submit_music_request();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif