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

#if defined(WASM)
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
    friend class HyObject;
    friend class Flower;

public:
    explicit HFS(QObject* parent = nullptr);

    QVariant data(const QModelIndex& index, int role) const override;
    QVariant data(QString path) override;
    QVariant childKeys(QString path) override;

    virtual int dataChangeRequest(
        QObject* requester,                 // The object that is requesting the datachange, this object would be notified if
        QString sessionid,                  // The device_sessionid.user_sessionid combo for ACL checking
        QString topic,                      // The topic of which value change was requested
        QVariant val) override;             // The new requested value

    virtual QVariant getAttribute(QString topic, 
        QString attributename,
        QVariant defvalue =QVariant()) override;

    virtual QObject* getObjectAttribute(QString topic) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int col, const QModelIndex& parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex& index) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QString getRandomString(int length) override;

    void useConfig(QString oonfigfile);
    void addHFSSubscribes();
    bool loadBootupIni();                    // return if ini file is loaded and could define role of the node
    bool loadConfigIni(QString filename, bool clear = false);
    bool saveConfigIni();
    bool clear();                           // Drops the all entries, except the ones from the bootup.ini

    // Any device or actor could register itself to get push/pull notifications on value change
    QString provides(QObject* obj,
        QString topic,
        int hfs_flags = 0,
        DataType datatype = DT_String,
        Unit unit = NotDefined,
        QString regexp = QString()
    ) override;

    bool createAlias(QString existing_topic, QString alias_topic) override;
    bool removeAlias(QString existing_topic, QString alias_topic) override;

    void subscribe(QObject* obj,                                // Only used by Flower
        QString topic,
        QString funcname = QString("topicChanged"),
        QString keyidx = QString(),
        HFS_Subscription_Flag subflag = HFSSF_AnyValueTrigger,
        Unit unit = NotDefined
    ) override;

    void unsubscribe(QObject* obj,
        QString path,
        QString funcname = QString("topicChanged")) override;

    void addDBHook(QString path, QString table,
        QString columnname = QString(),                         // if left empty, it is generated from path
        DBColumnType datatype = DBF_SameAsDataType,
        int sub_precision = -1,
        int major_precision = -1
    ) override;

    void setDBHookSaveTimer(QString path, int interval = 15);   // default save interval is 15 secs
    void maintainDB();
    bool createDBColumn(QString tablename, QString columnname, int datatype, int sub_precision = -1, int major_precision = -1);
    bool modifyDBColumn(QString tablename, QString columnname, int datatype, int sub_precision = -1, int major_precision = -1);

    // Shortcuts for frequently used functions
    QQmlPropertyMap* getPropertyMap() { return propmap; }

public slots:
    void startServices();
    void objectDeleted(QObject* obj);       // remove deleted object from all mappings
    void log(int severity, QString logline, QString source) override;
    void dumpState(QString filename);
    QJsonDocument saveAll();
    void loadAll(QJsonDocument doc);

    QVariant clearGlobals(Job* job);
    QVariant dumpState(Job* job);
    QVariant restoreState(Job* job);

protected:
    ~HFS();

    HFSItem* _hasPath(QString path, bool create = true, int flags = HFS_None);
    HFSItem* _createPath(QString path, bool do_sync = true, int flags = HFS_None);

    void setFlower(Flower* flower) { _flower = flower; }
    QStringList getSubList(QString path) override;
    void log(int severity, QString logline);
    bool setAttribute(HFSItem* item, const QString& path, QVariant value);
    bool removeAttribute(HFSItem* item, const QString& topic);
    bool setMethod(HFSItem* item, QObject* obj, const QString& methodName);
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
    int obj2int(QObject* obj);      // Transferred out for possible tokenization
    void setDefaultValues();
    bool checkDataBase();

private slots:
    void fileChanged(const QString& str);
    void epochChanged(QVariant epoch);
    void nodeRoleChanged(QVariant noderole);
    void deviceIdChanged(QVariant device_id);

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

    
    QDateTime dto;
    QDateTime dtn;
    int _dayepoch;
    int _epoch;

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

};

#endif