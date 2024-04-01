#include <huawei_sun.h>

huawei_sun::huawei_sun(QObject *parent) : HyObject(parent),
_initialized(false), sock(NULL), reconnect_timer(NULL), readout_timer(NULL)
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
    readout_timer->setSingleShot(true);

    populate_timer = new QTimer(this);
    QObject::connect(populate_timer, SIGNAL(timeout()), this, SLOT(populateQueue()));
    populate_timer->setSingleShot(false);


    if (sock)
    {
        sock->disconnect();
        sock->deleteLater();
        sock = NULL;
    }

    if ((sock = new TcpSocket(this)))
    {
        QObject::connect(sock, SIGNAL(readyRead()), this, SLOT(readyRead()));
        QObject::connect(sock, SIGNAL(connected()), this, SLOT(connected()));
        QObject::connect(sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
        QObject::connect(sock, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));

        qDebug() << "TIMER START FROM THREAD: " << QThread::currentThread();
        reconnect_timer->start(1000);
    }
}

void huawei_sun::connectToRealDevice()
{
    bool ok;
    if (sock->state() != QAbstractSocket::ConnectedState)
    {
        //        sock->connectToHost(_host, _port.toInt(&ok));
        sock->connectToHost("192.168.3.16", 502);
    }
}

void huawei_sun::connected()
{
    _initialized = true;
    printf("huawei_sun::connected\n");

#if 0
    QHashIterator<int, SunAttribute*> it(sunattributes);
    while (it.hasNext())
    {
        it.next();
        queue.append(it.value()->hyattr);
    }
#endif
    populateQueue();
    readout_timer->start(300);
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
        mba.number_of_registers = sa->quantity;
        qDebug() << " ---> INVERTER : " << mba.encode().toHex();
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
    qDebug() << "FROMINV: " << ba.toHex();
    if (!queue.isEmpty())
    {
        int hyattr = queue.takeFirst();
        if (SunAttribute* sa = sunattributes.value(hyattr, NULL))
        {
            MBAPackage mba;
            mba.decode(ba);

            if (mba.error_code == 0)
            {
                bool ok;
                int i = mba.register_value.toHex().toInt(&ok, 16);
                hfs->dataChangeRequest(this, "", sa->path, QVariant(mba.register_value.toHex().toInt(&ok, 16)));
            }
            else
            {
//                qDebug() << sa->address << " IS INVALID CALL FOR READ";
            }
        }
    }
    readout_timer->start(300);
}


/* MBAPACKAGE ==========================================================*/

MBAPackage::MBAPackage()
{
    trid                = 1;
    prottype            = 0;
    data_length         = 6;
    logic_dev_id        = 1;
    func_code           = MODBUS_ERROR;
    register_address    = 0;
    register_value      = 0;
    error_code          = 0;
    num_of_bytes        = 0;
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

    QString th = ba.toHex();
    QDataStream ds(&ba, QIODevice::ReadOnly);
    ds >> trid >> prottype >> data_length >> logic_dev_id >> func_code >> num_of_bytes;
    if (func_code == MODBUS_ERROR)
    {
        ds >> error_code;
        retbool = false;
    }
    else
    {
        if (register_value.length())
            free(register_value.data());
        char* cc = (char *)malloc(num_of_bytes);
        ds.readRawData(cc, num_of_bytes);
        register_value.resize(num_of_bytes);
        register_value.setRawData(cc, num_of_bytes);
        bool ok;
        qDebug() << "DATA: " << register_value.toHex() << " ### " << register_value.toHex().toInt(&ok, 16);
        retbool = true;
    }
    return retbool;
}

/* ===========================================================================================*/

void huawei_sun::populateQueue()
{
    queue.append(INV_BATTERY_SOC);
    queue.append(INV_POWERMETER_ACTIVE_POWER);
    queue.append(INV_ACTIVE_POWER);
    queue.append(INV_BATTERY_CHARGE_AND_DISCHARGE_POWER);
    queue.append(INV_PHASE_A_VOLTAGE);
    queue.append(INV_PHASE_B_VOLTAGE);
    queue.append(INV_PHASE_C_VOLTAGE);
    queue.append(INV_PHASE_A_CURRENT);
    queue.append(INV_PHASE_B_CURRENT);
    queue.append(INV_PHASE_C_CURRENT);
    queue.append(INV_BATTERY_RUNNING_STATUS);
    queue.append(INV_INTERNAL_TEMPERATURE);
}


