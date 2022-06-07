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

#include "common.h"

class Listener
{
public:
    Listener();
    ~Listener();

    QString _id;
    int     _ptr;       // int or QObject*?
    QString _token;
    int     _mode;      // When hfsitem changes, should the change be pushed or tell the listener to pull?
    int     _permanent; // If not permanent, the push or pull would remove the entry from the model
};

class HFS;
class Slotter;

class HFSItem
{
    
public:
    friend class HFS;
    friend class Slotter;
 
    explicit HFSItem(QString id, HFSItem* parentItem = nullptr, const QList<QVariant>& data=QList<QVariant>());
    ~HFSItem();

    void appendChild(HFSItem* child);
    HFSItem* getThis() { return this; }

    HFSItem* child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    HFSItem* parentItem();
    QString _id;
    void setData(QVariant d, int col=0);
    QVariant data(int column = 0);

protected:
    QList<HFSItem*> m_childItems;
    QList<QObject*> registered;         // list of registered objects should be notified when this item changes
                                        //!!! and it should be a Listener, not a QObject

private:
    QList<QVariant> m_itemData;
    HFSItem* m_parentItem;
};

class HFS : public QAbstractItemModel
{
    Q_OBJECT
    friend class Slotter;
public:
	explicit HFS(QObject* parent = nullptr);
	~HFS();

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
    
    void loadInitFiles();
    void saveInitFiles();

    // Any device or actor could register itself to get push/pull notifications on value change
    void interested(QObject *obj, QString path=QString(), int mode=0);
    void uninterested(QObject *obj, QString path=QString());

public slots:
    void objectDeleted(QObject* obj);       // remove deleted object from all mappings

protected:
    HFSItem* _hasPath(QString path, bool create = true);
    HFSItem* _createPath(QString path);
    void log(int severity, QString logline);

protected slots:
    void setData(QString path, QVariant data, int column=0);

private:
    int obj2int(QObject* obj);      // Transferred out for possible tokenization 
    void setDefaultValues();

private slots:
    void heartBeatTest();                   // Does something (for test) in each second

signals:
    void signal_log(int severity, QString logline, QString src);
    void signal_dataChangeRequest(QString path, QVariant value, int col = 0);

private:
    HFSItem* rootItem;
    QMutex mutex;
    QHash<int, QString> tokens;
    QHash<QString, Listener*> listeners;
    QRandomGenerator rndgen;
    QMap<int, QStringList> interested_cache;    //!! performance: might use pointer for list here.
    QTimer testtimer;
    QStringList pinis;                          // Possible ini files
};



#endif