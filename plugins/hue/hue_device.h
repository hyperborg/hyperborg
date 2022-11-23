#ifndef hue_device_H
#define hue_device_H

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

#include "hdevice.h"

class hue_device : public HDevice
{
    enum Mode
    {
        GET,
        POST,
        DELETE,
        NOTIMPLEMENTED
    };

Q_OBJECT
public:
    hue_device(QObject *parent=nullptr);
    ~hue_device();
    HyObject::Type type() { return Device; }
    void disconnect() {}
    void init();

public slots:
    void setup();
    void connectToRealDevice(); // creating tcp connection to the actual hardware

protected slots:
    void handleNetworkData(QNetworkReply *reply);
    void handleSSLErrors(QNetworkReply *reply);

private slots:
    // GENERAL
    void proceed(hue_device::Mode, QString cmd, QString body, QString parser);

    // LIGHTS API
    void getAllLights();
    void getNewLights();
    void getLightAttributesAndState(QString id);
    void setLightAttribute(QString id);
    void setLightState(QString id);
    void deleteLight(QString id);

    // GROUPS API
    void getAllGroups();
    void createGroup();
    void getGroupAttributes();
    void setGroupAttributes();
    void setGroupState();
    void deleteGroup();

    // SCHEDULES API
    void getAllSchedules();
    void createSchedule();
    void getScheduleAttributes();
    void setScheduleAttributes();
    void deleteSchedule();

    // SCENES API
    void getAllScenes();
    void createScene();
    void modifyScene();
    void recallScene();
    void deleteScene();
    void getScene();
    
    // SENSORS API
    void getAllSensors();
    void createSensor();
    void findNewSensors();
    void getNewSensors();
    void getSensor();
    void updateSensor();
    void deleteSensor();
    void changeSensorState();
    
    // RULES API
    void getAllRules();
    void getRule();
    void createRule();
    void updateRule();
    void deleteRule();

    // CONFIGURATION API
    void createUser();
    void getConfiguration();
    void modifyConfiguration();
    void deleteUser();
    void getFullState();
    
    // RESOURCELINKS API
    void getAllResourceLinks();
    void getResourceLinks();
    void createResourceLinks();
    void updateResourceLinks();
    
    // CAPABILITIES API
    void getAllCapabilities();
    



private:
    QNetworkAccessManager *netman;

public: // for testing
    QString _host;
    QString _username;
};
#endif