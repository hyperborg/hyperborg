#ifndef HUDElement_H
#define HUDElement_H

#include <QObject>
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

#include "hfs.h"
#include "colorrange.h"

enum HUDElementType
{
    Element         = QGraphicsItem::UserType + 1,
    Screen          = QGraphicsItem::UserType + 2,
    Button          = QGraphicsItem::UserType + 3,
    Gauge           = QGraphicsItem::UserType + 4,
    Clock           = QGraphicsItem::UserType + 5,
    Weather         = QGraphicsItem::UserType + 6,
    Garbage         = QGraphicsItem::UserType + 7,
    PowerGrid       = QGraphicsItem::UserType + 8,
    TimeTable       = QGraphicsItem::UserType + 9,
    TodoList        = QGraphicsItem::UserType + 10,
    EventList       = QGraphicsItem::UserType + 11,
    ShoppingList    = QGraphicsItem::UserType + 12,
    Calendar        = QGraphicsItem::UserType + 13,
    CalendarDay     = QGraphicsItem::UserType + 14,
    CalendarEntry   = QGraphicsItem::UserType + 15,
    HFSTree         = QGraphicsItem::UserType + 16,
    Library         = QGraphicsItem::UserType + 17,
    Navigator       = QGraphicsItem::UserType + 18

};

class HUDElement : public QQuickPaintedItem
{
    Q_OBJECT
public:
    HUDElement(QQuickItem* parent = nullptr);
    ~HUDElement();

    virtual void loadConfiguration(QJsonObject& json);
    virtual void saveConfiguration(QJsonObject& json);
    virtual int type() const;
    virtual void paint(QPainter* painter) {}

protected:
    virtual void mousePressEvent(QMouseEvent* e) 
    {
        qDebug() << "virtual mpe";
    }

public slots:
    void setElementProperty(QString key, QVariant value, int col);
    void setHFS(HFS* hfs);

signals:
    void itemChanged(QString path, QString value);              // Signal emitted when element had user or other interaction

protected:
    HFS *_hfs;
    void reColor(QPixmap *px, QColor c);
};


#endif