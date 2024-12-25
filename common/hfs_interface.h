#ifndef HFS_INTERFACE
#define HFS_INTERFACE

#include <common.h>
#include <QObject>

class Flow;

class HFS_Interface
{
public:
    virtual ~HFS_Interface() {}

    // Registers a new topic. This function returns unique token to the caller that could identify itself
    // to the system in order to block malicious takeover of a topic

    virtual QString provides(QObject* obj,                          // The object that would keep this topic updated
                             const QString &topic,                         // The unique id of the topic (warning if overdriven!)
                             int hfs_flags          = HFS_None,              // Additional HFS flags
                             DataType datatype      = DT_String,    // Value representation for this topic
                             Unit unit              = NotDefined,   // Unit of the topic's value
                             const QString &regexp  = QString()     // Regexp expression to check data validity
                            ) = 0;

    virtual bool createAlias(const QString &existing_topic, const QString &alias_topic) = 0;
    virtual bool removeAlias(const QString &existing_topic, const QString &alias_topic) = 0;

    virtual QString nodeRole()          { return _noderole;  }
    virtual int devId()                 { return _devid;     }
    virtual void setDevId(int devid)    { _devid = devid;    }
    virtual QObject* getObject(const QString &path) = 0;

    // Attach a given object to a topic. When the topic is changed, this object would be called via
    // invokemethod
    virtual Flow *subscribe(QObject *obj,                                            // The object that request notification when the topic is changed
                           const QString &topic,                                           // The topic the object is attached (subscirbed) to
                           const QString &funcname=QString("topicChanged"),          // The obj's method name (slot) that would be called when topic is changed
                           const QString &keyidx=QString(),                                // If the function is a handles multiple topic, this key is added to the call for sorting out reason
                           HFS_Subscription_Flag subflag = HFSSF_AnyValueTrigger,   // When should be the object notified
                           Unit unit                     = NotDefined               // To which unit should the value to be converted before dispatch (if possible)
                           ) = 0;

    // Unsubscibes an object from a given topic
    virtual void unsubscribe(QObject *obj,
                             const QString &path,
                             const QString &funcname=QString("topicChanged")) = 0;

    virtual QStringList getSubList(const QString &path) = 0;

    // The data in HFS cannot be changed directly from the plugin/GUI side. It should be requested
    // If everything is fine (ACL accepted and regexp is ok) the value is changed and would be propagted system-wide
    // If ACL is not permitting or other issue happens, the event would be logged and the requested would be notified
    // via the general error handling path

    virtual int dataChangeRequest(QObject *requester,           // The object that is requesting the datachange, this object would be notified if
                                   const QString &sessionid,    // The device_sessionid.user_sessionid combo for ACL checking
                                   const QString &topic,               // The topic of which value change was requested
                                   QVariant val) = 0;           // The new requested value

    virtual QVariant getAttribute(const QString &topic,
                                  const QString &attributename,
                                  const QVariant &defvalue =QVariant()) = 0;

    virtual QVariant data(const QString &path) = 0;
    virtual QVariant childKeys(const QString &path) = 0;

    virtual void log(int severity, const QString &logline, const QString &source=QString("CORE")) = 0;
    virtual QString getRandomString(int length) = 0;

protected:
    QString _noderole;
    int _devid;
};

#endif