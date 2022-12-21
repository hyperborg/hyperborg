#ifndef HUDLog_H
#define HUDLog_H

#include "hudelement.h"
#include <QTextBrowser>

class HUDLog : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDLog)

public:
    HUDLog(QQuickItem* parent = nullptr);
    ~HUDLog();

//    int type() const override { return HUDElementType::TodoList; }
//    void paint(QPainter* painter) override;

private:
    QTextBrowser* browser;
};

#endif