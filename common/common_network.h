#ifndef COMMON_NETWORK_H
#define COMMON_NETWORK_H

#include <QVariant>
#include <QString>
#include <QStringList>
#include <QList>
#include <QWebSocket>
#include <QHash>
#include <QHashIterator>

#include "common.h"
#include "datapack.h"

class NodeRegistry
{
public:
    NodeRegistry(int _id, QWebSocket* s) : id(_id), socket(s), self(false) {}
    ~NodeRegistry()
    {
        if (socket)
        {
            socket->close();
            socket->deleteLater();
            while (DataPack* db = getDataPack())
            {
                delete(db);
            }
        }
    }

    bool self;
    int id;
    QWebSocket* socket;

    void addDataPack(DataPack* pack)
    {
        packs.append(pack);
    }

    DataPack* getDataPack()
    {
        if (!packs.count()) return NULL;
        return packs.takeFirst();
    }

private:
    QList<DataPack*> packs;
};

#if !PF_WASM
#include <QNetworkAddressEntry>
#include <QNetworkInterface>
#endif

static QStringList HlocalAddresses()
{
    QStringList lst;
#if !PF_WASM
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    for (int i = 0; i < interfaces.count(); i++)
    {
        if (interfaces.at(i).flags() & (QNetworkInterface::IsUp | QNetworkInterface::IsRunning))
        {
            QList<QNetworkAddressEntry> entries = interfaces.at(i).addressEntries();
            for (int j = 0; j < entries.count(); j++)
            {
                if (entries.at(j).ip().protocol() == QAbstractSocket::IPv4Protocol)
                {
                    lst.append(entries.at(j).ip().toString());
                }
            }
        }
    }
#ifdef HDEBUG
    lst.prepend("127.0.0.1");
#endif
#endif
    return lst;
}



#endif