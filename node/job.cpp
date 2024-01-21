#include "job.h"

// Very simple saving for Job state!!! It is required for inter-node communication testing.
// It does not handle well the multiple "=" characters in the value and stringlists yet.
// Really, just a quick POC for this area. Scheduled to be extended later on!

QString Job::save()
{
    QString str;
    QStringList lst;
    lst << flow->name;
    lst << QString::number(id);
    lst << QString::number(step);
    lst << topic;
    lst << variant.toString();

    while (!stack.isEmpty())
    {
        StackPair sp = stack.pop();
        QString s = sp.first+"="+sp.second.toString();
        lst << s;
    }

    str = lst.join(";");

    return str;
}

void Job::load(QString str)
{
    QStringList lst = str.split(";");
    if (lst.count()<5) return;

    flow_name = lst[0];
    id = lst[1].toInt();
    step = lst[2].toInt();
    topic = lst[3];
    variant = lst[4];

    if (lst.count()>5)
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
}

