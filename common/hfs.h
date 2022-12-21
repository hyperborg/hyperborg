#ifndef HSF_H
#define HSF_H

/* HyperBorg FileSystem
* 
* The main goal of this class to provide a virtual, distributed filesystem among all nodes
*/

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QString>
#include <QStringList>
#include <QHash>
#include <QRandomGenerator>
#include <QMap>
#include <QHash>
#include <QTimer>
#include <QElapsedTimer>
#include <QMutex>
#include <QMutexLocker>
#include <QFile>
#include <QDebug>
#include <QJsonParseError>
#include <QJsonObject>
#include <QStack>
#include <QFileSystemWatcher>
#include <QQmlPropertyMap>
#include <QThread>

#include "common.h"
#include "hfsitem.h"
#include "hfs_interface.h"

#if defined(WASM)
    #include <emscripten/val.h>
    #include <emscripten.h>
#endif

class HFS : public QAbstractItemModel, public HFS_Interface
{
    Q_OBJECT
    friend class Slotter;
    friend class NodeCore;
    friend class UniCore;
    friend class CoreServer;
    friend class HyObject;

public:
    explicit HFS(QObject* parent = nullptr);

    QVariant data(const QModelIndex& index, int role) const override;
    QVariant data(QString path) override;
    QVariant childKeys(QString path) override;
    void dataChangeRequest(QString path, QVariant val) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int col, const QModelIndex& parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex& index) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QString getRandomString(int length);

    void useConfig(QString oonfigfile);
    bool loadBootupIni();       // return if ini file is loaded and could define role of the node
    bool loadConfigIni(QString filename, bool clear=false);
    bool saveConfigIni();
    bool clear();		// Drops the all entries, except the ones from the bootup.ini

    // Any device or actor could register itself to get push/pull notifications on value change
    void subscribe(QObject *obj, QString path, QString funcname=QString("setElementProperty"), QString keyidx=QString()) override;
    void unsubscribe(QObject *obj, QString path, QString funcname=QString("setElementProperty")) override;
    QString provides(QObject *obj, QString path, int platform, QString keyidx) override;

    // Shortcuts for frequently used functions
    void log(int severity, QString logline, QString source) override;
    QQmlPropertyMap *getPropertyMap() { return propmap; }

public slots:
    void objectDeleted(QObject* obj);       // remove deleted object from all mappings

protected:
    ~HFS();
    HFSItem* _hasPath(QString path, bool create = true);
    HFSItem* _createPath(QString path);
    QStringList getSubList(QString path) override;
    void log(int severity, QString logline);
    HFSItem* addProperty(HFSItem* parent, QString prop_name, int platform=GENERAL);
    HFSItem* addMethod(QObject *obj, HFSItem* parent, QString methodName, QString keyidx=QString());

protected slots:
    void setData(QString path, QVariant data);
    void inPack(DataPack* datapack);
    void qmlValueChanged(const QString& key, const QVariant& value);

private:
    int obj2int(QObject* obj);      // Transferred out for possible tokenization 
    void setDefaultValues();

private slots:
    void heartBeatTest();                   // Does something (for test) in each second
    void fileChanged(const QString &str);

signals:
    void signal_log(int severity, QString logline, QString src);
    void signal_dataChangeRequest(QString path, QVariant value);

signals: // This one could be hacked from plugin side
    void outPack(DataPack);

private:
    HFSItem* rootItem;
    QString _configfile;
    QMutex mutex;
    QHash<int, QString> tokens;
    QHash<QString, Listener*> listeners;
    QRandomGenerator rndgen;
    QMap<int, QStringList> subscribed_cache;    //!! performance: might use pointer for list here.
    QTimer* testtimer;
    QStringList pinis;                          // Possible ini files
    QFileSystemWatcher* watcher;
    QQmlPropertyMap* propmap;
};



#endif