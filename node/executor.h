#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "common.h"
#include "job.h"
#include "hfs_interface.h"

#include <QThread>
#include <QRunnable>

#include "executor.h"

class Executor : public QObject
{
    Q_OBJECT
public:
    Executor(HFS_Interface* hfsi, QObject* parent = nullptr) : QObject(parent), hfs(hfsi)
    {}
    ~Executor()
    {}

    QString getName() { return name; }
    void setName(QString _name) { name = _name; }

signals:
    void finished(Job* job);

public slots:
    void enqueueJob(Job* job)
    {
        bool log = false;
        if (job && job->flow)
        {
            QDateTime dt = QDateTime::currentDateTime();
            if (log) qDebug() << "[" << dt.toString("yyyy-MM-dd hh:mm:ss.zzz") << "]" << " EXECUTING TASK ID: " << job->id << " stepping: " << job->step << " thread: " << QThread::currentThread();
            QVariant retval;
            if (Task* task = job->currentTask())
            {
                QString path = task->path();
                QString function = task->pathFunction();
                function = function.replace("()", "");

                if (!path.isEmpty() && !function.isEmpty())
                {
                    if (QObject* obj = hfs->getObjectAttribute(path))
                    {
                        bool f = QMetaObject::invokeMethod(obj, function.toLatin1(), Qt::DirectConnection, Q_RETURN_ARG(QVariant, retval), Q_ARG(Job*, job));
                        if (f)
                        {
                            job->setLastError(retval);
                        }
                        else
                        {
                            job->setLastError(1, tr("Requested function is not available"));
                        }
                    }
                }
                dt = QDateTime::currentDateTime();
                if (log) qDebug() << "[" << dt.toString("yyyy-MM-dd hh:mm:ss.zzz") << "]" << " EXECUTED TASK ID: " << job->id << " stepping: " << job->step << " thread: " << QThread::currentThread() << "\n";
                emit finished(job);
            }
        }
    }

public:
    QString name;

private:
    HFS_Interface* hfs;
};

#endif