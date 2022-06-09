#ifndef HYOBJECT_H
#define HYOBJECT_H

#include <QObject>
#include <QDebug>

#include "common.h"

class HyObject : public QObject
{
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

	Q_OBJECT
public:
	HyObject(QObject* parent = nullptr) : QObject(parent) {}
	virtual ~HyObject() {}
	virtual HyObject::Type type() { return Type::Undefined; }
	void setId(QString i) { _id = i; }
	QString id() { return _id; }

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

private:
    QString _id;
	QHash<QString, DataPack *> packs;
};

#endif