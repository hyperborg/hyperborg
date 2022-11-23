#ifndef MediaLibrary_H
#define MediaLibrary_H

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QStringList>
#include <QMap>
#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QRandomGenerator>
#include <QList>

#include "common.h"
#include <hyplugin.h>
#include <hyobject.h>

class MediaLibraryDevice : public HyObject
{
    Q_OBJECT
public:
    MediaLibraryDevice();
    ~MediaLibraryDevice();

public slots:
    void init();
    void timedUpdate();
    void pushRandomFile();

private:
    QTimer timer;
    QString rootDir;
    QString hfs_filepath;
    int refresh_timeout;
    QRandomGenerator *rndgen;
    
};

class MediaLibrary : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "medialibrary.json");
    Q_INTERFACES(HyPluginInterface);

public:
    MediaLibrary(QObject *parent=NULL);
    ~MediaLibrary();

    QString name()          { return "medialibrary";                         		}
    QString description()   { return "General media library";    			}
    int implementation()    { return Developement;                      		}
    QObject *getObject()    { return this;                              		}
    QString author()        { return "Imre, Nagy  <i@hyperborg.com>";   		}

    void init();

private:
    QList<MediaLibraryDevice *> devices;

};
#endif
