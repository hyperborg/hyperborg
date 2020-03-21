#include "coresocket.h"

CoreSocket::CoreSocket(const QString &origin, QWebSocketProtocol::Version version, QObject *parent) : QWebSocket(origin, version, parent)
{
    connect(this, &QWebSocket::aboutToClose, this, &CoreSocket::slot_aboutToClose);
    connect(this, &QWebSocket::binaryFrameReceived, this, &CoreSocket::slot_binaryFrameReceived);
    connect(this, &QWebSocket::binaryMessageReceived, this, &CoreSocket::slot_binaryMessageReceived);
    connect(this, &QWebSocket::bytesWritten, this, &CoreSocket::slot_bytesWritten);
    connect(this, &QWebSocket::connected, this, &CoreSocket::slot_connected);
    connect(this, &QWebSocket::disconnected, this, &CoreSocket::slot_disconnected);
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slot_error(QAbstractSocket::SocketError)));
    connect(this, &QWebSocket::pong, this, &CoreSocket::slot_pong);
//    connect(this, &QWebSocket::preSharedKeyAuthenticationRequired, this, &CoreSocket::slot_preSharedKeyAuthenticationRequired);
    connect(this, &QWebSocket::proxyAuthenticationRequired, this, &CoreSocket::slot_proxyAuthenticationRequired);
    connect(this, &QWebSocket::readChannelFinished, this, &CoreSocket::slot_readChannelFinished);
    connect(this, &QWebSocket::sslErrors, this, &CoreSocket::slot_sslErrors);
    connect(this, &QWebSocket::stateChanged, this, &CoreSocket::slot_stateChanged);
    connect(this, &QWebSocket::textFrameReceived, this, &CoreSocket::slot_textFrameReceived);
    connect(this, &QWebSocket::textMessageReceived, this, &CoreSocket::slot_textMessageReceived);
}

CoreSocket::~CoreSocket()
{
}

void CoreSocket::slot_aboutToClose()
{
    qDebug() << "aboutToClose";
}

void CoreSocket::slot_binaryFrameReceived(const QByteArray &frame, bool isLastFrame)
{
    qDebug() << "binaryFrameReceived";
}

void CoreSocket::slot_binaryMessageReceived(const QByteArray &message)
{
    qDebug() << "binaryMessageReceived";
}

void CoreSocket::slot_bytesWritten(qint64 bytes)
{
    qDebug() << "bytesWritten";
}

void CoreSocket::slot_connected()
{
    qDebug() << "connected";
}

void CoreSocket::slot_disconnected()
{
    qDebug() << "disconnected";
}

void CoreSocket::slot_error(QAbstractSocket::SocketError error)
{
    qDebug() << "error";
}

void CoreSocket::slot_pong(quint64 elapsedTime, const QByteArray &payload)
{
    qDebug() << "pong";
}

//void CoreSocket::slot_preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenticator)
//{
//    qDebug() << "preSharedKeyAuthenticationRequired";
//}

void CoreSocket::slot_proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator)
{
    qDebug() << "proxyAuthenticationRequired";
}

void CoreSocket::slot_readChannelFinished()
{
    qDebug() << "readChannelFinished";
}

void CoreSocket::slot_sslErrors(const QList<QSslError> &errors)
{
    qDebug() << "sslErrors";
}

void CoreSocket::slot_stateChanged(QAbstractSocket::SocketState state)
{
    qDebug() << "stateChanged";
}

void CoreSocket::slot_textFrameReceived(const QString &frame, bool isLastFrame)
{
    qDebug() << "textFrameReceived";
}

void CoreSocket::slot_textMessageReceived(const QString &message)
{
    qDebug() << "textMessageReceived";
}
