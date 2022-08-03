#ifndef HUAWEI_SUN_H
#define HUAWEI_SUN_H

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QStringList>
#include <QMap>
#include <QByteArray>

#include <QHostAddress>
#include <QTcpServer>
#include <QTcpSocket>

#include "common.h"
#include "tcpsocket.h"
#include <hyplugin.h>
#include <hyobject.h>

enum xx
{
    MODBUS_READ             = 0x03,
    MODBUS_WRITE            = 0x06,     // Writing single register
    MODBUS_WRITE_MULTO      = 0x10,     // Writing multiple registers
    MODBUS_READ_DEVICEID    = 0x2b,     // Read device identifiers
    MODBUS_ERROR            = 0x83      // Error
};

// Currently we are allowing only one register read/write (no multiple registers yet!)

class MBAPackage
{
public:
    MBAPackage();
    ~MBAPackage();

    bool decode(QByteArray ba);
    QByteArray encode();

    ushort trid;                // Matching identified between a request frame and a response frame
    ushort prottype;            // Protocol type    0 = Modbus
    ushort data_length;         // Data length
    char   logic_dev_id;        // Logic device ID
    char   func_code;           // Function code
    ushort register_address;    // Register address
    ushort number_of_registers; // Number of registers
    QByteArray register_value;  // Register value 
    char   error_code;          // Error code
};


class huawei_sun : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "huawei_sun.json");
    Q_INTERFACES(HyPluginInterface);

public:
    huawei_sun(QObject *parent=nullptr);
    ~huawei_sun();

    QString name()          { return "huawei_sun";                         		}
    QString description()   { return "Huawei Sun Solar Inverter Device Driver"; }
    int implementation()    { return Developement;                      	    }
    QObject *getObject()    { return this;                              	    }
    QString author()        { return "Imre, Nagy  <i@hyperborg.com>";   	    }

    void init();

public slots:
    QJsonObject configurationTemplate();
    void saveConfiguration(QJsonObject &json);
    bool loadConfiguration(QJsonObject json);

private slots:
    void connectToRealDevice(); // creating tcp connection to the actual hardware
    void readyRead();
    void connected();
    void disconnected();
    void readOut();
    void stateChanged(QAbstractSocket::SocketState socketState);

private:
    QTimer reconnect_timer;
    QTimer readout_timer;
    bool _initialized;
    TcpSocket* sock;
};
#endif
