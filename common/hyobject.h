#ifndef HYOBJECT_H
#define HYOBJECT_H

#include <QObject>
#include <QDebug>

class HyObject : public QObject
{
    Q_OBJECT
public:
    HyObject(QObject *parent=nullptr) : QObject(parent)
    {
	printf("HyObject created\n");
    }
    virtual ~HyObject() {}

public slots:
    virtual void init()
    {
	qDebug() << " -- base init ";
    }

protected slots:
    void log(int severity, QString logline)
    {
	emit signal_log(_id, severity, logline);
    }

signals:
    void signal_log(QString source, int severity, QString logline);

private:
    QString _id;
};

#endif