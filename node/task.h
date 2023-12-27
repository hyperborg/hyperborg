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

    void setValue(QString key, QString value)   { _params.insert(key, value);            }
    QVariant getValue(QString key)              { return _params.value(key);             }
    QString getStringValue(QString key)         { return getValue(key).toString();      }

    void setName(QString name)                  { _name = name;                         }
    void setDevice(QString device)              { _device = device;                     }
    void setExecutor(QString executor)          { _executor = executor;                 }
    void setPath(QString p)                     { parseURL(p);
                                        
                                                }

    QString name()                              { return _name;                         }
    QString device()                            { return _device;                       }
    QString executor()                          { return _executor;                     }
    QString path()                              { return _path;                         }
    QString pathLastElement()                   { return _path_last_element;            }

protected:
    void parseURL(QString url)
    {
        _path = url;
        QStringList lst = url.split(".");
        _path_last_element = lst.last();
    }

private:
    QString _name;
    QString _device;
    QString _executor;
    QString _path;
    QString _path_last_element;
    ParameterList _params;
};

#endif