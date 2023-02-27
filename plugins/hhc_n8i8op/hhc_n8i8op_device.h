#ifndef hhc_n8i8op_device_H
#define hhc_n8i8op_device_H

#include "hdevice.h"
#include "tcpsocket.h"
#include "hfs_interface.h"
#include "hfsitem.h"

#include <QTimer>
#include <QElapsedTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

class HHCN8I8OPDevicePort
{
public:
    HHCN8I8OPDevicePort()  
    {
        input_state = 0;
        last_input_statechange = 0;
        relay_state = 0;
        impulsed=true;
        changed=false;
    }
    ~HHCN8I8OPDevicePort() {}

    bool changed;
    bool input_state;
    qint64 last_input_statechange;
    bool relay_state;
    bool impulsed;
};

class hhc_n8i8op_device : public HDevice
{
Q_OBJECT
public:
    hhc_n8i8op_device(QObject *parent=nullptr);
    ~hhc_n8i8op_device();
    HyObject::Type type() { return Device; }
    void disconnect() {}
    void init();

    bool loadConfiguration(QString name, QString id, QString host, QString port);

// public temporarily for setDemo
    QString _name;
    QString _id;
    QString _host;
    QString _port;

public slots:
    void turnOn(QString idx, QVariant value);
    void turnOff(QString idx, QVariant value);
    void toggle(QString idx, QVariant value);

private slots:
    void connectToRealDevice(); // creating tcp connection to the actual hardware
    void readyRead();
    void connected();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState socketState);

    int setInput(int idx, int val);
    void setInputs(QString ascii_command);
    int setRelay(int idx, int value, bool callUpdateDevice=true);
    void setRelays(QString ascii_command, bool callUpdateDevice = true);
    void sendCommand(QString str=QString());
    void updateDevice();	// send current settings to relay panel

    void logToFile(QString str);
    void testTimeout();

private:
    bool _test;
    TcpSocket *sock;
    int tcnt;
    QString in_buffer;      // input read buffer
    QString name;
    bool _named;
    QRegularExpression readregexp;
    int _delayed_timeout;
    QTimer reconnect_timer;
    QStringList send_queue;
    int send_ack;
    int maxports;
    bool _initialized;

    QList<HHCN8I8OPDevicePort*> ports;
    QTimer updatetimer;
    QTimer testtimer;
    QDateTime epoch_dt;
    int _testcnt;
};
#endif