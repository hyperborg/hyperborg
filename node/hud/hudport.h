#ifndef HUDPort_H
#define HUDPort_H

#include <huditem.h>
#include <task.h>
#include <port.h>

class HUDPort : public HUDItem
{
    Q_OBJECT
    Q_PROPERTY(QString portID MEMBER _portID)
public:
    HUDPort(QGraphicsItem* parent = nullptr);
    ~HUDPort();

    int type() const override { return HUDElementType::HET_Port; }
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    void load(QJsonObject obj) override;
    QJsonObject save() override;

public slots:
private:
    QString _portID;
};

#endif