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

#include "common.h"
#include "hfsitem.h"

#if defined(WASM)
    #include <emscripten/val.h>
    #include <emscripten.h>
#endif

class HFS : public QAbstractItemModel
{
    Q_OBJECT
    friend class Slotter;
    friend class NodeCore;
    friend class UniCore;
    friend class CoreServer;

public:
    explicit HFS(QObject* parent = nullptr);

    QVariant data(const QModelIndex& index, int role) const override;
    QVariant data(QString path, int col = 0);
    void dataChangeRequest(QString path, QVariant value, int column = 0);
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
    void subscribe(QObject *obj, QString path, QString funcname=QString("setElementProperty"), int mode = SingleInterest);
    void unsubscribe(QObject *obj, QString path, QString funcname=QString("setElementProperty"));
    void provides(
        Attributes hypattr,     // HyperBorg value id if that is already enisted in common.h
        Context context,        // What this attribute contains 
        OpenMode iomode,        // How it could be accessed
        DataType dt,            // Contained data format
        Unit attr_unit,         // Used unit (ex Celsius) for this attribute
        QString path,           // Path in HFS
        QString comment,        // Comment if needed
        int     history_depth   // How many previous entries should be kept for this attribute (0=none)
    );

    // Shortcuts for frequently used functions
    void log(int severity, QString logline, QString source);

public slots:
    void objectDeleted(QObject* obj);       // remove deleted object from all mappings

protected:
    ~HFS();
    HFSItem* _hasPath(QString path, bool create = true);
    HFSItem* _createPath(QString path);
    void log(int severity, QString logline);

protected slots:
    void setData(QString path, QVariant data, int column=0);
    void inPack(DataPack* datapack);

private:
    int obj2int(QObject* obj);      // Transferred out for possible tokenization 
    void setDefaultValues();

private slots:
    void heartBeatTest();                   // Does something (for test) in each second

signals:
    void signal_log(int severity, QString logline, QString src);
    void signal_dataChangeRequest(QString path, QVariant value, int col = 0);

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
    QTimer testtimer;
    QStringList pinis;                          // Possible ini files
};



#endif