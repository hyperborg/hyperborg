#ifndef HUDITEM_H
#define HUDITEM_H

#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QGraphicsWidget>
#include <QPainter>
#include <QPolygonF>
#include <QRectF>
#include <QColor>
#include <QPen>
#include <QBrush>
#include <QPolygonF>
#include <QPointF>
#include <QString>
#include <QStringList>
#include <QFont>
#include <QFontMetrics>
#include <QPixmap>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include "hfs.h"
#include "hfs_interface.h"
#include "painterbase.h"

class HUDFactory;

class HUDItem : public QGraphicsWidget
{
    Q_OBJECT
    Q_PROPERTY(QString id MEMBER _id);

public:
    HUDItem(QGraphicsItem *parent=nullptr,  Qt::WindowFlags wFlags = Qt::WindowFlags());

    virtual ~HUDItem();
    virtual int type() const override;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
    virtual void paint(QPainter* painter) { paint(painter, NULL, NULL); }

    void setHFS(HFS *hfs);
    void setPainterBase(PainterBase* pb)
    {
        painterbase = pb;
        update();
    }

    virtual QJsonObject save();
    virtual void load(QJsonObject obj);

    void setHUDFactory(HUDFactory *hf);
    HUDFactory *getHUDFactory();

public slots:
    virtual void calculateGeometry() {}

private:
    HFS *_hfs;
    HUDFactory *hudfactory;
    PainterBase* painterbase;
    QString _id;
};


#endif