void huawei_sun::insertSunAttribute(SunAttribute* sa)
{
    if (!sa) return;
    sunattributes.insert(sa->hyattr, sa);
    if (hfs)
    {
    }
}

void huawei_sun::initDatabase()
{
    QString bp = "plugins.huawei_sun";
    insertSunAttribute(new SunAttribute(INV_MODEL, ReadOnly, DT_String, NotDefined, 1, 30000, 15, bp+"model",tr("model")));
    insertSunAttribute(new SunAttribute(INV_SN, ReadOnly, DT_String, NotDefined, 1, 30015, 10, bp + "serial", tr("serial")));
    insertSunAttribute(new SunAttribute(INV_PN, ReadOnly, DT_String, NotDefined, 1, 30025, 10, bp + "pn", tr("pn")));
    insertSunAttribute(new SunAttribute(INV_MODEL_ID, ReadOnly, DT_U16, NotDefined, 1, 30070, 1, bp + "model_id", tr("model_id")));
    insertSunAttribute(new SunAttribute(INV_NUM_PV_STRINGS, ReadOnly, DT_U16, NotDefined, 1, 30071, 1, bp + "num_pv_strings", tr("num_pv_strings")));
    insertSunAttribute(new SunAttribute(INV_NUM_MPP_TRACKERS, ReadOnly, DT_U16, NotDefined, 1, 30072, 1, bp + "num_mpp_trackers", tr("num_mpp_trackers")));
    insertSunAttribute(new SunAttribute(INV_RATED_POWER, ReadOnly, DT_U32, kW, 1000, 30073, 2, bp + "rated_power", tr("rated_power")));
    insertSunAttribute(new SunAttribute(INV_MAX_ACTIVE_POWER, ReadOnly, DT_U32, kW, 1000, 30075, 2, bp + "max_active_power", tr("max_active_power")));
    insertSunAttribute(new SunAttribute(INV_MAX_APPARENT_POWER, ReadOnly, DT_U32, kVA, 1000, 30077, 2, bp + "max_apparent_power", tr("max_apparent_power")));
    insertSunAttribute(new SunAttribute(INV_MAX_REACTIVE_POWER_TO_GRID, ReadOnly, DT_I32, kVar, 1000, 30079, 2, bp + "max_reactive_power_to_grid", tr("max_reactive_power_to_grid")));
    insertSunAttribute(new SunAttribute(INV_MAX_REACTIVE_POWER_FROM_GRID, ReadOnly, DT_I32, kVar, 1000, 30081, 2, bp + "max_reactive_power_from_grid", tr("max_reactive_power_from_grid")));
    insertSunAttribute(new SunAttribute(INV_STATE_1, ReadOnly, DT_BitField16, NotDefined, 1, 32000, 1, bp + "inv_state_1", tr("inv_state_1")));
    insertSunAttribute(new SunAttribute(INV_STATE_2, ReadOnly, DT_BitField16, NotDefined, 1, 32002, 1, bp + "inv_state_2", tr("inv_state_2")));
    insertSunAttribute(new SunAttribute(INV_STATE_3, ReadOnly, DT_BitField32, NotDefined, 1, 32003, 1, bp + "inv_state_3", tr("inv_state_3")));
    insertSunAttribute(new SunAttribute(INV_ALARM_1, ReadOnly, DT_BitField16, NotDefined, 1, 32008, 1, bp + "inv_alarm_1", tr("inv_alarm_1")));
    insertSunAttribute(new SunAttribute(INV_ALARM_2, ReadOnly, DT_BitField16, NotDefined, 1, 32009, 1, bp + "inv_alarm_2", tr("inv_alarm_2")));
    insertSunAttribute(new SunAttribute(INV_ALARM_3, ReadOnly, DT_BitField16, NotDefined, 1, 32010, 1, bp + "inv_alarm_3", tr("inv_alarm_3")));
    insertSunAttribute(new SunAttribute(INV_PV1_VOLTAGE, ReadOnly, DT_I16, Volt, 10, 32016, 1, bp + "pv1_voltage", tr("pv1_voltage")));
    insertSunAttribute(new SunAttribute(INV_PV1_CURRENT, ReadOnly, DT_I16, Amper, 10, 32017, 1, bp + "pv1_current", tr("pv1_current")));
    insertSunAttribute(new SunAttribute(INV_PV2_VOLTAGE, ReadOnly, DT_I16, Volt, 10, 32018, 1, bp + "pv2_voltage", tr("pv2_voltage")));
    insertSunAttribute(new SunAttribute(INV_PV2_CURRENT, ReadOnly, DT_I16, Amper, 10, 32019, 1, bp + "pv2_current", tr("pv2_current")));
    insertSunAttribute(new SunAttribute(INV_PV3_VOLTAGE, ReadOnly, DT_I16, Volt, 10, 32020, 1, bp + "pv3_voltage", tr("pv3_voltage")));
    insertSunAttribute(new SunAttribute(INV_PV3_CURRENT, ReadOnly, DT_I16, Amper, 10, 32021, 1, bp + "pv3_current", tr("pv3_current")));
    insertSunAttribute(new SunAttribute(INV_PV4_VOLTAGE, ReadOnly, DT_I16, Volt, 10, 32022, 1, bp + "pv4_voltage", tr("pv4_voltage")));
    insertSunAttribute(new SunAttribute(INV_PV4_CURRENT, ReadOnly, DT_I16, Amper, 10, 32023, 1, bp + "pv4_current", tr("pv4_current")));
    insertSunAttribute(new SunAttribute(INV_INPUT_POWER, ReadOnly, DT_I32, kW, 1000, 32064, 2, bp + "input_power", tr("input_power")));
    insertSunAttribute(new SunAttribute(INV_LINE_VOLTAGE_A_B, ReadOnly, DT_U16, Volt, 10, 32066, 1, bp + "line_voltage_a_b", tr("line_voltage_a_b")));
    insertSunAttribute(new SunAttribute(INV_LINE_VOLTAGE_B_C, ReadOnly, DT_U16, Volt, 10, 32067, 1, bp + "line_voltage_b_c", tr("line_voltage_b_c")));
    insertSunAttribute(new SunAttribute(INV_LINE_VOLTAGE_C_A, ReadOnly, DT_U16, Volt, 10, 32068, 1, bp + "line_voltage_c_a", tr("line_voltage_c_a")));
    insertSunAttribute(new SunAttribute(INV_PHASE_A_VOLTAGE, ReadOnly, DT_U16, Volt, 10, 32069, 1, bp + "phase_a_voltage", tr("phase_a_voltage")));
    insertSunAttribute(new SunAttribute(INV_PHASE_B_VOLTAGE, ReadOnly, DT_U16, Volt, 10, 32070, 1, bp + "phase_b_voltage", tr("phase_b_voltage")));
    insertSunAttribute(new SunAttribute(INV_PHASE_C_VOLTAGE, ReadOnly, DT_U16, Volt, 10, 32071, 1, bp + "phase_c_voltage", tr("phase_c_voltage")));
    insertSunAttribute(new SunAttribute(INV_PHASE_A_CURRENT, ReadOnly, DT_I32, Amper, 1000, 32072, 2, bp + "phase_a_current", tr("phase_a_current")));
    insertSunAttribute(new SunAttribute(INV_PHASE_B_CURRENT, ReadOnly, DT_I32, Amper, 1000, 32074, 2, bp + "phase_b_current", tr("phase_b_current")));
    insertSunAttribute(new SunAttribute(INV_PHASE_C_CURRENT, ReadOnly, DT_I32, Amper, 1000, 32076, 2, bp + "phase_c_current", tr("phase_c_current")));
    insertSunAttribute(new SunAttribute(INV_PEAK_ACTIVE_POWER_OF_DAY, ReadOnly, DT_I32, kW, 1000, 32078, 2, bp + "peak_active_power_of_day", tr("peak_active_power_of_day")));
    insertSunAttribute(new SunAttribute(INV_ACTIVE_POWER, ReadOnly, DT_I32, kW, 1000, 32080, 2, bp + "active_power", tr("active_power")));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_POWER, ReadOnly, DT_I32, kVar, 1000, 32082, 2, bp + "reactive_power", tr("reactive_power")));
    insertSunAttribute(new SunAttribute(INV_POWER_FACTOR, ReadOnly, DT_I16, NotDefined, 1000, 32084, 1, bp + "power_factor", tr("power_factor")));
    insertSunAttribute(new SunAttribute(INV_GRID_FREQUENCY, ReadOnly, DT_U16, Hz, 100, 32085,1, bp + "grid_frequency", tr("grid_frequency")));
    insertSunAttribute(new SunAttribute(INV_EFFICIENCY, ReadOnly, DT_U16, Percent, 100, 32086,1, bp + "efficiency", tr("efficiency")));
    insertSunAttribute(new SunAttribute(INV_INTERNAL_TEMPERATURE, ReadOnly, DT_I16, Celsius, 10, 32087, 1, bp + "internal_temperature", tr("internal_temperature")));
    insertSunAttribute(new SunAttribute(INV_INSULATION_RESISTANCE, ReadOnly, DT_U16, MOhm, 1000, 32088, 1, bp + "insulation_resistance", tr("insulation_resistance")));
    insertSunAttribute(new SunAttribute(INV_DEVICE_STATUS, ReadOnly, DT_U16, NotDefined, 1, 32089, 1, bp + "device_status", tr("device_status")));
    insertSunAttribute(new SunAttribute(INV_FAULT_CODE, ReadOnly, DT_U16, NotDefined, 1, 32090, 1, bp + "fault_code", tr("fault_code")));
    insertSunAttribute(new SunAttribute(INV_STARTUP_TIME, ReadOnly, DT_U32, NotDefined, 1, 32091, 2, bp + "startup_time", tr("startup_time")));
    insertSunAttribute(new SunAttribute(INV_SHUTDOWN_TIME, ReadOnly, DT_U32, NotDefined, 1, 32093, 2, bp + "shutdown_time", tr("shutdown_time")));
    insertSunAttribute(new SunAttribute(INV_ACCUMULATED_ENERGY_YIELD, ReadOnly, DT_U32, kWh, 100, 32106, 2, bp + "accumulated_energy_yield", tr("accumulated_energy_yield")));
    insertSunAttribute(new SunAttribute(INV_DAILY_ENERGY_YIELD, ReadOnly, DT_U32, kWh, 100, 32114, 2, bp + "daily_energy_yield", tr("daily_energy_yield")));
    insertSunAttribute(new SunAttribute(INV_ACTIVE_ADJUSTMENT_MODE, ReadOnly, DT_U16, NotDefined, 1, 35300, 1, bp + "active_adjustment_mode", tr("active_adjustment_mode")));
    insertSunAttribute(new SunAttribute(INV_ACTIVE_ADJUSTMENT_VALUE, ReadOnly, DT_U32, NotDefined, 1, 35302, 2, bp + "active_adjustment_value", tr("active_adjustment_value")));
    insertSunAttribute(new SunAttribute(INV_ACTIVE_ADJUSTMENT_COMMAND, ReadOnly, DT_U16, NotDefined, 1, 35303, 1, bp + "active_adjustment_command", tr("active_adjustment_command")));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_ADJUSTMENT_MODE, ReadOnly, DT_U16, NotDefined, 1, 35304, 1, bp + "reactive_adjustment_mode", tr("reactive_adjustment_mode")));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_ADJUSTMENT_VALUE, ReadOnly, DT_U32, NotDefined, 1, 35305, 2, bp + "reactive_adjustment_value", tr("reactive_adjustment_value")));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_ADJUSTMENT_COMMAND, ReadOnly, DT_U16, NotDefined, 1, 35307, 1, bp + "reactive_adjustment_mode", tr("reactive_adjustment_mode")));
    insertSunAttribute(new SunAttribute(INV_BATTERY_RUNNING_STATUS, ReadOnly, DT_U16, NotDefined, 1, 37000, 1, bp + "battery_running_status", tr("battery_running_status")));
    insertSunAttribute(new SunAttribute(INV_BATTERY_CHARGE_AND_DISCHARGE_POWER, ReadOnly, DT_I32, W, 1, 37001, 2, bp + "battery_chare_and_discharge_power", tr("battery_chare_and_discharge_power")));
    insertSunAttribute(new SunAttribute(INV_BATTERY_SOC, ReadOnly, DT_U16, Percent, 10, 37004, 1, bp + "battery_soc", tr("battery_soc")));
    insertSunAttribute(new SunAttribute(INV_BATTERY_CHARGE_CAPACITY_OF_DAY, ReadOnly, DT_U32, kWh, 100, 37015, 2, bp + "battery_charge_capacity_of_day", tr("battery_charge_capacity_of_day")));
    insertSunAttribute(new SunAttribute(INV_BATTERY_DISCHARGE_CAPACITY_OF_DAY, ReadOnly, DT_U32, kWh, 100, 37017, 2, bp + "battery_discharge_capacity_of_day", tr("battery_discharge_capacity_of_day")));
    insertSunAttribute(new SunAttribute(INV_POWERMETER_ACTIVE_POWER, ReadOnly, DT_I32, W, 1, 37113, 2, bp + "powermeter_active_power", tr("powermeter_active_power")));
    insertSunAttribute(new SunAttribute(INV_OPTIMIZER_TOTAL_NUMBER, ReadOnly, DT_U16, NotDefined, 1, 37200, 1, bp + "optimizer_total_number", tr("optimizer_total_number")));
    insertSunAttribute(new SunAttribute(INV_OPTIMIZER_ONLINE, ReadOnly, DT_U16, NotDefined, 1, 37201, 1, bp + "optimizer_online", tr("optimizer_online")));
    insertSunAttribute(new SunAttribute(INV_OPTIMIZER_FEATURE_DATA, ReadOnly, DT_U16, NotDefined, 1, 37202, 1, bp + "optimizer_feature_data", tr("optimizer_feature_data")));
    insertSunAttribute(new SunAttribute(INV_SYSTEM_TIME, ReadWrite, DT_U32, NotDefined, 1, 40000, 2, bp + "system_time", tr("system_time")));
    insertSunAttribute(new SunAttribute(INV_Q_U_CHARACTERISTIC_CURVE_MODE, ReadWrite, DT_U16, NotDefined, 1, 40037, 1, bp + "q_u_characteristic_curve_mode", tr("q_u_characteristic_curve_mode")));
    insertSunAttribute(new SunAttribute(INV_Q_U_DISPATCH_TRIGGER_POWER, ReadWrite, DT_U16, Percent, 1, 40038, 1, bp + "q_u_dispatch_trigger_power", tr("q_u_dispatch_trigger_power")));
    insertSunAttribute(new SunAttribute(INV_FIXED_ACTIVE_POWER_DERATED, ReadWrite, DT_U16, kW, 10, 40120, 1, bp + "fixed_active_power_derated", tr("fixed_active_power_derated")));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_POWER_COMPENSATION_PF, ReadWrite, DT_I16, NotDefined, 1000, 40122, 1, bp + "reactive_power_compensation_pf", tr("reactive_power_compensation_pf")));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_POWER_COMPENSATION_QS, ReadWrite, DT_I16, NotDefined, 1000, 40123, 1, bp + "reactive_power_compensation_qs", tr("reactive_power_compensation_qs")));
    insertSunAttribute(new SunAttribute(INV_ACTIVE_POWER_PERCENTAGE_DERATING, ReadWrite, DT_U16, Percent, 10, 40125, 1, bp + "active_power_percentage_derating", tr("active_power_percentage_derating")));
    insertSunAttribute(new SunAttribute(INV_FIXED_ACTIVE_POWER_DERATED, ReadWrite, DT_U32, W, 1, 40126, 2, bp + "fixed_active_power_derated", tr("fixed_active_power_derated")));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_POWER_COMPENSATION_AT_NIGHT, ReadWrite, DT_I32, kVar, 1000, 40129, 2, bp + "reactive_power_compensation_at_night", tr("reactive_power_compensation_at_night")));
