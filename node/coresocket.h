#ifndef CORESOCKET_H
#define CORESOCKET_H

#include <QObject>
#include <QWebSocket>
#include <QDebug>
#include <QSslPreSharedKeyAuthenticator>
#include <QNetworkProxy>
#include <QAuthenticator>
#include <common.h>

class CoreSocket : public QWebSocket
{
Q_OBJECT
public:
    CoreSocket(const QString &origin = QString(), QWebSocketProtocol::Version version = QWebSocketProtocol::VersionLatest, QObject *parent = nullptr);
    ~CoreSocket();

private slots:

    void slot_aboutToClose();
    void slot_binaryFrameReceived(const QByteArray &frame, bool isLastFrame);
    void slot_binaryMessageReceived(const QByteArray &message);
    void slot_bytesWritten(qint64 bytes);
    void slot_connected();
    void slot_disconnected();
    void slot_error(QAbstractSocket::SocketError error);
    void slot_pong(quint64 elapsedTime, const QByteArray &payload);
//    void slot_preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenticator);
    void slot_proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator);
    void slot_readChannelFinished();
    void slot_sslErrors(const QList<QSslError> &errors);
    void slot_stateChanged(QAbstractSocket::SocketState state);
    void slot_textFrameReceived(const QString &frame, bool isLastFrame);
    void slot_textMessageReceived(const QString &message);

};

#endif