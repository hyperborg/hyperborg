#ifndef HUAWEI_SUN_H
#define HUAWEI_SUN_H

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QStringList>
#include <QMap>
#include <QHash>
#include <QHashIterator>
#include <QByteArray>
#include <QDataStream>
#include <qThread>

#include <QHostAddress>
#include <QTcpServer>
#include <QTcpSocket>

#include "common.h"
#include <hfs.h>
#include <hfsitem.h>
#include "tcpsocket.h"
#include <hyplugin.h>
#include <hyobject.h>

enum huawei_modbus_tcp
{
    MODBUS_READ             = 0x03,
    MODBUS_WRITE            = 0x06,     // Writing single register
    MODBUS_WRITE_MULTO      = 0x10,     // Writing multiple registers
    MODBUS_READ_DEVICEID    = 0x2b,     // Read device identifiers
    MODBUS_ERROR            = 0x83      // Error
};

class SunAttribute
{
public:
    SunAttribute(Attributes _hyattr, OpenMode _iomode, DataType _dt, Unit _attr_unit, int _gain, int _address, int _quantity=1, QString _path=QString(), QString _desc=QString())
    {
        hyattr = _hyattr;
        iomode = _iomode;
        dt = _dt;
        attr_unit = _attr_unit;
        gain = _gain;
        address = _address;
        quantity = _quantity;
        desc = _desc;
        avail = false;
        path = _path;
    }

    Attributes hyattr;
    OpenMode iomode;
    DataType dt;
    Unit attr_unit;
    int gain;
    int address;
    int quantity;
    QString desc;
    bool avail;
    QString path;
};

// Currently we are allowing only one register read/write (no multiple registers yet!)

class MBAPackage
{
public:
    MBAPackage();
    ~MBAPackage();

    bool decode(QByteArray ba);
    QByteArray encode();

    // MBAP definitions
    ushort trid;                // Matching identified between a request frame and a response frame
    ushort prottype;            // Protocol type    0 = Modbus
    ushort data_length ;        // Data length
    uchar  logic_dev_id;       // Logic device ID

    uchar  func_code;          // Function code
    ushort register_address;    // Register address
    ushort number_of_registers; // Number of registers

    uchar num_of_bytes;         // Response num of bytes
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
    void setHFS(HFS* _hfs) 
    {
        hfs = _hfs;
    }
    QJsonObject configurationTemplate();
    void saveConfiguration(QJsonObject &json);
    bool loadConfiguration(QJsonObject json);

protected slots:
    void popuplateQueue();
    void addQueue(int hyattr);

protected:
    void initDatabase();
    void insertSunAttribute(SunAttribute* sa);

private slots:
    void connectToRealDevice(); // creating tcp connection to the actual hardware
    void readyRead();
    void connected();
    void disconnected();
    void readOut();
    void stateChanged(QAbstractSocket::SocketState socketState);

private:
    HFS* hfs;
    QTimer *reconnect_timer;
    QTimer *readout_timer;
    QTimer *populate_timer;
    bool _initialized;
    TcpSocket* sock;
    QHash<int, SunAttribute *> sunattributes;

    QList<int> queue;
    QList<int> frequent_list;
    QList<int> not_frequent_list;

};
#endif
