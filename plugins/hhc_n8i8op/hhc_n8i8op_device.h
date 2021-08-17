#ifndef hhc_n8i8op_device_H
#define hhc_n8i8op_device_H

#include "hdevice.h"
#include "tcpsocket.h"
#include "hentity.h"

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

    void setInput(int idx, int val);
    void setInputs(QString ascii_command);
    void setRelay(int idx, int value, int delay=0);
    void setRelays(QString ascii_command);
    void sendCommandDelayed(QString str);
    void sendCommandDelayedTimeout();
    void sendCommand(QString str=QString());

private:
    int tcnt;
    TcpSocket *sock;
    QString in_buffer;      // input read buffer
    QString name;
    bool _named;
    bool _bypass;
    QRegularExpression readregexp;
    int _delayed_timeout;
    QTimer delayed_timer;
    QTimer reconnect_timer;
    QString _delayed_cmd;
    QStringList send_queue;
    int send_ack;
    bool _initialized;

    QList<HEntity *> relays;
    QList<HEntity *> inputs;
};
#endif