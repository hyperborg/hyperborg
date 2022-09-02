#include <huawei_sun.h>

huawei_sun::huawei_sun(QObject *parent) : HyObject(parent),
_initialized(false), sock(NULL), hfs(NULL), reconnect_timer(NULL)
{
}

huawei_sun::~huawei_sun()
{
}

void huawei_sun::init()
{
    initDatabase();

    // Creating essential timers
    reconnect_timer = new QTimer(this);
    QObject::connect(reconnect_timer, SIGNAL(timeout()), this, SLOT(connectToRealDevice()));
    reconnect_timer->setSingleShot(true);

    readout_timer = new QTimer(this);
    QObject::connect(readout_timer, SIGNAL(timeout()), this, SLOT(readOut()));
    readout_timer->setSingleShot(false);

    populate_timer = new QTimer(this);
    QObject::connect(populate_timer, SIGNAL(timeout()), this, SLOT(populateQueue()));
    populate_timer->setSingleShot(false);


    if (sock)
    {
        sock->disconnect();
        sock->deleteLater();
        sock = NULL;
    }
    if (sock = new TcpSocket(this))
    {
        QObject::connect(sock, SIGNAL(readyRead()), this, SLOT(readyRead()));
        QObject::connect(sock, SIGNAL(connected()), this, SLOT(connected()));
        QObject::connect(sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
        QObject::connect(sock, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));

        qDebug() << "TIMER START FROM THREAD: " << QThread::currentThread();
        reconnect_timer->start(1000);
    }
}

QJsonObject huawei_sun::configurationTemplate()
{
    return QJsonObject();
}

void huawei_sun::saveConfiguration(QJsonObject& json)
{
    Q_UNUSED(json);
}

bool huawei_sun::loadConfiguration(QJsonObject json)
{
    Q_UNUSED(json);
    return true;
}

void huawei_sun::connectToRealDevice()
{
    bool ok;
    if (sock->state() != QAbstractSocket::ConnectedState)
    {
        //        sock->connectToHost(_host, _port.toInt(&ok));
        sock->connectToHost("192.168.37.161", 502);
    }
}

void huawei_sun::connected()
{
    _initialized = true;
    printf("huawei_sun::connected\n");

    QHashIterator<int, SunAttribute*> it(sunattributes);
    while (it.hasNext())
    {
        it.next();
        queue.append(it.value()->hyattr);
    }
    readout_timer->start(1000);
}

void huawei_sun::disconnected()
{
    queue.clear();      
   _initialized = false;
}

void huawei_sun::stateChanged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        reconnect_timer->start(15 * 1000);       // trying to reconnect in 30 secs
    }
}

void huawei_sun::popuplateQueue()
{}


void huawei_sun::addQueue(int hyattr)
{
    queue.append(hyattr);
    if (!readout_timer->isActive())
    {
        readout_timer->start(30);
    }
}

void huawei_sun::readOut()
{
    if (!_initialized) return;
    if (queue.isEmpty())
    {
        return;
    }

    int hyattr = queue.first();
    if (SunAttribute* sa = sunattributes.value(hyattr, NULL))
    {
        int register_id = sa->address;
        MBAPackage mba;
        mba.func_code = MODBUS_READ;
        mba.register_address = register_id;
        sock->write(mba.encode());
        sock->flush();
    }
}

void huawei_sun::readyRead()
{
    // This is a TCP socket. We might want to implement some kind of buffering in case 
    // the transmission is fragmented. But with nowadays hardware, it should not happen.
    // We are talking about 20-30 bytes packages. For now, if cannot be encoded, we just drop.

    QByteArray ba = sock->readAll();

    int hyattr = queue.takeFirst();
    if (SunAttribute* sa = sunattributes.value(hyattr, NULL))
    {
        MBAPackage mba;
        mba.decode(ba);

        if (mba.error_code == 0)
        {
            qDebug() << sa->address << " could be EXECUTED, value : " << mba.register_value;
        }
        else
        {
            qDebug() << sa->address << " IS INVALID CALL FOR READ";
        }
    }
}


/* MBAPACKAGE ==========================================================*/

