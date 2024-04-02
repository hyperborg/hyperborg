#include "job.h"

// Very simple saving for Job state!!! It is required for inter-node communication testing.
// It does not handle well the multiple "=" characters in the value and stringlists yet.
// Really, just a quick POC for this area. Scheduled to be extended later on!

QString Job::save()
{
    QString str;
    QJsonObject obj;

    // Adding basic information
    obj["flow_name"] = flow->name;
    obj["id"] = id;
    obj["step"] = step;
    obj["topic"] = topic;
    obj["variant"] = variant.toString();
    obj["src_dev"] = _src_device;
    obj["dst_dev"] = _dst_device;
    obj["org_dev"] = _org_device;

    // Adding attributes
    QJsonObject arro;
    QHashIterator<QString, QVariant> it(attributes);
    while (it.hasNext())
    {
        it.next();
        arro[it.key()] = it.value().toString();
    }
    obj["attributes"] = arro;
    
    // Adding stack

    QJsonDocument doc;
    doc.setObject(obj);
    str = QString(doc.toJson());
    return str;
}

void Job::load(QString str)
{
    attributes.clear();
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject root = doc.object();
    
    flow_name = root["flow_name"].toString();
    id = root["id"].toInt();
    step = root["step"].toInt();
    topic = root["topic"].toString();
    variant = root["variant"].toVariant();
    _src_device = root["src_dev"].toInt();
    _dst_device = root["dst_dev"].toInt();
    _org_device = root["org_dev"].toInt();

    QJsonObject atto = root["attributes"].toObject();
    if (!atto.isEmpty())
    {
        QStringList keys = atto.keys();
        for (int i = 0; i < keys.count(); i++)
        {
            attributes.insert(keys.at(i), atto[keys.at(i)].toString());
        }
    }
}

