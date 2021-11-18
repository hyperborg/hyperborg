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
#include "hudscene.h"
#include "hudengine.h"

//POC include
#include <QQmlApplicationEngine>
#include <QChartView>
#include <QChart>
#include <QLineSeries>

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
	void slot_logLine(int severity, QString str, QString source=QString());
	void slot_logLineHUD(QString str);

signals:
	void logLine(int severity, QString str, QString source);

private slots:
	void slot_navClicked(int idx);

protected:
	void resizeEvent(QResizeEvent* event);
	void generateBackground();
	void applyStyleSheet(int idx = -1);
	void createUI();
	void createNavigation();
	void createScene();

private:
	Ui::HUD ui;
	QButtonGroup bgroup;
	Slotter *_slotter;
	QButtonGroup* nav_group;
	HUDScene* hudscene;
	HUDView* hudview;
	QStringList loglines;
	QQmlApplicationEngine* qmlengine;
};

#endif