//    insertSunAttribute(new SunAttribute(INV_COSFI_CCHARACTERISTIC_CURVE
//    insertSunAttribute(new SunAttribute(INV_Q_U_CHARACHTERISTIC_CURVE
//    insertSunAttribute(new SunAttribute(INV_PF_U_CHARACTERISTIC_CURVE
    insertSunAttribute(new SunAttribute(INV_REACTIVE_POWER_ADJUSTMENT_TIME, ReadWrite, DT_U16, Second, 1, 40196, 1, bp + "reactive_power_adjust_time", tr("reactive_power_adjust_time")));
    insertSunAttribute(new SunAttribute(INV_Q_U_POWER_PERCENTAGE_TO_EXIT_SCHEDULING, ReadWrite, DT_U16, Percent, 1, 40198, 1, bp + "q_u_power_to_exit_scheduling", tr("q_u_power_to_exit_scheduling")));
    insertSunAttribute(new SunAttribute(INV_STARTUP, WriteOnly, DT_U16, NotDefined, 1, 40200, 1, bp + "startup", tr("startup")));
    insertSunAttribute(new SunAttribute(INV_SHUTDOWN, WriteOnly, DT_U16, NotDefined, 1, 40201, 1, bp + "shutdown", tr("shutdown")));
    insertSunAttribute(new SunAttribute(INV_GRID_CODE, ReadWrite, DT_U16, NotDefined, 1, 42000, 1, bp + "grid_code", tr("grid_code")));
    insertSunAttribute(new SunAttribute(INV_REACTIVE_POWER_CHANGE_GRADIENT, ReadWrite, DT_U32, PercentPerSec, 1000, 42015, 2, bp + "reactive_power_change_gradient", tr("reactive_power_change_gradient")));
    insertSunAttribute(new SunAttribute(INV_ACTIVE_POWER_CHANGE_GRADIENT, ReadWrite, DT_U32, PercentPerSec, 1000, 42017, 2, bp + "active_power_change_gradient", tr("active_power_change_gradient")));
    insertSunAttribute(new SunAttribute(INV_SCHEDULE_INSTRUCTION_VALID_DURATION, ReadWrite, DT_U32,  Second, 1000, 42019, 2, bp + "schedule_instruction_valid_duration", tr("schedule_instruction_valid_duration")));
    insertSunAttribute(new SunAttribute(INV_TIME_ZONE, ReadWrite, DT_I16, Minute, 1, 43006, 1, bp + "time_zone", tr("time_zone")));
    insertSunAttribute(new SunAttribute(INV_BATTERY_WORKING_MODE, ReadWrite, DT_U16, NotDefined, 1, 47004, 1, bp + "battery_working_mode", tr("battery_working_mode")));
    insertSunAttribute(new SunAttribute(INV_BATTERY_TIME_OF_USE_ELECTRICITY_PRICE, ReadWrite, DT_U16, NotDefined, 1, 47027, 1, bp + "battery_time_of_use_electricity_price", tr("battery_time_of_use_electricity_price")));
