/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class template : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "template.json");
    Q_INTERFACES(HyPluginInterface);
public:
    template(QObject *parent=nullptr);
    ~template();

    QString name() 		{ return "template"; }
    QString description()	{ return "The template component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void initialise_templates();
	void extract_entities();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif