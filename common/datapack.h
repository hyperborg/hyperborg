#ifndef DATAPACK_H
#define DATAPACK_H

#include "common.h"

class CoreServer;
class UniCore;
class Slotter;
class HyObject;
class HFS;

class DataPack
{
    friend class CoreServer;
    friend class UniCore;
    friend class Slotter;
    friend class HyObject;
    friend class HFS;

public:
     DataPack()
     {
         reset();
     }

     DataPack(int command, QString text=QString())
     {
         reset();
         _command = command;
         setText(text);
     }

    DataPack(QString text)
    {
        reset();
        _command = Message;
        setText(text);
    }

    DataPack(int command, QByteArray ar)
    {
        reset();
        _command = command;
        setBinary(ar);
    }

    DataPack(QByteArray ar)
    {
        reset();
        _command = Message;
        setBinary(ar);
    }

    DataPack(const DataPack* old)
    {
        _command        = old->_command;
        _isText         = old->_isText;
        _MIMEType       = old->_MIMEType;
        _text_payload   = old->_text_payload;
        _binary_payload = old->_binary_payload;
        attributes      = old->attributes;
        _src_device     = old->_src_device;
        _dst_device     = old->_dst_device;
        _compressed     = old->_compressed;
        _socket_id      = old->_socket_id;
     }

    virtual ~DataPack() {}

    void reset()
    {
        _command = CommandNotDefined;
        _compressed = false;
        _dst_device = 0;
        _src_device = 0;
        _socket_id  = -1;
        _isText     = true;
        attributes.clear();
    }

    static int serialize(DataPack* pack)               // we fill the the block with the sended data (binary or text)
    {                                                  // we could apply format versioning here, or compressing data
        if (!pack) return 0;

        QStringList retlst;

        // We overwrite the attributes before serialization. This way if an entity would
        // create the same value (badly behaving), it is overwritten here
        pack->attributes.insert("$$COMMAND", pack->_command);
        pack->attributes.insert("$$PSRCDEV", pack->_src_device);
        pack->attributes.insert("$$PDSTDEV", pack->_dst_device);

        // Text playload is converted to base64
        int idn = pack->_text_payload.indexOf("\n");
        if (idn==-1) idn = pack->_text_payload.indexOf("\"");
        if (idn==-1) idn = pack->_text_payload.indexOf(";");
        if (idn!=-1)
        {
            QByteArray ba = pack->_text_payload.toUtf8();
            pack->_text_payload = ba.toBase64(QByteArray::Base64Encoding | QByteArray::OmitTrailingEquals);
            pack->_MIMEType = "text/base64";
        }

        pack->attributes.insert("$$TEXTPAY",  pack->_text_payload);
        pack->attributes.insert("$$MIMETYPE", pack->_MIMEType);

        QHashIterator<QString, QVariant> it(pack->attributes);
        while (it.hasNext())
        {
            it.next();
            retlst << QString(it.key() + "=" + it.value().toString());
        }
        pack->setText(retlst.join("\n"));
        return 1;
    }

    static int deserialize(DataPack* pack)              // we extract attributes from the text/binary data received 
    {                                                   // through socket. We could apply format versioning here or
                                                        // decompressing data
        int retint = 1;
        if (!pack) return 0;
        if (pack->isText())
        {
            pack->attributes.clear();
            QStringList lst = pack->_text_payload.split("\n");
            for (int i = 0; i < lst.count(); i++)
            {
                QStringList wlst = lst.at(i).split("=");
                if (wlst.count() == 2)
                {
                    pack->attributes.insert(wlst.at(0), wlst.at(1));
                }
            }
            // Regenerating control values from the list
            // We assume that we get package from other Unicore, not any other source
            // Anyway, it might be wise to put some checks before this point to
            // catch man-in-the-middle attacks
            QString str = pack->attributes.value("$$COMMAND", "").toString();
            pack->_command      = pack->attributes.value("$$COMMAND", "").toInt();
            pack->_src_device   = pack->attributes.value("$$PSRCDEV", "").toInt();
            pack->_dst_device   = pack->attributes.value("$$PDSTDEV", "").toInt();
            pack->_MIMEType     = pack->attributes.value("$$MIMETYPE", "text/plain").toString();
            pack->_text_payload = pack->attributes.value("$$TEXTPAY", "").toString();

            if (pack->_MIMEType=="text/base64")
            {
                QByteArray ba = pack->_text_payload.toUtf8();
                pack->_text_payload = QByteArray::fromBase64(ba, QByteArray::Base64Encoding | QByteArray::OmitTrailingEquals);
                pack->_MIMEType = "text/plain";
            }
        }
        else // binary - we do not process it yet
        {
        }
         return retint;
    }

    QString textPayload()       { return _text_payload;         }
    QByteArray binaryPayload()  { return _binary_payload;       }

    int command()               { return _command;              }
    bool isText()               { return _isText;               }
    QString MIMEType()          { return _MIMEType;             }
    bool compressed()           { return _compressed;           }

    QString getStringAttribute(QString key) { return attributes.value(key).toString(); }

    QHash<QString, QVariant> attributes;
    inline void setAttribute(QString key, QVariant val)
    {
        attributes.insert(key, val);
    }

    void setCommand(int command)          { _command = command;       }
    void setSource(int deviceid)          { _src_device = deviceid;   }
    void setDestination(int deviceid)     { _dst_device = deviceid;   }
    void setSocketId(int socketid)        { _socket_id = socketid;    }
    int sourceDevice()                    { return _src_device;       }
    int destinationDevice()               { return _dst_device;       }
    int socketId()                        { return _socket_id;        }

protected:
    void setText(QString txt)
    {
        _isText = true;
        _MIMEType = "text/plain";
        _text_payload = txt;
    }

    void setBinary(QByteArray arr)
    {
        _isText = false;
        _binary_payload = arr;
    }

protected:
    int         _command;
    bool        _compressed;                // true, if the content of this pack is compressed
    bool        _isText;                    // true, if the payload should be handled as text (_text_payload is filled)
                                            // otherwise _binary_payload is filled
    QString     _MIMEType;                  // contains the MIME typpe of the payload, regardless whether it is a text or not
    QString     _text_payload;
    QByteArray  _binary_payload;
    int         _src_device;                // The id of the node that actully sent the package
    int         _dst_device;                // The list of target node ids or * for all. "," is used as a separator
    int         _socket_id;
};

#endif