#ifndef hhc_n8i8op_device_H
#define hhc_n8i8op_device_H

#include "tcpsocket.h"
#include "hfs_interface.h"
#include "hfsitem.h"

#include <QElapsedTimer>

class Job;

class HHCN8I8OPDevicePort
{
public:
    HHCN8I8OPDevicePort(QString didx)
    {
        devidx = didx;
        state = -1;
        last_statechange = 0;
        impulsed = true;
        changed = false;
    }
    ~HHCN8I8OPDevicePort() {}

    int state;
    bool changed;
    qint64 last_statechange;
    bool impulsed;
    QString topic;
    QString devidx;
};

class hhc_n8i8op_device : public QObject //Hactor?
{
    Q_OBJECT
public:
    hhc_n8i8op_device(QObject* parent = nullptr);
    ~hhc_n8i8op_device();
    void disconnect() {}
    void loadConfiguration(QString str);

    bool loadConfiguration(QString name, QString id, QString host, QString port,  int heartbeat_timeout=30);

    // public temporarily for setDemo
    QString _name;
    QString _id;
    QString _host;
    QString _port;

public slots:
    QVariant turnOn(Job *job);
    QVariant turnOff(Job *job);
    QVariant toggle(Job *job);

private slots:
    void checkConnectionStatus();
    bool connectToRealDevice(); // creating tcp connection to the actual hardware
    void readyRead();
    void connected();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState socketState);

    void setInputs(QString ascii_command);
    void setRelays(QString ascii_command);
    void sendCommand(QString str = QString());

private:
    void setPhysicalRelay(HHCN8I8OPDevicePort* port, int expected_value);

private:
    bool _test;
    TcpSocket* sock;
    int tcnt;
    QString in_buffer;      // input read buffer
    QString name;
    bool _named;
    QStringList keywords;
    QRegularExpression readregexp;
    int _delayed_timeout;
    QTimer reconnect_timer;
    QElapsedTimer heartbeat_elapsed;
    QStringList send_queue;
    int send_ack;
    int maxports;
    bool _initialized;
    int _expected_heartbeat;
    int _reconnect_timeout;

    QList<HHCN8I8OPDevicePort*> in_ports;
    QList<HHCN8I8OPDevicePort*> relays;
    QDateTime epoch_dt;
    int _testcnt;
};
#endif
