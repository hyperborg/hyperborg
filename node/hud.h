#ifndef HUD_H
#define HUD_H

#include <QDebug>
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
#include <QButtonGroup>

#include "ui_hud.h"
#include "hudlabel.h"
#include "slotter.h"
#include "hudelements.h"
#include "codeeditor.h"

//POC include
#include <QQmlApplicationEngine>
#include <QChartView>
#include <QChart>
#include <QLineSeries>
QT_CHARTS_USE_NAMESPACE

class HUD : public QWidget
{
Q_OBJECT
public:
	HUD(QWidget* parent = nullptr);
	~HUD();
	void setSlotter(Slotter *slotter);

public slots:
	void timeChanged(QString time);
	void dateChanged(QString date);
	void slot_logLine(QString str);

protected:
	void resizeEvent(QResizeEvent* event);
	void generateBackground();
	void applyStyleSheet(int idx = -1);
	void createQMLEngine();
	void createUI();

	void createTestElements();

private:
	Ui::HUD ui;
	QList<HUDButton*> buttons;
	QQmlApplicationEngine *qmlengine;
	int logcnt;
	QButtonGroup bgroup;
	Slotter *_slotter;
};

#endif