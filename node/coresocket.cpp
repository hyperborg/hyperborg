#include "coresocket.h"

CoreSocket::CoreSocket(const QString &origin, QWebSocketProtocol::Version version, QObject *parent) : QWebSocket(origin, version, parent)
{
}

CoreSocket::~CoreSocket()
{
}