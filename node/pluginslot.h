#ifndef PLUGINSLOT_H
#define PLUGINSLOT_H

#include <QObject>
#include <QPluginLoader>
#include <QThread>
#include <QString>
#include <QFile>
#include <QDebug>

#include <hyplugin.h>

class PluginSlot : public QObject
{
Q_OBJECT
public:
    PluginSlot(QObject *parent=nullptr);
    ~PluginSlot();

    QString name() { return instance?instance->objectName():"";}
    QObject *getObject() { return NULL; }
    bool initializePlugin(QString name);
    int requiredFeatures();
    bool connectPlugin();
    bool initPlugin();

protected slots:
    void slot_log(int severity, QString logline);

private:
    QPluginLoader *pluginloader;
    QObject *instance;
    QString _name;
    QThread *wthread;
    QObject *_parent;

};

#endif