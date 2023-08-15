#ifndef HUDElement_H
#define HUDElement_H

#include <QObject>
#include <QWidget>
#include <QQuickPaintedItem>
#include <QColor>
#include <QPen>
#include <QBrush>
#include <QGraphicsEffect>
#include <QGraphicsItem>
#include <QString>
#include <QStringList>
#include <QHash>
#include <QHashIterator>
#include <QMap>
#include <QPalette>
#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QLineF>
#include <QVariant>
#include <QFont>
#include <QFontMetrics>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QRadialGradient>
#include <QMouseEvent>
#include <QFontMetrics>
#include <QDateTime>
#include <QPixmap>
#include <QPainterPath>
#include <QPolygon>
#include <QPolygonF>
#include <QPoint>
#include <QPointF>
#include <QLinearGradient>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkCookie>

#include <QGraphicsPolygonItem>

#include "hfs.h"
#include "colorrange.h"
#include "guicommon.h"

class HUDElement : public QQuickPaintedItem
{
    Q_OBJECT
public:
    HUDElement(QQuickItem* parent = nullptr);
    ~HUDElement();

    virtual int type() const;
    virtual void paint(QPainter* painter);

public slots:
    void topicChanged(QString key, QVariant value);
    void setHFS(HFS* hfs);

protected:
    HFS *_hfs;
    QWidget* widget;
    void reColor(QPixmap *px, QColor c);
};

#endif
