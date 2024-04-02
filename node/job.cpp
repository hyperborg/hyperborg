#include "job.h"

// Very simple saving for Job state!!! It is required for inter-node communication testing.
// It does not handle well the multiple "=" characters in the value and stringlists yet.
// Really, just a quick POC for this area. Scheduled to be extended later on!

//#define job_numpars 8

QString Job::save()
{
    QString str;
//#if 1      // new format
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
    qDebug() << "STR: " << str;
/*
#else       // old format
    QStringList lst;
    lst << flow->name;
    lst << QString::number(id);
    lst << QString::number(step);
    lst << topic;
    lst << variant.toString();
    lst << QString::number(_src_device);
    lst << QString::number(_dst_device);
    lst << QString::number(_org_device);

    while (!stack.isEmpty())
    {
        StackPair sp = stack.pop();
        QString s = sp.first+"="+sp.second.toString();
        lst << s;
    }

    str = lst.join(";");
#endif
*/
    load(str);
    return str;
}

void Job::load(QString str)
{
#if 1       // new format
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


#else       // old format
    QStringList lst = str.split(";");
    if (lst.count()<job_numpars) return;

    flow_name = lst[0];
    id = lst[1].toInt();
    step = lst[2].toInt();
    topic = lst[3];
    variant = lst[4];
    _src_device = lst[5].toInt();
    _dst_device = lst[6].toInt();
    _org_device = lst[7].toInt();

    if (lst.count()>job_numpars)
    {
        for (int i=4;i<lst.count();i++)
        {
            QString w = lst.at(i);
            QStringList wlst = w.split("=");
            StackPair sp;
            sp.first = wlst.at(0);
            sp.second=wlst.at(1);
            stack.push(sp);
        }
    }
#endif
}

