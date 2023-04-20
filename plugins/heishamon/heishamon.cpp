#include <heishamon.h>

HeishaMon::HeishaMon(QObject *parent) : HyObject(parent)
{
    leafpoint = "plugins.heishamon.";
}

HeishaMon::~HeishaMon()
{
}

void HeishaMon::init()
{
    qDebug() << "---HeishaMon INIT---";
//    m_userprop
//    m_authprop

    m_client = new QMqttClient(this);
    m_client->setHostname("192.168.37.111");
    m_client->setPort(1883);
    m_client->setClientId("hyperborg_111");
    m_client->setUsername("hyperborg_111");
    m_client->setPassword("SuperSecret4567");

        connect(m_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) 
        {
//        const QString content = QDateTime::currentDateTime().toString()
//                    + QLatin1String(" Received Topic: ")
//                    + topic.name()
//                    + QLatin1String(" Message: ")
//                    + message
//                    + QLatin1Char('\n');
        const QString content = QDateTime::currentDateTime().toString()+"      "
                    + topic.name()+"  "
                    + message
                    + QLatin1Char('\n');
        qDebug() << content;
    });

        connect(m_client, &QMqttClient::pingResponseReceived, this, [this]() {
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" PingResponse")
                    + QLatin1Char('\n');
        qDebug() << content;
    });

    QObject::connect(m_client, SIGNAL(connected()), this, SLOT(connected()));
    QObject::connect(m_client, SIGNAL(disconnected()), this, SLOT(disconnected()));
    QObject::connect(m_client, SIGNAL(errorChanged(QMqttClient::ClientError)), this, SLOT(errorChanged(QMqttClient::ClientError)));

    m_client->connectToHost();

/*
    qDebug() << "HeishaMon init with HFS: " << hfs;
    hfs->providesSensor(this, _pathbase+"indoortemp_F",         DT_Numeric,   Farenheit, "", 2, 2);

    hfs->addDBHook(_pathbase+"indoortemp_F",          "sensors");
*/
}

void HeishaMon::connected()
{
    qDebug() << "HeishaMon is connected";

    QMqttTopicFilter filter("panasonic_heat_pump/main/#");
    m_client->subscribe(filter);
    

}

void HeishaMon::disconnected()
{
    qDebug() << "HeishaMon is DISconnected";
}

void HeishaMon::errorChanged(QMqttClient::ClientError err)
{
    qDebug() << err;
}

