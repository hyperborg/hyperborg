#ifndef HUDText_H
#define HUDText_H

#include <huditem.h>

class HUDText : public HUDItem
{
Q_OBJECT
public:
    HUDText(QGraphicsItem* parent = nullptr);
    ~HUDText();

    int type() const override { return HUDElementType::HET_Text; }
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    void setText(QString text);
    void setFont(QFont f);

    void load(QJsonObject obj) override;
    QJsonObject save() override;

public slots:
    void calculateGeometry() override;

private:
    QString _text;
    QFont _font;
    qreal _voffset;
};

#endif