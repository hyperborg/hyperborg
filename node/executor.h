#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "job.h"

#include <QObject>
#include <QThread>
#include <QString>

class Executor : public QObject
{
Q_OBJECT
public:
    Executor(QObject* executedobj, QObject* parent = nullptr);
    ~Executor();

    QString getName() { return name; }
    void setName(QString _name) { name = _name; }
    void setExecutedObject(QObject* _obj) { obj = _obj; }

signals:
    void finished(Job* job);

public slots:
    void enqueueJob(Job* job, QString methodname) 
    {
        if (obj && job && job->flow)
        {
            QDateTime dt = QDateTime::currentDateTime();
            qDebug() << "["<< dt.toString("yyyy-MM-dd hh:mm:ss.zzz") << "]" << " EXECUTING TASK ID: " << job->id << " stepping: " << job->step << " thread: " << QThread::currentThread();
            QVariant retval;
            if (job->topic.isEmpty())
            {
                QMetaObject::invokeMethod(obj, methodname.toLatin1(), Qt::DirectConnection, Q_RETURN_ARG(QVariant, retval));
            }
            else
            {
                QMetaObject::invokeMethod(obj, methodname.toLatin1(), Qt::DirectConnection, Q_RETURN_ARG(QVariant, retval), Q_ARG(QString, job->topic), Q_ARG(QVariant, job->variant));
            }
            // return value should be handled
            emit finished(job);
        }
    }

public:
    QString name;

public slots:
    void startJob(QString flowname) 
    {
        // NOT YET IMPLEMENTED
    }

private:
    QObject* obj;

};

#endif