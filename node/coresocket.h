#ifndef CORESOCKET_H
#define CORESOCKET_H

#include <QObject>
#include <QWebSocket>

class CoreSocket : public QWebSocket
{
Q_OBJECT
public:
    CoreSocket(const QString &origin = QString(), QWebSocketProtocol::Version version = QWebSocketProtocol::VersionLatest, QObject *parent = nullptr);
    ~CoreSocket();
};

#endif