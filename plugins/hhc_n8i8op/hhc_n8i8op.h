#ifndef hhc_n8i8op_H
#define hhc_n8i8op_H

#include <hyplugin.h>
#include <hyobject.h>

#include <QString>
#include <QObject>
#include <QList>
#include <QDebug>
#include <QFile>
#include <QDir>

class hhc_n8i8op : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hhc_n8i8op.json");
    Q_INTERFACES(HyPluginInterface);

public:
    hhc_n8i8op(QObject *parent=nullptr);
    ~hhc_n8i8op();
    QObject *getObject() { return this; };

    QString name() { return "hhc_n8i8op"; }
    QString description() { return "HHC-N8I8OP driver"; }
    int implementation() { return Developement; }

    void init();

protected:

private:

};


#endif