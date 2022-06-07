#ifndef hhc_n8i8op_device_H
#define hhc_n8i8op_device_H

#include "hdevice.h"
#include "tcpsocket.h"

#include <QTimer>
#include <QElapsedTimer>

class BypassEntity
{
public:
    BypassEntity() : impulsed(true), state(0)
    {
        timer.start();
    }
    ~BypassEntity() {}

    int impulsed;	// if false, relay is sync with input, if not input change (0-1 transit toggles relay)
    bool state;		// false-off, true-on for now

    QElapsedTimer timer;     // elapsed time since last change
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

    QJsonObject configurationTemplate();
    void saveConfiguration(QJsonObject &json);
    bool loadConfiguration(QJsonObject json);

// public temporarily for setDemo
    QString _name;
    QString _id;
    QString _host;
    QString _port;

private slots:
    void connectToRealDevice(); // creating tcp connection to the actual hardware
    void readyRead();
    void connected();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState socketState);

    int setInput(int idx, int val);
    void setInputs(QString ascii_command);
    void setRelay(int idx, int value);
    void setRelays(QString ascii_command);
    void sendCommand(QString str=QString());
    void updateDevice();	// send current settings to relay panel

    void checkPingStatus();

private:
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
    bool _initialized;

    QList<HEntity *> relays;
    QList<HEntity *> inputs;

// TESTING FOR 
    bool _bypass;
    QList<BypassEntity *> entities;
    QElapsedTimer pingelapsed;
    QTimer pingtimer;
    QTimer updatetimer;


};
#endif