/*

    hfs->providesSensor(this, _pathbase+"indoortemp_F",         DT_Numeric,   Farenheit, "", 2, 2);

    //OPTS
   hfs->provideSensor(this, leafpoint+"main/Heatpump_State",                   tr("Heatpump state (0=off, 1=on)")
   hfs->provideSensor(this, leafpoint+   "main/Pump_Flow",                        tr("Pump flow (l/min)")
   hfs->provideSensor(this, leafpoint+   "main/Force_DHW_State",                  tr("DHW status (0=off, 1=on)")
   hfs->provideSensor(this, leafpoint+   "main/Quiet_Mode_Schedule",              tr("Quiet mode schedule (0=inactive, 1=active)")
   hfs->provideSensor(this, leafpoint+   "main/Operating_Mode_State",             tr("Operating mode (0=Heat only, 1=Cool only, 2=Auto(Heat), 3=DHW only, 4=Heat+DHW, 5=Cool+DHW, 6=Auto(Heat)+DHW, 7=Auto(Cool), 8=Auto(Cool)+DHW)")
   hfs->provideSensor(this, leafpoint+   "main/Main_Inlet_Temp",                  tr("Main inlet water temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Main_Outlet_Temp",                 tr("Main outlet water temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Main_Target_Temp",                 tr("Main outlet water target temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Compressor_Freq",                  tr("Compressor frequency (Hz)")
   hfs->provideSensor(this, leafpoint+   "main/DHW_Target_Temp",                  tr("DHW target temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/DHW_Temp",                         tr("Actual DHW temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Operations_Hours",                 tr("Heatpump operating time (Hour)")
   hfs->provideSensor(this, leafpoint+   "main/Operations_Counter",               tr(" Heatpump starts (counter)")
   hfs->provideSensor(this, leafpoint+   "main/Main_Schedule_State",              tr("Main thermostat schedule state (inactive - active)")
   hfs->provideSensor(this, leafpoint+   "main/Outside_Temp",                     tr("Outside ambient temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Heat_Energy_Production",           tr("Thermal heat power production (Watt)")
   hfs->provideSensor(this, leafpoint+   "main/Heat_Energy_Consumption",          tr("Elektrical heat power consumption at heat mode (Watt)")
   hfs->provideSensor(this, leafpoint+   "main/Powerful_Mode_Time",               tr("Powerful state in minutes (0, 1, 2 or 3 x 30min)")
   hfs->provideSensor(this, leafpoint+   "main/Quiet_Mode_Level",                 tr("Quiet mode level (0, 1, 2, 3)")
   hfs->provideSensor(this, leafpoint+   "main/Holiday_Mode_State",               tr("Holiday mode (0=off, 1=scheduled, 2=active)")
   hfs->provideSensor(this, leafpoint+   "main/ThreeWay_Valve_State",             tr("3-way valve mode (0=Room, 1=DHW)")
   hfs->provideSensor(this, leafpoint+   "main/Outside_Pipe_Temp",                tr("Outside pipe temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/DHW_Heat_Delta",                   tr("DHW heating delta (-12 to -2) (K)")
   hfs->provideSensor(this, leafpoint+   "main/Heat_Delta",                       tr("Heat delta (K)")
   hfs->provideSensor(this, leafpoint+   "main/Cool_Delta",                       tr("Cool delta (K)")
   hfs->provideSensor(this, leafpoint+   "main/DHW_Holiday_Shift_Temp",           tr("DHW Holiday shift temperature (-15 to +15)")
   hfs->provideSensor(this, leafpoint+   "main/Defrosting_State",                 tr("Defrost state (0=off, 1=on)")
   hfs->provideSensor(this, leafpoint+   "main/Z1_Heat_Request_Temp",             tr("Zone 1 Heat Requested shift temp (-5 to 5) or direct heat temp (20 to max)")
   hfs->provideSensor(this, leafpoint+   "main/Z1_Cool_Request_Temp",             tr("Zone 1 Cool Requested shift temp (-5 to 5) or direct cool temp (5 to 20)")
   hfs->provideSensor(this, leafpoint+   "main/Z1_Heat_Curve_Target_High_Temp",   tr("Target temperature at lowest point on the heating curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z1_Heat_Curve_Target_Low_Temp",    tr("Target temperature at highest point on the heating curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z1_Heat_Curve_Outside_High_Temp",  tr("Lowest outside temperature on the heating curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z1_Heat_Curve_Outside_Low_Temp",   tr("Highest outside temperature on the heating curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Room_Thermostat_Temp",             tr("Remote control thermostat temp (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z2_Heat_Request_Temp",             tr("Zone 2 Heat Requested shift temp (-5 to 5) or direct heat temp (20 to max)")
   hfs->provideSensor(this, leafpoint+   "main/Z2_Cool_Request_Temp",             tr("Zone 2 Cool Requested shift temp (-5 to 5) or direct cool temp (5 to 20)")
   hfs->provideSensor(this, leafpoint+   "main/Z1_Water_Temp",                    tr("Zone 1 Water outlet temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z2_Water_Temp",                    tr("Zone 2 Water outlet temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Cool_Energy_Production",           tr("Thermal cooling power production (Watt)")
   hfs->provideSensor(this, leafpoint+   "main/Cool_Energy_Consumption",          tr("Elektrical cooling power consumption (Watt)")
   hfs->provideSensor(this, leafpoint+   "main/DHW_Energy_Production",            tr("Thermal DHW power production (Watt)")
   hfs->provideSensor(this, leafpoint+   "main/DHW_Energy_Consumption",           tr("Elektrical DHW power consumption (Watt)")
   hfs->provideSensor(this, leafpoint+   "main/Z1_Water_Target_Temp",             tr("Zone 1 water target temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z2_Water_Target_Temp",             tr("Zone 2 water target temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Error",                            tr("Last active Error from Heat Pump")
   hfs->provideSensor(this, leafpoint+   "main/Room_Holiday_Shift_Temp",          tr("Room heating Holiday shift temperature (-15 to 15)")
   hfs->provideSensor(this, leafpoint+   "main/Buffer_Temp",                      tr("Actual Buffer temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Solar_Temp",                       tr("Actual Solar temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Pool_Temp",                        tr("Actual Pool temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Main_Hex_Outlet_Temp",             tr("Outlet 2, after heat exchanger water temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Discharge_Temp",                   tr("Discharge Temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Inside_Pipe_Temp",                 tr("Inside pipe temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Defrost_Temp",                     tr("Defrost temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Eva_Outlet_Temp",                  tr("Eva Outlet temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Bypass_Outlet_Temp",               tr("Bypass Outlet temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Ipm_Temp",                         tr("Ipm temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z1_Temp",                          tr("Zone1: Actual Temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z2_Temp",                          tr("Zone2: Actual Temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/DHW_Heater_State",                 tr("When enabled, backup/booster heater can be used for DHW heating (disabled - enabled)")
   hfs->provideSensor(this, leafpoint+   "main/Room_Heater_State",                tr("When enabled, backup heater can be used for room heating (disabled - enabled)")
   hfs->provideSensor(this, leafpoint+   "main/Internal_Heater_State",            tr("Internal backup heater state (inactive - active)")
   hfs->provideSensor(this, leafpoint+   "main/External_Heater_State",            tr("External backup/booster heater state (inactive - active)")
   hfs->provideSensor(this, leafpoint+   "main/Fan1_Motor_Speed",                 tr("Fan 1 Motor rotation speed (R/Min)")
   hfs->provideSensor(this, leafpoint+   "main/Fan2_Motor_Speed",                 tr("Fan 2 Motor rotation speed (R/Min)")
   hfs->provideSensor(this, leafpoint+   "main/High_Pressure",                    tr("High Pressure (Kgf/Cm2)")
   hfs->provideSensor(this, leafpoint+   "main/Pump_Speed",                       tr("Pump Rotation Speed (R/Min)")
   hfs->provideSensor(this, leafpoint+   "main/Low_Pressure",                     tr("Low Pressure (Kgf/Cm2)")
   hfs->provideSensor(this, leafpoint+   "main/Compressor_Current",               tr("Compressor/Outdoor unit Current (Ampere)")
   hfs->provideSensor(this, leafpoint+   "main/Force_Heater_State",               tr("Force heater status (0=inactive, 1=active)")
   hfs->provideSensor(this, leafpoint+   "main/Sterilization_State",              tr("Sterilisation State (0=inactive, 1=active)")
   hfs->provideSensor(this, leafpoint+   "main/Sterilization_Temp",               tr("Sterilisation Temperature (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Sterilization_Max_Time",           tr("Sterilisation maximum time (minutes)")
   hfs->provideSensor(this, leafpoint+   "main/Z1_Cool_Curve_Target_High_Temp",   tr("Target temperature at highest point on the cooling curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z1_Cool_Curve_Target_Low_Temp",    tr("Target temperature at lowest point on the cooling curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z1_Cool_Curve_Outside_High_Temp",  tr("Highest outside temperature on the cooling curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z1_Cool_Curve_Outside_Low_Temp",   tr("Lowest outside temperature on the cooling curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Heating_Mode",                     tr("Compensation / Direct mode for heat (0 = compensation curve, 1 = direct)")
   hfs->provideSensor(this, leafpoint+   "main/Heating_Off_Outdoor_Temp",         tr("Above this outdoor temperature all heating is turned off(5 to 35 °C)")
   hfs->provideSensor(this, leafpoint+   "main/Heater_On_Outdoor_Temp",           tr("Below this temperature the backup heater is allowed to be used by heatpump heating logic(-15 to 20 °C)")
   hfs->provideSensor(this, leafpoint+   "main/Heat_To_Cool_Temp",                tr("Outdoor temperature to switch from heat to cool mode when in auto setting(°C)")
   hfs->provideSensor(this, leafpoint+   "main/Cool_To_Heat_Temp",                tr("Outdoor temperature to switch from cool to heat mode when in auto setting (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Cooling_Mode",                     tr("Compensation / Direct mode for cool (0 = compensation curve, 1 = direct)")
   hfs->provideSensor(this, leafpoint+   "main/Z2_Heat_Curve_Target_High_Temp",   tr("Target temperature at lowest point on the heating curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z2_Heat_Curve_Target_Low_Temp",    tr("Target temperature at highest point on the heating curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z2_Heat_Curve_Outside_High_Temp",  tr("Lowest outside temperature on the heating curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z2_Heat_Curve_Outside_Low_Temp",   tr("Highest outside temperature on the heating curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z2_Cool_Curve_Target_High_Temp",   tr("Target temperature at highest point on the cooling curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z2_Cool_Curve_Target_Low_Temp",    tr("Target temperature at lowest point on the cooling curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z2_Cool_Curve_Outside_High_Temp",  tr("Highest outside temperature on the cooling curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Z2_Cool_Curve_Outside_Low_Temp",   tr("Lowest outside temperature on the cooling curve (°C)")
   hfs->provideSensor(this, leafpoint+   "main/Room_Heater_Operations_Hours",     tr("Electric heater operating time for Room (Hour)")
   hfs->provideSensor(this, leafpoint+   "main/DHW_Heater_Operations_Hours",      tr("Electric heater operating time for DHW (Hour)")
   hfs->provideSensor(this, leafpoint+   "main/Heat_Pump_Model",                  tr("Heat pump model, all values in HeatPumpType.md")
   hfs->provideSensor(this, leafpoint+   "main/Pump_Duty",                        tr("Pump duty")
   hfs->provideSensor(this, leafpoint+   "main/Zones_State",                      tr("Zones state (0 = zone1 active, 1 = zone2 active, 2 = zone1 and zone2 active)")
   hfs->provideSensor(this, leafpoint+   "main/Max_Pump_Duty",                    tr("Max pump duty configured")
   hfs->provideSensor(this, leafpoint+   "main/Heater_Delay_Time",                tr("Heater delay time (J-series only)")
   hfs->provideSensor(this, leafpoint+   "main/Heater_Start_Delta",               tr("Heater start delta (J-series only)")
   hfs->provideSensor(this, leafpoint+   "main/Heater_S_Delta",                   tr("Heater s delta (J-series only)")
   hfs->provideSensor(this, leafpoint+   "main/Buffer_Installed",                 tr("Buffer tank installed")
   hfs->provideSensor(this, leafpoint+   "main/DHW_Installed",                    tr("DHW tank installed")
   hfs->provideSensor(this, leafpoint+   "main/Solar_Mode",                       tr(" Solar mode disabled, to buffer, to DHW)")
   hfs->provideSensor(this, leafpoint+   "main/Solar_On_Delta",                   tr("Solar heating delta on")
   hfs->provideSensor(this, leafpoint+   "main/Solar_Off_Delta",                  tr("solar heating delta off")
   hfs->provideSensor(this, leafpoint+   "main/Solar_Frost_Protection",           tr("Solar frost protection temp")
   hfs->provideSensor(this, leafpoint+   "main/Solar_High_Limit",                 tr("Solar max temp limit")
   hfs->provideSensor(this, leafpoint+   "main/Pump_Flowrate_mode",               tr("Settings for pump flow rate (0=DeltaT, 1=Maximum flow, J-series only)")
   hfs->provideSensor(this, leafpoint+   "main/Liquid_Type",                      tr("Type of liquid in settings (Water / Glycol)")
   hfs->provideSensor(this, leafpoint+   "main/Alt_External_Sensor",              tr("If external outdoor sensor is selected")
   hfs->provideSensor(this, leafpoint+   "main/Anti_Freeze_Mode",                 tr("Is anti freeze mode enabled or disabled")
   hfs->provideSensor(this, leafpoint+   "main/Optional_PCB",                     tr("If the optional PCB is enabled (if installed)")
   hfs->provideSensor(this, leafpoint+   "main/Z2_Sensor_Settings",               tr("Setting of the sensor for zone 2 (water, ext thermostat, int. thermostat or thermistor)")
   hfs->provideSensor(this, leafpoint+   "main/Z1_Sensor_Settings",               tr("Setting of the sensor for zone 1 (water, ext thermostat, int. thermostat or thermistor)")
   hfs->provideSensor(this, leafpoint+   "main/Buffer_Tank_Delta",                tr("Delta of buffer tank setting in Kelvin")
   hfs->provideSensor(this, leafpoint+   "main/External_Pad_Heater",              tr("If the external pad heater is enabled (if installed)")


    //SETS
   SetHeatpump",                            tr("Set heatpump on or off  0=off, 1=on")
   SetHolidayMode",                         tr("Set holiday mode on or off  0=off, 1=on")
   SetQuietMode",                           tr("Set quiet mode level    0, 1, 2 or 3")
   SetPowerfulMode",                        tr("Set powerful mode run time in minutes   0=off, 1=30, 2=60 or 3=90")
   SetZ1HeatRequestTemperature",            tr("Set Z1 heat shift or direct heat temperature    -5 to 5 or 20 to max")
   SetZ1CoolRequestTemperature",            tr("Set Z1 cool shift or direct cool temperature    -5 to 5 or 20 to max")
   SetZ2HeatRequestTemperature",            tr("Set Z2 heat shift or direct heat temperature    -5 to 5 or 20 to max")
   SetZ2CoolRequestTemperature",            tr("Set Z2 cool shift or direct cool temperature    -5 to 5 or 20 to max")
   SetOperationMode",                       tr("Sets operating mode 0=Heat only, 1=Cool only, 2=Auto, 3=DHW only, 4=Heat+DHW, 5=Cool+DHW, 6=Auto+DHW")
   SetForceDHW",                            tr("Forces DHW (Operating mode should be set first to inlcude DWH mode (operation mode 3,4,5 or 6) to be effective. Please look at SET9 )   0, 1")
   SetDHWTemp",                             tr("Set DHW target temperature  40 - 75")
   SetForceDefrost",                        tr("Forces defrost routine  0, 1")
   SetForceSterilization",                  tr("Forces DHW sterilization routine    0, 1")
   SetPump",                                tr("Set Water Pump to service mode, max speed   0, 1")
   SetMaxPumpDuty,                          tr("Set max Water Pump duty in service menu decimal value translate to hexadecimal in service menu 64 to 254")
   SetCurves",                              tr("Set zones heat/cool curves  JSON document (see below)")
   SetZones",                               tr(" Set zones to active 0 = zone 1 active, 1 = zone2 active, 2 = zone1 and zone2 active")
   SetFloorHeatDelta",                      tr("Set floor heating delta in Kelvin   1-15")
   SetFloorCoolDelta",                      tr("Set floor cooling delta in Kelvin   1-15")
   SetDHWHeatDelta",                        tr("Set DHW heating delta in Kelvin -12 to -2 (negative value)")
   SetHeaterDelayTime",                     tr("Set heater start delay time (only J-series) in minutes")
   SetHeaterStartDelta",                    tr("Set heater start delta T (only J-series)    in kelvin")
   SetHeaterStopDelta",                     tr("Set heater stop delta T (only J-series) in kelvin")
   SetMainSchedule",                        tr("Set weekly schedule 0=off, 1=on")
   SetAltExternalSensor",                   tr("Set the alternative external outdoor sensor 0=disabled, 1=enabled")
   SetExternalPadHeater",                   tr("Set the external pad heater 0=disabled, 1=type-A, 2=type-B")
   SetBufferDelta",                         tr("Set buffer tank delta   0 - 10")


    To send Heating/Cooling Curves on topic SET16 you need to send a flattened JSON document. For example:

    {"zone1":{"heat":{"target":{"high":35,"low":25},"outside":{"high":15,"low":-15}},"cool":{"target":{"high":35,"low":25},"outside":{"high":15,"low":-15}}},"zone2":{"heat":{"target":{"high":35,"low":25},"outside":{"high":15,"low":-15}},"cool":{"target":{"high":35,"low":25},"outside":{"high":15,"low":-15}}}}

    The structure of the JSON document:
    {
        "zone1": {
            "heat": {
                "target": {
                    "high": 35,
                    "low": 25
                },
                "outside": {
                    "high": 15,
                    "low": -15
                }
            },
            "cool": {
                "target": {
                    "high": 35,
                    "low": 25
                },
                "outside": {
                 "high": 15,
                    "low": -15
                }
            }
        },
        "zone2": {
            "heat": {
                "target": {
                    "high": 35,
                    "low": 25
                },
                "outside": {
                    "high": 15,
                    "low": -15
                }
            },
            "cool": {
                "target": {
                    "high": 35,
                    "low": 25
                },
                "outside": {
                    "high": 15,
                    "low": -15
                }
            }
        }
    }

    But you are free to set only the value you need, for example:

    {
    "zone1": {
     "heat": {
         "outside": {
            "low": -15
        }
        }
    }
    }
*/
