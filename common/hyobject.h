#ifndef HYOBJECT_H
#define HYOBJECT_H

#include <QObject>
#include <QDebug>

#include "common.h"
#include "hfs_interface.h"
#include "hfsitem.h"

class HyObject : public QObject
{
	Q_OBJECT
public:
	enum Type
	{
		Undefined = 0,
		CoreServer = 1,
		UniCore = 2,
		Slotter = 3,
		Plugin = 4,
		Device = 5,
		Entity = 6
	};

public:
	HyObject(QObject* parent = nullptr) : QObject(parent) {}
	virtual ~HyObject() {}
	virtual HyObject::Type type() { return Type::Undefined; }
	void setId(QString i) { _id = i; }
	QString id() { return _id; }

	void setHFS(HFS_Interface *h)
	{
	    qDebug() << "Setting HFS " << h << " for " << "whatever";
	    hfs = h;
	}

public slots:
	virtual void init() {}
	virtual void receivePack(DataPack* p);

protected slots:
    void log(int severity, QString logline)
    {
	emit signal_log(severity, logline, _id);
    }

signals:
    void signal_log(int severity, QString logline, QString source);
	void signal_sendPack(DataPack *p);

protected:
	void registerEntity(QString entity_id);
	void unregisterEntity(QString entity_id);

	void startModification(QString entity_id=QString());
	void setValue(QString key, HyValue value, QString entity_id=QString());
	void endModification(QString entity_id=QString());

	virtual QStringList deviceKeys(QString str);

private:
	void sendPack(DataPack *pack)
	{
		emit signal_sendPack(pack);
	}

	void sendSystemCommand(int cmd_id, QString val1=QString(), QString val2=QString())
	{
		startModification();
		DataPack *pack = new DataPack();
		pack->setCommand(cmd_id);
		pack->attributes.insert("$$VAL1", val1);
		pack->attributes.insert("$$VAL2", val2);
		endModification();
	}

protected:
    HFS_Interface* hfs;

private:
    QString _id;
    QHash<QString, DataPack *> packs;
};

#endif