MBAPackage::MBAPackage()
{
    trid                = 1;
    prottype            = 0;
    logic_dev_id        = 1;
    func_code           = MODBUS_ERROR;
    register_address    = 0;
    register_value      = 0;
    error_code          = 0;
    data_length         = 6;
    number_of_registers = 1;
}

MBAPackage::~MBAPackage()
{
}

QByteArray MBAPackage::encode()
{
    QByteArray ba;
    QDataStream ds(&ba, QIODevice::ReadWrite);

    ds << trid << prottype << data_length << logic_dev_id;
    ds << func_code << register_address << number_of_registers;

    qDebug() << "toHex1: " << ba.toHex();

return ba;
}

bool MBAPackage::decode(QByteArray ba)
{
    qDebug() << "SUN DECODE: " << ba.toHex();
    bool retbool = false;
    int ba_size = ba.size();
    if (ba_size < 9)
    {
        // return package is too small
        error_code = -1;
        return retbool;
    }

    QDataStream ds(&ba, QIODevice::ReadOnly);
    ds >> trid >> prottype >> data_length >> logic_dev_id >> func_code;
    if (func_code == MODBUS_ERROR)
    {
        ds >> error_code;
        retbool = false;
    }
    else
    {
        if (ba_size == data_length + 9)
        {
            ds >> register_value;
            retbool = true;
        }
    }
    return retbool;
}

/* ===========================================================================================*/

void huawei_sun::insertSunAttribute(SunAttribute* sa)
{
    if (!sa) return;
    sunattributes.insert(sa->hyattr, sa);
}

