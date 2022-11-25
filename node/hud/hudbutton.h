#ifndef HUDButton_H
#define HUDButton_H

#include <hudelement.h>

class HUDButton : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDButton)
    Q_PROPERTY(QString text MEMBER _text WRITE setText)
    Q_PROPERTY(QString subtext MEMBER _subtext WRITE setSubText)
    Q_PROPERTY(QVariant value MEMBER _val WRITE setValue)
    
    Q_PROPERTY(QColor colorOff MEMBER color_off)
    Q_PROPERTY(QColor colorPending MEMBER color_pend)
    Q_PROPERTY(QColor colorForbidden MEMBER color_forbidden)
    Q_PROPERTY(QColor colorOn MEMBER color_on)

public:
    HUDButton(QQuickItem* parent = nullptr);
    ~HUDButton();

    int type() const override { return HUDElementType::Button; }
    void paint(QPainter* painter) override;

public slots:
    void mousePressed(int x, int y, int butt);
    void setValue(QVariant var)
    {
        setValue(var.toDouble());
        update();
    }

    void setText(QString txt)
    {
        _text = txt;
        update();
    }

    void setSubText(QString txt)
    {
        _subtext = txt;
        update();
    }

    void setValue(double val)
    {
        _val = val;
        update();
    }

private:
    QString _text;
    QString _subtext;
    int _val;

    QColor color_off;           // these should be in some list
    QColor color_pend;
    QColor color_forbidden;
    QColor color_on;
};

#endif