/* The concept here is the following. HyperBorg would like to use both Widget and QML for 
* its visual interface, but there is one major difference. By default QGraphicsItem does 
* not inherit from QObject, while QQuickPainterItem does (mainly for the property system that is
* the backbone of QML usage. On source code level it makes the paint function not-really-reusable.
*  
* In order to keep the necesseary amount of code rewrite when switching from widgets to QML, 
* the paint feature is based on its own base class called PainterBase. Both carriers 
* (HUDItem for widget, HUDElement for QML) would be (re)designed to handle this for their
* paint operations. Althoug this does not cease the necessity to modify all classes when
* switching, but it would make that a lot easier. 
*/

#ifndef PAINTERBASE_H
#define PAINTERBASE_H

#include <QObject>
#include <QPainter>
#include <QString>
#include <QDateTime>

class PainterBase : public QObject
{
    Q_OBJECT
public:
    PainterBase(QObject* parent = nullptr) : QObject(parent) {}
    virtual ~PainterBase() {}

    virtual void paint(QPainter* painter, QRectF boundingrect) = 0;
};


class HUDButtonPainter : public PainterBase
{
    Q_OBJECT
public:
    HUDButtonPainter(QObject* parent = nullptr) : PainterBase(parent) 
    {
        _text = "TEST";
    }
    ~HUDButtonPainter() {}

    void paint(QPainter* painter, QRectF boundingrect) override;
private:
    QString _text;
};

class HUDCalendarPainter : public PainterBase
{
    Q_OBJECT
public:
    HUDCalendarPainter(QObject* parent = nullptr) : PainterBase(parent) {}
    ~HUDCalendarPainter() {}

    void paint(QPainter* painter, QRectF boundingrect) override;
};

class HUDClockPainter : public PainterBase
{
    Q_OBJECT
public:
    HUDClockPainter(QObject* parent = nullptr) : PainterBase(parent) {}
    ~HUDClockPainter() {}

    void paint(QPainter* painter, QRectF boundingrect) override;
};

#endif