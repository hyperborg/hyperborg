#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QString>
#include <QVariant>

class Task : public QObject
{
    Q_OBJECT
public:
    Task(QString name, QString executor, QString method)
    {
        setName(name);
        setExecutor(executor);
        setMethod(method);
    }
    virtual ~Task() {}

    void setName(QString name) { setValue("name", name); }
    void setExecutor(QString name) { setValue("executor", name); }
    void setMethod(QString name) { setValue("method", name); }
    void setValue(QString key, QString value) { params.insert(key, value); }

    QString name() { return getValue("name").toString(); }
    QString executor() { return getValue("executor").toString().toLower(); }
    QString method() { return getValue("method").toString(); }
    QVariant getValue(QString key) { return params.value(key); }
    QString getStringValue(QString key) { return getValue(key).toString(); }

private:
    QString _name;
    QString _executor;
    QString _method;

    QHash<QString, QVariant> params;
};

#endif