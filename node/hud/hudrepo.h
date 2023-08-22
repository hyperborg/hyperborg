#ifndef HUDREPO_H
#define HUDREPO_H

#include <huditem.h>
#include <QGraphicsSceneWheelEvent>
#include <QTransform>

class HUDRepo : public HUDItem
{
Q_OBJECT
public:
    HUDRepo(QGraphicsItem* parent);
    ~HUDRepo();

    int type() const override { return HUDElementType::HET_Repo; }
    void paint(QPainter* painter) override;

    void addItem(HUDItem *item);

    void load(QJsonObject obj) override;
    QJsonObject save() override;

protected:
    void wheelEvent(QGraphicsSceneWheelEvent *ev) override;

public slots:
    void calculateGeometry() override;
    void calculateLayout();

private:
    QList<HUDItem *> items;

    int _offset;        // current offset of scrolling
    int _max_offset;    // maximum offset user cannot spin further
};

#endif