void huawei_sun::initDatabase()
{
    insertSunAttribute(new SunAttribute(INV_MODEL, ReadOnly, DT_String, NotDefined, 1, 30000, 15));
    insertSunAttribute(new SunAttribute(INV_SN, ReadOnly, DT_String, NotDefined, 1, 30015, 10));
    insertSunAttribute(new SunAttribute(INV_PN, ReadOnly, DT_String, NotDefined, 1, 30025, 10));
    insertSunAttribute(new SunAttribute(INV_MODEL_ID, ReadOnly, DT_U16, NotDefined, 1, 30070, 1));
    insertSunAttribute(new SunAttribute(INV_NUM_PV_STRINGS, ReadOnly, DT_U16, NotDefined, 1, 30071, 1));
    insertSunAttribute(new SunAttribute(INV_NUM_MPP_TRACKERS, ReadOnly, DT_U16, NotDefined, 1, 30072, 1));
    insertSunAttribute(new SunAttribute(INV_RATED_POWER, ReadOnly, DT_U32, kW, 1000, 30073, 2));
    insertSunAttribute(new SunAttribute(INV_MAX_ACTIVE_POWER, ReadOnly, DT_U32, kW, 1000, 30075, 2));
    insertSunAttribute(new SunAttribute(INV_MAX_APPARENT_POWER, ReadOnly, DT_U32, kVA, 1000, 30077, 2));
    insertSunAttribute(new SunAttribute(INV_MAX_REACTIVE_POWER_TO_GRID, ReadOnly, DT_I32, kVar, 1000, 30079, 2));
    insertSunAttribute(new SunAttribute(INV_MAX_REACTIVE_POWER_TO_GRID, ReadOnly, DT_I32, kVar, 1000, 30081, 2));
    insertSunAttribute(new SunAttribute(INV_STATE_1, ReadOnly, DT_BitField16, NotDefined, 1, 32000, 1));
    insertSunAttribute(new SunAttribute(INV_STATE_2, ReadOnly, DT_BitField16, NotDefined, 1, 32002, 1));
    insertSunAttribute(new SunAttribute(INV_STATE_3, ReadOnly, DT_BitField32, NotDefined, 1, 32003, 1));
    insertSunAttribute(new SunAttribute(INV_ALARM_1, ReadOnly, DT_BitField16, NotDefined, 1, 32008, 1));
    insertSunAttribute(new SunAttribute(INV_ALARM_2, ReadOnly, DT_BitField16, NotDefined, 1, 32009, 1));
    insertSunAttribute(new SunAttribute(INV_ALARM_3, ReadOnly, DT_BitField16, NotDefined, 1, 32010, 1));
    insertSunAttribute(new SunAttribute(INV_PV1_VOLTAGE, ReadOnly, DT_I16, Volt, 10, 32016, 1));
    insertSunAttribute(new SunAttribute(INV_PV1_CURRENT, ReadOnly, DT_I16, Amper, 10, 32017, 1));
    insertSunAttribute(new SunAttribute(INV_PV2_VOLTAGE, ReadOnly, DT_I16, Volt, 10, 32018, 1));
    insertSunAttribute(new SunAttribute(INV_PV2_CURRENT, ReadOnly, DT_I16, Amper, 10, 32019, 1));
    insertSunAttribute(new SunAttribute(INV_PV3_VOLTAGE, ReadOnly, DT_I16, Volt, 10, 32020, 1));
    insertSunAttribute(new SunAttribute(INV_PV3_CURRENT, ReadOnly, DT_I16, Amper, 10, 32021, 1));
    insertSunAttribute(new SunAttribute(INV_PV4_VOLTAGE, ReadOnly, DT_I16, Volt, 10, 32022, 1));
    insertSunAttribute(new SunAttribute(INV_PV4_CURRENT, ReadOnly, DT_I16, Amper, 10, 32023, 1));
    insertSunAttribute(new SunAttribute(INV_INPUT_POWER, ReadOnly, DT_I32, kW, 1000, 32064, 2));
    insertSunAttribute(new SunAttribute(INV_LINE_VOLTAGE_A_B, ReadOnly, DT_U16, Volt, 10, 32066, 1));
    insertSunAttribute(new SunAttribute(INV_LINE_VOLTAGE_B_C, ReadOnly, DT_U16, Volt, 10, 32067, 1));
    insertSunAttribute(new SunAttribute(INV_LINE_VOLTAGE_C_A, ReadOnly, DT_U16, Volt, 10, 32068, 1));
    insertSunAttribute(new SunAttribute(INV_PHASE_A_VOLTAGE, ReadOnly, DT_U16, Volt, 10, 32069, 1));
    insertSunAttribute(new SunAttribute(INV_PHASE_B_VOLTAGE, ReadOnly, DT_U16, Volt, 10, 32070, 1));
    insertSunAttribute(new SunAttribute(INV_PHASE_C_VOLTAGE, ReadOnly, DT_U16, Volt, 10, 32071, 1));
    insertSunAttribute(new SunAttribute(INV_PHASE_A_CURRENT, ReadOnly, DT_I32, Amper, 1000, 32072, 2));
    insertSunAttribute(new SunAttribute(INV_PHASE_B_CURRENT, ReadOnly, DT_I32, Amper, 1000, 32074, 2));
    insertSunAttribute(new SunAttribute(INV_PHASE_C_CURRENT, ReadOnly, DT_I32, Amper, 1000, 32076, 2));
    insertSunAttribute(new SunAttribute(INV_PEAK_ACTIVE_POWER_OF_DAY, ReadOnly, DT_I32, kW, 1000, 32078, 2));
    insertSunAttribute(new SunAttribute(INV_ACTIVE_POWER, ReadOnly, DT_I32, kW, 1000, 32080, 2));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_POWER, ReadOnly, DT_I32, kVar, 1000, 32082, 2));
    insertSunAttribute(new SunAttribute(INV_POWER_FACTOR, ReadOnly, DT_I16, NotDefined, 1000, 32084, 1));
    insertSunAttribute(new SunAttribute(INV_GRID_FREQUENCY, ReadOnly, DT_U16, Hz, 100, 32085,1));
    insertSunAttribute(new SunAttribute(INV_EFFICIENCY, ReadOnly, DT_U16, Percent, 100, 32086,1));
    insertSunAttribute(new SunAttribute(INV_INTERNAL_TEMPERATURE, ReadOnly, DT_I16, Celsius, 10, 32087, 1));
    insertSunAttribute(new SunAttribute(INV_INSULATION_RESISTANCE, ReadOnly, DT_U16, MOhm, 1000, 32088, 1));
    insertSunAttribute(new SunAttribute(INV_DEVICE_STATUS, ReadOnly, DT_U16, NotDefined, 1, 32089, 1));
    insertSunAttribute(new SunAttribute(INV_FAULT_CODE, ReadOnly, DT_U16, NotDefined, 1, 32090, 1));
    insertSunAttribute(new SunAttribute(INV_STARTUP_TIME, ReadOnly, DT_U32, NotDefined, 1, 32091, 2));
    insertSunAttribute(new SunAttribute(INV_SHUTDOWN_TIME, ReadOnly, DT_U32, NotDefined, 1, 32093, 2));
    insertSunAttribute(new SunAttribute(INV_ACCUMULATED_ENERGY_YIELD, ReadOnly, DT_U32, kWh, 100, 32106, 2));
    insertSunAttribute(new SunAttribute(INV_DAILY_ENERGY_YIELD, ReadOnly, DT_U32, kWh, 100, 32114, 2));
    insertSunAttribute(new SunAttribute(INV_ACTIVE_ADJUSTMENT_MODE, ReadOnly, DT_U16, NotDefined, 1, 35300, 1));
    insertSunAttribute(new SunAttribute(INV_ACTIVE_ADJUSTMENT_VALUE, ReadOnly, DT_U32, NotDefined, 1, 35302, 2));
    insertSunAttribute(new SunAttribute(INV_ACTIVE_ADJUSTMENT_COMMAND, ReadOnly, DT_U16, NotDefined, 1, 35303, 1));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_ADJUSTMENT_MODE, ReadOnly, DT_U16, NotDefined, 1, 35304, 1));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_ADJUSTMENT_VALUE, ReadOnly, DT_U32, NotDefined, 1, 35305, 2));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_ADJUSTMENT_COMMAND, ReadOnly, DT_U16, NotDefined, 1, 35307, 1));
    insertSunAttribute(new SunAttribute(INV_BATTERY_RUNNING_STATUS, ReadOnly, DT_U16, NotDefined, 1, 37000, 1));
    insertSunAttribute(new SunAttribute(INV_BATTERY_CHARGE_AND_DISCHARGE_POWER, ReadOnly, DT_I32, W, 1, 37001, 2));
    insertSunAttribute(new SunAttribute(INV_BATTERY_SOC, ReadOnly, DT_U16, Percent, 10, 37004, 1));
    insertSunAttribute(new SunAttribute(INV_BATTERY_CHARGE_CAPACITY_OF_DAY, ReadOnly, DT_U32, kWh, 100, 37015, 2));
    insertSunAttribute(new SunAttribute(INV_BATTERY_DISCHARGE_CAPACITY_OF_DAY, ReadOnly, DT_U32, kWh, 100, 37017, 2));
    insertSunAttribute(new SunAttribute(INV_POWERMETER_ACTIVE_POWER, ReadOnly, DT_I32, W, 1, 37113, 2));
    insertSunAttribute(new SunAttribute(INV_OPTIMIZER_TOTAL_NUMBER, ReadOnly, DT_U16, NotDefined, 1, 37200, 1));
    insertSunAttribute(new SunAttribute(INV_OPTIMIZER_ONLINE, ReadOnly, DT_U16, NotDefined, 1, 37201, 1));
    insertSunAttribute(new SunAttribute(INV_OPTIMIZER_FEATURE_DATA, ReadOnly, DT_U16, NotDefined, 1, 37202, 1));
    insertSunAttribute(new SunAttribute(INV_SYSTEM_TIME, ReadWrite, DT_U32, NotDefined, 1, 40000, 2));
    insertSunAttribute(new SunAttribute(INV_Q_U_CHARACTERISTIC_CURVE_MODE, ReadWrite, DT_U16, NotDefined, 1, 40037, 1));
    insertSunAttribute(new SunAttribute(INV_Q_U_DISPATCH_TRIGGER_POWER, ReadWrite, DT_U16, Percent, 1, 40038, 1));
    insertSunAttribute(new SunAttribute(INV_FIXED_ACTIVE_POWER_DERATED, ReadWrite, DT_U16, kW, 10, 40120, 1));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_POWER_COMPENSATION_PF, ReadWrite, DT_I16, NotDefined, 1000, 40122, 1));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_POWER_COMPENSATION_QS, ReadWrite, DT_I16, NotDefined, 1000, 40123, 1));
    insertSunAttribute(new SunAttribute(INV_ACTIVE_POWER_PERCENTAGE_DERATING, ReadWrite, DT_U16, Percent, 10, 40125, 1));
    insertSunAttribute(new SunAttribute(INV_FIXED_ACTIVE_POWER_DERATED, ReadWrite, DT_U32, W, 1, 40126, 2));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_POWER_COMPENSATION_AT_NIGHT, ReadWrite, DT_I32, kVar, 1000, 40129, 2));
