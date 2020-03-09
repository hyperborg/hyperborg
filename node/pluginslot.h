#ifndef PLUGINSLOT_H
#define PLUGINSLOT_H

#include <QObject>
#include <QPluginLoader>
#include <QThread>
#include <QString>
#include <QFile>


class PluginSlot : public QObject
{
Q_OBJECT
public:
    PluginSlot(QObject *parent=nullptr);
    ~PluginSlot();

    QString name() { return _name;}
    QObject *getObject() { return NULL; }

private:
    QPluginLoader *pluginloader;
    QObject *object;
    QString _name;

};

#endif