#ifndef PLUGINSLOT_H
#define PLUGINSLOT_H

#include <QObject>
#include <QPluginLoader>
#include <QThread>
#include <QString>
#include <QFile>
#include <QDebug>

#include <hyplugin_interface.h>
#include <hdevice.h>
#include <hplugin.h>
#include <hfs.h>

// forward declaration
class HyPluginInterface;

class PluginSlot : public QObject
{
Q_OBJECT
public:
    PluginSlot(HFS* _hfs, QObject *parent=nullptr);
    ~PluginSlot();

    QString pluginName() { return _name; }
    QObject *getObject() { return nullptr; }
    bool load(QString name);
    bool init();
    bool connect();
    bool unload();
    SystemFeatures requiredFeatures();
    virtual bool setConfiguration(QJsonObject &json);

    HyPluginInterface* pluginInterface() { return _interface; }
    QObject *instance() { return _instance; }

protected slots:
    void slot_log(int severity, QString logline, QString source = QString());

signals:
    void logLine(int severity, QString logline, QString source);

private:
    QPluginLoader *pluginloader;
    QObject *_instance;
    QString _name;
    QString _configuration;
    QThread *wthread;
    QObject *_parent;
    HyPluginInterface *_interface;
    HPlugin* _plugin;
    HFS* hfs;

};

#endif