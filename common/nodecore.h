#ifndef NODECORE_H
#define NODECORE_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QPluginLoader>
#include <QDir>
#include <QDomNode>

#include "hyplugin.h"
#include <common.h>

class NodeCore : public QObject
{
Q_OBJECT

public:
    NodeCore(int appmode=NoFeature, QObject *parent=NULL);
    void launch();
    ~NodeCore();

    void loadPlugins();
    int requiredFeatures() { return _requiredfeatures; }
    int appMode() { return _appmode; }

public slots:
    void slot_log(QString source, int severity, QString logline);

    void sendDataBlockToMesh(QString data) {}
    void sendDataBlockToMesh(QDomNode node) {}

signals:
    void incomingDataBlock(QDomNode node);

private:
    QList<HyPlugin *> plugins;
    int _requiredfeatures;
    int _appmode;
};

#endif