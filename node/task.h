#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QString>

class Task : public QObject
{
Q_OBJECT
public:
    Task(QString _taskname, QString execurl, QString _key=QString())
    {
        key = _key;
        taskname = _taskname;
        setExecUrl(execurl);
    }
    ~Task() {}

    void setExecUrl(QString str)
    {
        QStringList lst = str.split(".");
        if (lst.count() == 1)
        {
            methodname = lst.first();
        }
        else
        {
            executorname = lst[0];
            methodname = lst[1];
        }
    }

public:
    QString taskname;
    QString executorname;
    QString methodname;
    QString key;
};

#endif