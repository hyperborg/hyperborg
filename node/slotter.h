/*HYPERBORG SLOTTER

The main functionality of the slotter is to create a general interface for all devices connected to this node.
*/

#ifndef SLOTTER_H
#define SLOTTER_H

#include <QObject>
#include <QString>
#include <QMutex>
#include <QVector>
#include <QQuickWidget>
#include <QWaitCondition>
#include <QJsonObject>
#include <QQmlContext>
#include <QThread>
#include <QTimer>
#include <QList>
#include <QHash>
#include <QHashIterator>
#include <QQuickWidget>
#include <QByteArray>
#include <QQmlComponent>
#include <QFileSystemWatcher>
#include <QFileInfo>
#include <QQuickWindow>
#include <QQmlApplicationEngine>

#include "buffer.h"
#include "pluginslot.h"
#include "hfs.h"
#include "hyobject.h"

// For QML
#include <hudbutton.h>
#include <hudcalendar.h>
#include <hudclock.h>
#include <hudelement.h>
#include <hudeventlist.h>
#include <hudgarbage.h>
#include <hudgauge.h>
#include <hudhfstree.h>
#include <hudlibrary.h>
#include <hudlog.h>
#include <hudnavigator.h>
#include <hudpowergrid.h>
#include <hudscreen.h>
#include <hudscreenmanager.h>
#include <hudscreensaver.h>
#include <hudshoppinglist.h>
#include <hudtimetable.h>
#include <hudtodolist.h>
#include <hudweather.h>

//NI class Slotter : public QThread
class Slotter: public QObject
{
    Q_OBJECT
public:
    Slotter(HFS* hfs, QObject* parent = nullptr);
    ~Slotter();

    QWaitCondition* getWaitCondition() { return waitcondition; }
    void setInboundBuffer(PackBuffer* b)
    {
        inbound_buffer = b;
    }
    void run();
    void addPluginSlot(PluginSlot* slot)
    {
        pluginslots.append(slot);
    }

    void clearPluginSlots()
    {
        pluginslots.clear();
        // we do not destroy plugins here, nodecore should unregister their instances
    }

    // Iterate over all plugins and create all relevant entites from them
    void activatePlugins();
    const HFS* getHFS() { return hfs; }

public slots:
    void init();
    QVariant nodeRoleChanged(QVariant var);
    QVariant processTask(Job* job);

protected slots:
    void dataChangeRequest(QString path, QVariant value);
    void launchHUD();
    void loadQML();

signals:
    void newPackReady(DataPack* pack);

protected:
    void log(int severity, QString line, QString src = "SLOTTER");

    // convinience function for sending pack downward (UC) direction
    void sendPack(DataPack* pack);

    QObject* getObjectByName(QString name);
    void connectHUDtoHFS();

private:
    int processPackFromUniCore();

    // Plugin communication and relation handling
private slots:
    void datapackFromHyObj(DataPack* pack);
    void executeCommand(int cmd, DataPack* pack);
    void fileChanged(const QString& str);

signals:

private:
    HFS* hfs;
    PackBuffer* inbound_buffer;
    PackBuffer* req_buffer;
    QWaitCondition* waitcondition;
    QMutex* slotter_mutex;

    QList<PluginSlot*> pluginslots;
    QJsonObject json_config;            // Contains all plugin related configuration

    QHash<QString, QObject*> hobs;

    QObject* mainPage;
    QFileSystemWatcher* watcher;

    int last_seed;
#if 0
    QQuickWidget* qw;
#else
    QQmlApplicationEngine* qmlengine;
    QQuickWindow* qw;
#endif
};

#endif
