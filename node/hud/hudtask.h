#ifndef HUDTask_H
#define HUDTask_H

#include <huditem.h>
#include <task.h>
#include <hudport.h>
#include <hudpixmap.h>
#include <hudtext.h>

class HUDTask : public HUDItem
{
Q_OBJECT
public:
    HUDTask(QGraphicsItem* parent=nullptr);
    ~HUDTask();

    int type() const override { return HUDElementType::HET_Task; }
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    virtual int hasInput()  { return inports.count();   }
    virtual int hasOutput() { return outports.count();  }

    void addInputPort(HUDPort *port);
    void addOutputPort(HUDPort *port);
    void setLabel(QString label);
    void setLabelItem(HUDText *text);
    void setPixmap(HUDPixmap *pixmap);
    void setStatusPixmap(HUDPixmap *pixmap);
    void setStatusLabelItem(HUDText *text);
    void setStatusText(QString label);

    void clearInputPorts();
    void clearOutputPorts();

    void setStatusEnabled(bool flag);

    void load(QJsonObject obj) override;
    QJsonObject save() override;

public slots:
    void calculateGeometry() override;

private:
    QList<HUDPort*> inports;
    QList<HUDPort*> outports;
    HUDText *label;
    HUDPixmap* main_pixmap;             // main task pixmap
    HUDPixmap* status_pixmap;
    HUDText *status_label;
};

#endif