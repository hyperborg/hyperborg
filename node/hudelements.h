#ifndef HUDELEMENTS_H
#define HUDELEMENTS_H

#include <QDebug>
#include <QObject>
#include <QString>
#include <QPushButton>
#include <QToolButton>
#include <QVariant>
#include <QStringList>
#include <QLabel>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QString>
#include <QGraphicsItem>

/* Simple clickable button, mainly for navigation
*/

class HUDElement : public QGraphicsRectItem
{
public:
    HUDElement(QGraphicsItem* parent = NULL) : QGraphicsRectItem(parent) {}
    ~HUDElement() {}

    virtual int type() const override { return QGraphicsRectItem::type(); }
};

class NavButton : public QToolButton
{
Q_OBJECT
public:
    NavButton(QWidget* parent) : QToolButton(parent)
    {
		setCheckable(true);
		QObject::connect(this, SIGNAL(clicked()), this, SLOT(slot_clicked()));
		QObject::connect(this, SIGNAL(toggled(bool)), this, SLOT(slot_toggled(bool)));
    }
    ~NavButton() {}

signals:
    void requestChange(QString id, QVariant value, bool finish);

public slots:
    void valueChanged(QHash<QString, QVariant> vals)
    {
		valueChanged(vals.value("status", 0).toInt());
    }

    void valueChanged(int value)
    {
	if (isCheckable())
		{
			setChecked(value);
		}
    }

protected slots:
    void slot_clicked()
    {
		if (isCheckable()) return;
		emit requestChange("status", 1, true);
    }

    void slot_toggled(bool flag)
    {
		if (!isCheckable()) return;
		emit requestChange("status", isChecked()?"1":"0", true);
    }

private:
	QString name;
	QString value;
};

// -------------------------------------------------- ELEMENTS USUABLE ON HUD CANVAS ---------------------------------------
// HUDButton has 4 main parts: upper text, lower text, feedback line and background color
//
//
class HUDButton : public QGraphicsRectItem
{
public:
    HUDButton(QGraphicsItem* parent = nullptr) : QGraphicsRectItem(parent)
    {
        generateLayout();
    }
    ~HUDButton() 
    {}

    void generateLayout();
    void setText(QString utext = QString(), QString ltext = QString());

private:
    QGraphicsTextItem* uppertext;
    QGraphicsLineItem* feedback_line;
    QGraphicsTextItem* lowertext;

};


#endif
