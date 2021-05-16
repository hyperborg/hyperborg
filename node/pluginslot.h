#ifndef PLUGINSLOT_H
#define PLUGINSLOT_H

#include <QObject>
#include <QPluginLoader>
#include <QThread>
#include <QString>
#include <QFile>
#include <QDebug>

#include <hyplugin.h>

// forward declaration
class HyPluginInterface;

class PluginSlot : public QObject
{
Q_OBJECT
public:
    PluginSlot(QObject *parent=nullptr);
    ~PluginSlot();

    QString pluginName() { return _name; }
    QObject *getObject() { return NULL; }
    bool initializePlugin(QString name);
    int requiredFeatures();
    bool connectPlugin();
    bool initPlugin();
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
    QThread *wthread;
    QObject *_parent;
    HyPluginInterface *_interface;

};

#endif