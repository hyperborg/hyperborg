#ifndef HUDWire_H
#define HUDWire_H

#include <huditem.h>
#include <task.h>
#include <wire.h>

class HUDWire : public HUDItem
{
    Q_OBJECT
    Q_PROPERTY(QString wireID MEMBER _wireID);

public:
    HUDWire(QGraphicsItem* parent = nullptr);
    ~HUDWire();

    int type() const override { return HUDElementType::HET_Wire; }
    void paint(QPainter* painter) override;

    void setWire(Wire *w);
    Wire *wire();

    void load(QJsonObject obj) override;
    QJsonObject save() override;

public slots:

private:
    Wire *_wire;
    QString _wireID;
};

#endif