//    insertSunAttribute(new SunAttribute(INV_COSFI_CCHARACTERISTIC_CURVE
//    insertSunAttribute(new SunAttribute(INV_Q_U_CHARACHTERISTIC_CURVE
//    insertSunAttribute(new SunAttribute(INV_PF_U_CHARACTERISTIC_CURVE
    insertSunAttribute(new SunAttribute(INV_REACTIVE_POWER_ADJUSTMENT_TIME, ReadWrite, DT_U16, Second, 1, 40196, 1));
    insertSunAttribute(new SunAttribute(INV_Q_U_POWER_PERCENTAGE_TO_EXIT_SCHEDULING, ReadWrite, DT_U16, Percent, 1, 40198, 1));
    insertSunAttribute(new SunAttribute(INV_STARTUP, WriteOnly, DT_U16, NotDefined, 1, 40200, 1));
    insertSunAttribute(new SunAttribute(INV_SHUTDOWN, WriteOnly, DT_U16, NotDefined, 1, 40201, 1));
    insertSunAttribute(new SunAttribute(INV_GRID_CODE, ReadWrite, DT_U16, NotDefined, 1, 42000, 1));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_POWER_CHANGE_GRADIENT, ReadWrite, DT_U32, PercentPerSec, 1000, 42015, 2));
    insertSunAttribute(new SunAttribute(INV_ACTIVE_POWER_CHANGE_GRADIENT, ReadWrite, DT_U32, PercentPerSec, 1000, 42017, 2));
    insertSunAttribute(new SunAttribute(INV_SCHEDULE_INSTRUCTION_VALID_DURATION, ReadWrite, DT_U32,  Second, 1000, 42019, 2));
    insertSunAttribute(new SunAttribute(INV_TIME_ZONE, ReadWrite, DT_I16, Minute, 1, 43006, 1));
    insertSunAttribute(new SunAttribute(INV_BATTERY_WORKING_MODE, ReadWrite, DT_U16, NotDefined, 1, 47004, 1));
    insertSunAttribute(new SunAttribute(INV_BATTERY_TIME_OF_USE_ELECTRICITY_PRICE, ReadWrite, DT_U16, NotDefined, 1, 47027, 1));
