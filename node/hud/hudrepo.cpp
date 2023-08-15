#include "hudrepo.h"

HUDRepo::HUDRepo(QGraphicsItem* parent) : HUDItem(parent)
{
    setFlag(QGraphicsItem::ItemClipsChildrenToShape,true);
    _offset = 0;
    resize(200, 800);
}

HUDRepo::~HUDRepo()
{
}

void HUDRepo::load(QJsonObject obj)
{
    HUDItem::load(obj);
}

QJsonObject HUDRepo::save()
{
    QJsonObject obj = HUDItem::save();
    return obj;
}


void HUDRepo::addItem(HUDItem *item)
{
    items.append(item);
}

void HUDRepo::paint(QPainter* painter)
{
    // collect general values
    int mx = size().width();
    int my = size().height();
    int cx = mx / 2;
    int cy = my / 2;

    // draw background
    QBrush brush(QColor(100, 100, 100));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, mx-2, my-2, 5, 5);
}

void HUDRepo::calculateGeometry()
{
}

void HUDRepo::calculateLayout()
{
    qreal gap = 10;
    qreal y   = 0;
    qreal _w  = size().width();

    for (int i=0;i<items.count();i++)
    {
        y+=gap;
        HUDItem *item = items.at(i);
        QSizeF size = item->size();
        if (size.width())
        {
            qreal wscale = _w/size.width();
            item->transform().reset();
            item->setScale(wscale);
            item->setPos(1, y);
        }
        y += item->size().height();
    }
    _max_offset = (qreal)qMax((qreal)0, (qreal)size().height()-y);
}


void HUDRepo::wheelEvent(QGraphicsSceneWheelEvent *e)
{
    if (e->buttons()==Qt::NoButton)
    {
        qreal oldoffset = _offset;
        int delta = e->delta();
        delta = delta*1.0;          // handling mouse sensitivity
        if (delta>0)                // mouse scrolled "away" from user
        {
            _offset-=delta;
            _offset = qMax(0, _offset);
        }
        else                        // mouse scrolled "towards" to user
        {
            _offset+=delta;
            _offset=qMin(_max_offset, _offset);
        }

        qreal _move = _offset-oldoffset;
        // move all elements to their new parent related position, clipping would take care of the
        // "non-fitting" ones

        for (HUDItem *item : items)
        {
            item->moveBy(0, _move);
        }
        update();
        return;
    }

    e->ignore();    // do nothing if scrolled when button is pressed
}


