#ifndef HUDLABEL_H
#define HUDLABEL_H

#include <QLabel>
#include <QString>
#include <QPainter>
#include <QWidget>
#include <QPen>
#include <QString>

#include "ui_hudlabel.h"

class HUDLabel : public QWidget
{
Q_OBJECT
public:
	HUDLabel(QWidget* parent = nullptr);
	~HUDLabel();

	void setText(QString str);
	void setInvert(bool flag);
protected:
	void paintEvent(QPaintEvent* event);

private:
	Ui::HUDLabel ui;
	bool invert;
};

#endif
