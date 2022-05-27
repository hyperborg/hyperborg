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

class HFSItem
{
    
public:
    friend class HFS;
 
    explicit HFSItem(QString id, HFSItem* parentItem = nullptr, const QList<QVariant>& data=QList<QVariant>());
    ~HFSItem();

    void appendChild(HFSItem* child);

    HFSItem* child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    HFSItem* parentItem();

    QString _id;

protected:
    QList<HFSItem*> m_childItems;

private:
    QList<QVariant> m_itemData;
    HFSItem* m_parentItem;
};

class HFS : public QAbstractItemModel
{

	Q_OBJECT
public:
	explicit HFS(QObject* parent = nullptr);
	~HFS();

	QVariant data(const QModelIndex& index, int role) const override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	QModelIndex index(int row, int col, const QModelIndex& parent = QModelIndex()) const override;
	QModelIndex parent(const QModelIndex& index) const override;
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QString getToken(QObject *object);
    void releaseToken(QObject *object);

    // Any device or actor could register itself to get push/pull notifications on value change
    void interested(QString token, QString path, int mode);
    void uninterested(QString token, QString path);

    QString getRandomString(int length);

protected:
    HFSItem *_hasPath(QString path);
    HFSItem *_createPath(QString path);

private:
    HFSItem* rootItem;
    QHash<int, QString> tokens;
    QHash<QString, Listener*> listeners;
    QRandomGenerator rndgen;
};



#endif