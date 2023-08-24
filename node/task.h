#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QString>

class Task : public QObject
{
Q_OBJECT
public:
    Task(QString name, QString executor, QString topic, QString method)
    {
        _name = name;
        _executor = executor;
        _topic = topic;
        _method = method;
    }
    virtual ~Task() {}

    QString name()      { return _name;     }
    QString executor()  { return _executor; }
    QString topic()     { return _topic;    }
    QString method()    { return _method;   }

private:
    QString _name;
    QString _executor;
    QString _topic;
    QString _method;
};

#endif