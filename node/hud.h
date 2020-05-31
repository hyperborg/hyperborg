#ifndef HUD_H
#define HUD_H

#include <QList>
#include <QWidget>
#include <QString>
#include <QStringList>
#include <QToolButton>
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
#include <QIcon>

#include <QQmlApplicationEngine>
#include "ui_hud.h"
#include "hudlabel.h"

class HUD : public QWidget
{
Q_OBJECT
public:
	HUD(QWidget* parent = nullptr);
	~HUD();

public slots:
	void timeChanged(QString time);
	void dateChanged(QString date);

protected:
	void resizeEvent(QResizeEvent* event);
	void generateBackground();
	void generateButtons();
	void applyStyleSheet(int idx = -1);
	void createQMLEngine();
	void createUI();

private:
	Ui::HUD ui;
	QList<QToolButton*> buttons;
	QQmlApplicationEngine *qmlengine;
};

#endif