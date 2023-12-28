#ifndef TASK_H
#define TASK_H

#include <common.h>

#include <QObject>
#include <QString>
#include <QVariant>

class Task : public QObject
{
    Q_OBJECT
public:
    Task(QString name, QString url, ParameterList params=ParameterList())
    {
        setName(name);
        parseURL(url);
        _params = params;
    }
    virtual ~Task() {}

    void setValue(QString key, QString value)   { _params.insert(key, value);           }
    QVariant getValue(QString key)              { return _params.value(key);            }
    QString getStringValue(QString key)         { return getValue(key).toString();      }

    void setName(QString name)                  { _name = name;                         }
    void setPath(QString p)                     { parseURL(p);                      }

    QString name()                              { return _name;                         }
    QString path()                              { return _path;                         }
    QString pathFunction()                      { return _path_function;                }
    QString pathTopic()                         { return _path_topic;                   }

protected:
    void parseURL(QString url)
    {
        _path = url;
        if (url.isEmpty()) return;
        QStringList lst = url.split(".");
        if (lst.last().endsWith("()"))
        {
            _path_function = lst.last();
        }
        else
        {
            _path_topic = _path;
        }

        if (!_path_function.isEmpty())
        {
            lst.removeLast();
            _path_topic = lst.join(".");
        }
    }

private:
    QString _name;
    QString _path;
    QString _path_function;
    QString _path_topic;
    ParameterList _params;
};

#endif