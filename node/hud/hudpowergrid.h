#ifndef HUDPowerGrid_H
#define HUDPowerGrid_H

#include "hudelement.h"

class HUDPowerGrid : public HUDElement
{
    Q_OBJECT
        QML_NAMED_ELEMENT(HUDPowerGrid)

public:
    HUDPowerGrid(QQuickItem* parent = nullptr);
    ~HUDPowerGrid();

    int type() const override { return HUDElementType::PowerGrid; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;

private:
    QPainterPath pv_batt;
    QPainterPath pv_grid;
    QPainterPath pv_load;
    QPainterPath batt_load;
    QPainterPath grid_load;
    QPainterPath batt_grid;

    QColor color_pv;
    QColor color_batt;
    QColor color_load;
    QColor color_grid;
    QColor color_icon;

    double d_width, d_height;
    int cx, cy;                     // center x and y lines
    int cr;                         // circle radius
    int cg;                         // gap between lines
    int bg;                         // Bezier gap
    int xo[3] = { 80, 225, 370 };
    int yo[3] = { 80, 225, 370 };

    QPixmap px_batt;
    QPixmap px_grid;
    QPixmap px_load;
    QPixmap px_pv;

    double val_batt_power;
    double val_batt_soc;
    double val_pv;
    double val_grid;
    double val_load;
};

#endif
