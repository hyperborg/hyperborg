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

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlField>

#include "common.h"
#include "hfsitem.h"
#include "hfs_interface.h"
#include "datapack.h"

#include "flow.h"
#include "flower.h"
#include "job.h"
#include "task.h"

#if defined(PF_WASM)
#include <emscripten/val.h>
#include <emscripten.h>
#endif

class HFSSaveRegistry
{
public:
    HFSSaveRegistry()
    {
        epoch_interval = 60;
    }
    ~HFSSaveRegistry() {}

    QString path;
    QString db_column;
    QString type;
    int     epoch_interval;
};

class HFSSaveRegistryGroup
{
public:
    HFSSaveRegistryGroup()
    {
        epoch_interval = 60;
    }
    ~HFSSaveRegistryGroup()
    {
    }

    void setDBTable(QString dbt) { db_table = dbt; }

    void addSaveRegistry(HFSSaveRegistry* reg)
    {
        entries.append(reg);
        prepareSqlCmd();
    }

    QString getSQLCmd() { return sql_cmd; }
    QStringList getPaths() { return paths_for_sql; }
    int epoch_interval;

protected:

    void prepareSqlCmd()
    {
        sql_cmd = "";
        paths_for_sql.clear();
        if (!db_table.isEmpty() && entries.count())
        {
            QStringList fields;
            for (int i = 0; i < entries.count(); ++i)
            {
                fields.append(entries.at(i)->db_column);
                paths_for_sql.append(entries.at(i)->path);
            }
            sql_cmd = "INSERT INTO " + db_table + " (" + fields.join(",") + ") VALUES (";
            fields[0] = ":" + fields.at(0);
            sql_cmd += fields.join(",:") + ")";
        }
    }

    QString db_table;
    QList<HFSSaveRegistry*> entries;
    QString sql_cmd;
    QStringList paths_for_sql;
};

class HFS : public QAbstractItemModel, public HFS_Interface
{
    Q_OBJECT
    friend class Slotter;
    friend class NodeCore;
    friend class UniCore;
    friend class CoreServer;
    friend class Flower;

public:
    static HFS *get()
    {
        static HFS instance;
        return &instance; 
    }
    HFS(HFS const&)              = delete;
    void operator=(HFS const&)   = delete;


    QVariant data(const QString &path) override;
    QObject* getObject(const QString &path) override;
    QVariant childKeys(const QString &path) override;

    virtual int dataChangeRequest(
        QObject* requester,                 // The object that is requesting the datachange, this object would be notified if
        const QString &sessionid,                  // The device_sessionid.user_sessionid combo for ACL checking
        const QString &topic,                      // The topic of which value change was requested
        QVariant val) override;             // The new requested value

    virtual QVariant getAttribute(const QString &topic, 
        const QString &attributename,
        const QVariant &defvalue =QVariant()) override;

    QString getRandomString(int length) override;

    void useConfig(QString oonfigfile);
    void addHFSSubscribes();
    bool loadBootupIni();                    // return if ini file is loaded and could define role of the node
    bool loadConfigIni(QString filename, bool clear = false);
    bool saveConfigIni();
    bool clear();                           // Drops the all entries, except the ones from the bootup.ini

    // Any device or actor could register itself to get push/pull notifications on value change
    QString provides(QObject* obj,
        const QString &topic,
        int hfs_flags           = HFS_None,
        DataType datatype       = DT_String,
        Unit unit               = NotDefined,
        const QString &regexp   = QString()
    ) override;

    bool createAlias(const QString &existing_topic, const QString &alias_topic) override;
    bool removeAlias(const QString &existing_topic, const QString &alias_topic) override;

    Flow *subscribe(QObject* obj,                                // Only used by Flower
        const QString &topic,
        const QString &funcname = QString("topicChanged"),
        const QString &keyidx = QString(),
        HFS_Subscription_Flag subflag = HFSSF_AnyValueTrigger,
        Unit unit = NotDefined
    ) override;

    void unsubscribe(QObject* obj,
        const QString &path,
        const QString &funcname = QString("topicChanged")) override;


    // Qt model related functions
    QVariant data(const QModelIndex& index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int col, const QModelIndex& parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex& index) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    // Shortcuts for frequently used functions
    QQmlPropertyMap* getPropertyMap() { return propmap; }

    Unit preferredUnit(Unit rawunit);

public slots:
    void startServices();
    void objectDeleted(QObject* obj);       // remove deleted object from all mappings
    void log(int severity, const QString &logline, const QString &source=QString("CORE")) override;
    void dumpState(QString filename);
    QJsonDocument saveAll();
    void loadAll(QJsonDocument doc);

    QVariant clearGlobals(Job* job);
    QVariant dumpState(Job* job);
    QVariant restoreState(Job* job);

protected:
    ~HFS();

    HFSItem* _hasPath(const QString &path, bool create = true, int flags = HFS_None);
    HFSItem* _createPath(const QString &path, bool do_sync = true, int flags = HFS_None);

    void setFlower(Flower* flower) { _flower = flower; }
    QStringList getSubList(const QString &path) override;
    bool setAttribute(HFSItem* item, const QString& path, QVariant value);
    bool removeAttribute(HFSItem* item, const QString& topic);
    bool removeMethod(HFSItem* item, const QString& methodName);
    int getDevIdFromPath(QString path);
    QList<HFSItem*> flatItemList();
    int getFlagsFromItem(HFSItem* item);

    QString getRelativePath(HFSItem* item);
    QString getRelativePath(QString path);
    bool isPathGlobal(HFSItem* item);
    bool isPathGlobal(QString path);

protected slots:
    void setData(QString path, QVariant data, bool do_sync = true);
    void qmlValueChanged(const QString& key, const QVariant& value);
    void scheduler_timeout();
    void directLog(QString logline);

private:
    explicit HFS(QObject* parent = nullptr);
    int obj2int(QObject* obj);      // Transferred out for possible tokenization
    void setDefaultValues();
    bool checkDataBase();

private slots:
    void fileChanged(const QString& str);
    void epochChanged(Job *job);

    void nodeRoleChanged(Job *job);
    void deviceIdChanged(Job *job);
    void deviceIdChanged(int device_id);
    void connectionStateChanged(Job *job);

    void sync(PackCommands cmd, QString topic, QVariant var);
    void sync(PackCommands cmd, QString topic, AttributeList attrs = AttributeList());


signals:
    void signal_log(int severity, QString logline, QString src);
    void signal_dataChangeRequest(QString path, QVariant value);
    void to_HFS_inBound(DataPack* pack);
    void startJob(QString name, QString topic, QVariant var);

private:
    HFSItem* rootItem;
    QString _configfile;
    QMutex mutex;
    QHash<int, QString> tokens;
    QRandomGenerator rndgen;
    QMap<int, QStringList> subscribed_cache;    //!! performance: might use pointer for list here.
    QTimer* testtimer;
    QStringList pinis;                          // Possible ini files
    QFileSystemWatcher* watcher;
    QQmlPropertyMap* propmap;
    QStringList log_cache;
   
    // SQL related
    bool db_online;
    QSqlDatabase db;
    QSqlQuery* query1;
    QSqlQuery* query_log;
    QHash<int, HFSSaveRegistryGroup*> savegroups;
    Flower* _flower;

    //Scheduler related
    QTimer* scheduler_timer;
    int     scheduler_timeout_value;
    QList<QDateTime> scheduler_skew_epoch;
    int scheduler_last_epoch;                       // last processed epoch
    QDateTime dto;
    QDateTime dtn;
    int _dayepoch;
    int _epoch;


};

#endif