//    insertSunAttribute(new SunAttribute(INV_BATTERY_PRICE_PERIODS,
    insertSunAttribute(new SunAttribute(INV_BATTERY_LCOE, ReadWrite, DT_U32, NotDefined, 1000, 47069, 2, bp + "battery_lcoe", tr("battery_lcoe")));
    insertSunAttribute(new SunAttribute(INV_BATTERY_MAXIMUM_CHARGING_POWER, ReadWrite, DT_U32, W, 1, 47075, 2, bp + "battery_maximum_charging_power", tr("battery_maximum_charging_power")));
    insertSunAttribute(new SunAttribute(INV_BATTERY_MAXIMUM_DISCHARGING_POWER, ReadWrite, DT_U32, W, 1, 47077, 2, bp + "battery_maximum_discharging_power", tr("battery_maximum_discharging_power")));
    insertSunAttribute(new SunAttribute(INV_BATTERY_POWER_LIMIT_GRID_TIED_POINT, ReadWrite, DT_I32, W, 1, 47079, 2, bp + "battery_power_limit_grid_tied_point", tr("battery_power_limit_grid_tied_point")));
    insertSunAttribute(new SunAttribute(INV_BATTERY_CHARGE_CUTOFF_CAPACITY, ReadWrite, DT_U16, Percent, 10, 47081, 1, bp + "battery_charge_cutoff_capacity", tr("battery_charge_cutoff_capacity")));
    insertSunAttribute(new SunAttribute(INV_BATTERY_DISCHARGE_CUTOFF_CAPACITY, ReadWrite, DT_U16, Percent, 10, 47081, 1, bp + "battery_discharge_cutoff_capacity", tr("battery_discharge_cutoff_capacity")));
    insertSunAttribute(new SunAttribute(INV_BATTERY_FORCED_CHARGING_DISCHARGING_PERIOD, ReadWrite, DT_U16, Minute, 1, 47083, 1, bp + "battery_forced_discharging_period", tr("battery_forced_discharging_period")));
    insertSunAttribute(new SunAttribute(INV_BATTERY_FORCED_CHARGING_DISCHARGING_POWER, ReadWrite, DT_I32, W, 1, 47084, 2, bp + "battery_forced_discharging_power", tr("battery_forced_discharging_power")));
//    insertSunAttribute(new SunAttribute(INV_BATTERY_FIXED_CHARGING_DISCHARGING_PERIODS

}