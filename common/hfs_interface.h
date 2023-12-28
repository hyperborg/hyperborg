#ifndef HFS_INTERFACE
#define HFS_INTERFACE

#include <common.h>
#include <QObject>

class HFS_Interface
{
public:
    virtual ~HFS_Interface() {}

    // Registers a new topic. This function returns unique token to the caller that could identify itself
    // to the system in order to block malicious takeover of a topic

    virtual QString provides(QObject* obj,                          // The object that would keep this topic updated
                             QString topic,                         // The unique id of the topic (warning if overdriven!)
                             DataType datatype      = DT_String,    // Value representation for this topic
                             Unit unit              = NotDefined,   // Unit of the topic's value
                             int hfs_flags          = 0,            // Additional HFS flags
                             QString regexp         = QString()     // Regexp expression to check data validity
                            ) = 0;

    virtual bool providesAttribute(QObject* obj,                    // returns true if registration is successful
                            QString topic,                          // Topic that should be extended with this attribute (should be existing at this call)
                            QString attrname,                       // Name of the attribute (if already exists, it would be overwritten)
                            QVariant value = QVariant()             // Current value of the attribute
                            ) = 0;

    virtual QString nodeRole() { return _noderole;  }
    virtual QString devId()    { return _devid;     }

    // Attach a given object to a topic. When the topic is changed, this object would be called via
    // invokemethod
    virtual void subscribe(QObject *obj,                                            // The object that request notification when the topic is changed
                           QString topic,                                           // The topic the object is attached (subscirbed) to
                           QString funcname=QString("topicChanged"),          // The obj's method name (slot) that would be called when topic is changed
                           QString keyidx=QString(),                                // If the function is a handles multiple topic, this key is added to the call for sorting out reason
                           HFS_Subscription_Flag subflag = HFSSF_AnyValueTrigger,   // When should be the object notified
                           Unit unit                     = NotDefined               // To which unit should the value to be converted before dispatch (if possible)
                           ) = 0;

    // Unsubscibes an object from a given topic
    virtual void unsubscribe(QObject *obj,
                             QString path,
                             QString funcname=QString("topicChanged")) = 0;

    virtual QString providesSensor(QObject *obj, QString path,
        DataType datatype,
        Unit native_measurement,
        QString keyidx = QString(),
        int sub_precision =-1,
        int major_precision =-1) = 0;

    virtual void addDBHook( QString topic,
                            QString table,
                            QString columnname=QString(),
                            DBColumnType datatype = DBF_SameAsDataType,
                            int sub_precision=-1,
                            int major_precision=-1) = 0;

    virtual QStringList getSubList(QString path) = 0;

    // The data in HFS cannot be changed directly from the plugin/GUI side. It should be requested
    // If everything is fine (ACL accepted and regexp is ok) the value is changed and would be propagted system-wide
    // If ACL is not permitting or other issue happens, the event would be logged and the requested would be notified
    // via the general error handling path

    virtual int dataChangeRequest(QObject *requester,      // The object that is requesting the datachange, this object would be notified if
                                   QString sessionid,      // The device_sessionid.user_sessionid combo for ACL checking
                                   QString topic,          // The topic of which value change was requested
                                   QVariant val) = 0;      // The new requested value

    virtual QVariant getAttribute(QString topic,
                                  QString attributename,
                                  QVariant defvalue =QVariant()) = 0;

    virtual QObject* getObjectAttribute(QString topic) = 0;

    virtual QVariant data(QString path) = 0;
    virtual QVariant childKeys(QString path) = 0;

    virtual void log(int severity, QString logline, QString source) = 0;
    virtual QString getRandomString(int length) = 0;

protected:
    QString _noderole;
    QString _devid;
};

#endif