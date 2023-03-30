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

enum HUDElementType
{
    Element         = QGraphicsItem::UserType + 1,
    Magnet          = QGraphicsItem::UserType + 2,
    Screen          = QGraphicsItem::UserType + 3,
    Button          = QGraphicsItem::UserType + 4,
    Gauge           = QGraphicsItem::UserType + 5,
    Clock           = QGraphicsItem::UserType + 6,
    Weather         = QGraphicsItem::UserType + 7,
    Garbage         = QGraphicsItem::UserType + 8,
    PowerGrid       = QGraphicsItem::UserType + 9,
    TimeTable       = QGraphicsItem::UserType + 10,
    TodoList        = QGraphicsItem::UserType + 11,
    EventList       = QGraphicsItem::UserType + 12,
    ShoppingList    = QGraphicsItem::UserType + 13,
    Calendar        = QGraphicsItem::UserType + 14,
    CalendarDay     = QGraphicsItem::UserType + 15,
    CalendarEntry   = QGraphicsItem::UserType + 16,
    HFSTree         = QGraphicsItem::UserType + 17,
    Library         = QGraphicsItem::UserType + 18,
    Navigator       = QGraphicsItem::UserType + 19,
    ScreenSaver	    = QGraphicsItem::UserType + 20,
    ScreenManager   = QGraphicsItem::UserType + 21

};

class HUDElement : public QQuickPaintedItem
{
    Q_OBJECT
public:
    HUDElement(QQuickItem* parent = nullptr);
    ~HUDElement();

    virtual int type() const;
    virtual void paint(QPainter* painter);

public slots:
    void setElementProperty(QString key, QVariant value);
    void setHFS(HFS* hfs);

protected:
    HFS *_hfs;
    QWidget* widget;
    void reColor(QPixmap *px, QColor c);
};

#endif