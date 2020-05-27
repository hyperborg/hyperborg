#ifndef HUD_H
#define HUD_H

#include <QList>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QStringList>
#include <QGraphicsEffect>
#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QPen>
#include <QPixmap>
#include <QEvent>
#include <QRect>
#include <QPushButton>

class HUDButton : public QPushButton
{
Q_OBJECT
public:
	HUDButton(QWidget* parent = nullptr);
	~HUDButton();

protected:
	void resizeEvent(QResizeEvent* event);
	void paintEvent(QPaintEvent* event);

};

class HUD : public QWidget
{
Q_OBJECT
public:
	HUD(QWidget* parent = nullptr);
	~HUD();

protected:
	void resizeEvent(QResizeEvent* event);
	void generateBackground();

private:
	QList<HUDButton*> buttons;
};

#endif