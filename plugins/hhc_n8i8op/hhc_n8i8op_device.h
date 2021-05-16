#ifndef hhc_n8i8op_device_H
#define hhc_n8i8op_device_H

#include "hdevice.h"
#include "tcpsocket.h"
#include "hrelay.h"

#include <QTimer>

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
    bool loadConfiguration(QJsonObject &json);

    void connectToRealDevice(); // creating tcp connection to the actual hardware

// public temporarily for setDemo
    QString _name;
    QString _id;
    QString _host;
    QString _port;

private slots:
    void readyRead();
    void connected();
    void disconnected();
    void ticktimeout();

    void setRelay(int idx, int value, int delay=0);
    void setRelays(QString ascii_command);
    void sendCommandDelayed(QString str);
    void sendCommandDelayedTimeout();
    void sendCommand(QString str);

private:
    int tcnt;
    TcpSocket *sock;
    QList<HRelay *> relays;
    QStringList out_buffer;
    QString in_buffer;      // input read buffer
    QTimer *ticktimer;
    QString name;
    bool _named;
    bool _bypass;
    QRegularExpression readregexp;
    int _delayed_timeout;
    QTimer delayed_timer;
    QString _delayed_cmd;
};
#endif