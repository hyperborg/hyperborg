#ifndef HUD_H
#define HUD_H

#include <QList>
#include <QWidget>
#include <QString>
#include <QStringList>
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
#include <QWindow>
#include <QLabel>
#include <QLineEdit>

#include <QQmlApplicationEngine>

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
	void createQMLEngine();
	void createUI();

private:
	QList<HUDButton*> buttons;
	QQmlApplicationEngine *qmlengine;
	QLabel* date_label;
	QLabel* hello_label;
};

#endif