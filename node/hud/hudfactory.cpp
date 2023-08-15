#include "hudfactory.h"
#include "hyscene.h"

HUDFactory::HUDFactory(QObject *parent) : QObject(parent), scene(NULL)
{}

HUDFactory::~HUDFactory()
{}

void HUDFactory::setScene(HyScene *_scene)
{
    scene = _scene;
}

bool HUDFactory::save(QString filename)
{
    qDebug() << "Saving: " << filename;
    bool retbool = false;
    QJsonDocument doc = saveAll();
    QFile f(filename);
    if (f.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&f);
        stream << QString(doc.toJson());
        f.close();
        retbool = true;
    }
    return retbool;
}

QJsonDocument HUDFactory::saveAll()
{
    qDebug() << "saveAll ";
    QJsonDocument doc;
    if (!scene) return doc;
    QJsonObject obj;
    QJsonArray arr;

    QList<QGraphicsItem *> its = scene->items();
    for (int i=0;i<its.count();i++)
    {
        if (HUDItem *item=dynamic_cast<HUDItem *>(its.at(i)))
        {
            arr.append(item->save());
        }
    }
    obj["items"]=arr;
    doc.setObject(obj);
    return doc;
}

bool HUDFactory::load(QString filename)
{
    QFile f(filename);
    if (!f.open(QIODevice::ReadOnly))
    {
        return false;
    }
    QByteArray rall = f.readAll();
    f.close();

    QJsonParseError jerror;
    QJsonDocument doc = QJsonDocument::fromJson(rall, &jerror);
    if (jerror.error!=QJsonParseError::NoError)
    {
        return false;
    }

    return loadAll(doc);
}

bool HUDFactory::loadAll(QJsonDocument doc)
{
    QJsonObject obj = doc.object();
    QJsonArray arr = obj["items"].toArray();

    for (const QJsonValue &value :  arr)
    {
        QJsonObject cobj = value.toObject();
        create(cobj, NULL);
    }
    return true;
}


HUDItem *HUDFactory::create(QJsonObject obj, QGraphicsItem *parent)
{
    HUDItem *retitem = nullptr;
    int typ = obj["type"].toInt();
    if (HUDItem *item = create(typ, parent))
    {
        item->setHUDFactory(this);
        item->load(obj);
    }

#if 0 // Was used For testing ony

    switch(typ)
    {
        case HET_Task:
            {
                HUDTask *task = new HUDTask(parent);
                task->addInputPort(qobject_cast<HUDPort*>(create(HET_Port, task)));
//              task->addInputPort(qobject_cast<HUDPort*>(create(HET_Port, task)));
//              task->addInputPort(qobject_cast<HUDPort*>(create(HET_Port, task)));
//              task->addInputPort(qobject_cast<HUDPort*>(create(HET_Port, task)));

                task->addOutputPort(qobject_cast<HUDPort*>(create(HET_Port, task)));
//              task->addOutputPort(qobject_cast<HUDPort*>(create(HET_Port, task)));
//              task->addOutputPort(qobject_cast<HUDPort*>(create(HET_Port, task)));
//              task->addOutputPort(qobject_cast<HUDPort*>(create(HET_Port, task)));
//              task->addOutputPort(qobject_cast<HUDPort*>(create(HET_Port, task)));
//              task->addOutputPort(qobject_cast<HUDPort*>(create(HET_Port, task)));

                task->setPixmap(qobject_cast<HUDPixmap*>(create(HET_Pixmap, task)));
                task->setLabelItem(qobject_cast<HUDText *>(create(HET_Text, task)));
                task->setLabel("This is some text label");
                retitem = task;
            }
            break;
        default:
            break;
    }
#endif
    return retitem;
}

HUDItem* HUDFactory::create(int type, QGraphicsItem *parent)
{
    HUDItem *retitem = nullptr;
    switch(type)
    {
        case HET_Task:
            retitem = new HUDTask(parent);
            break;
        case HET_Port:
            retitem = new HUDPort(parent);
            break;
        case HET_Wire:
            retitem = new HUDWire(parent);
            break;
        case HET_Pixmap:
            {
                HUDPixmap* hp = new HUDPixmap(parent);
                QPixmap *px = new QPixmap(":/QML/resources/fontawesome/4.7/icons/function.svg");
                hp->setPixmap(px);
                retitem = hp;
            }
            break;
        case HET_Text:
            retitem = new HUDText(parent);
            break;
    }
    return retitem;
}

void HUDFactory::clear()
{
}