//    insertSunAttribute(new SunAttribute(INV_BATTERY_PRICE_PERIODS, 
    insertSunAttribute(new SunAttribute(INV_BATTERY_LCOE, ReadWrite, DT_U32, NotDefined, 1000, 47069, 2));
    insertSunAttribute(new SunAttribute(INV_BATTERY_MAXIMUM_CHARGING_POWER, ReadWrite, DT_U32, W, 1, 47075, 2));
    insertSunAttribute(new SunAttribute(INV_BATTERY_MAXIMUM_DISCHARGING_POWER, ReadWrite, DT_U32, W, 1, 47077, 2));
    insertSunAttribute(new SunAttribute(INV_BATTERY_POWER_LIMIT_GRID_TIED_POINT, ReadWrite, DT_I32, W, 1, 47079, 2));
    insertSunAttribute(new SunAttribute(INV_BATTERY_CHARGE_CUTOFF_CAPACITY, ReadWrite, DT_U16, Percent, 10, 47081, 1));
    insertSunAttribute(new SunAttribute(INV_BATTERY_DISCHARGE_CUTOFF_CAPACITY, ReadWrite, DT_U16, Percent, 10, 47081, 1));
    insertSunAttribute(new SunAttribute(INV_BATTERY_FORCED_CHARGING_DISCHARGING_PERIOD, ReadWrite, DT_U16, Minute, 1, 47083, 1));
    insertSunAttribute(new SunAttribute(INV_BATTERY_FORCED_CHARGING_DISCHARGING_POWER, ReadWrite, DT_I32, W, 1, 47084, 2));
//    insertSunAttribute(new SunAttribute(INV_BATTERY_FIXED_CHARGING_DISCHARGING_PERIODS

}