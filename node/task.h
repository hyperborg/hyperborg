#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QString>

class Task : public QObject
{
Q_OBJECT
public:
    Task(QString name, QString executor, QString method)
    {
        _name = name;
        _executor = executor;
        _method = method;
    }
    virtual ~Task() {}

    QString name()      { return _name;     }
    QString executor()  { return _executor; }
    QString method()    { return _method;   }

private:
    QString _name;
    QString _executor;
    QString _method;
};

#endif