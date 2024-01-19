#include "job.h"

// Very simple saving for Job state!!! It is required for inter-node communication testing.
// It does not handle well the multiple "=" characters in the value and stringlists yet.
// Really, just a quick POC for this area. Scheduled to be extended later on!

QString Job::save()
{
    QString str;
    QStringList lst;
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

    str = lst.join("\n");

    return str;
}

void Job::load(QString str)
{
    QStringList lst = str.split("\n");
    if (lst.count()<4) return;

    id = lst[0].toInt();
    step = lst[1].toInt();
    topic = lst[2];
    variant = lst[3];

    if (lst.count()>4)
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

