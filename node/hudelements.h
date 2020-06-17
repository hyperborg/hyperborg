#ifndef HUDELEMENTS_H
#define HUDELEMENTS_H

#include <QObject>
#include <QString>
#include <QPushButton>

class HUDElement
{
public:
	HUDElement(QWidget *gui) {}
	~HUDElement() {}
};

class SmartGrid : public QObject
{
Q_OBJECT
public:
	SmartGrid(QObject* parent = nullptr) : QObject(parent) {}
};

/* Simple clickable button
*/

class HUDButton : public QPushButton
{
	Q_OBJECT
public:
	HUDButton(QWidget* parent) : QPushButton(parent)
	{
		QObject::connect(this, SIGNAL(clicked()), this, SLOT(slot_clicked()));
		QObject::connect(this, SIGNAL(checked(bool)), this, SLOT(slot_checked(bool)));
	}
	~HUDButton() {}

signals:
	void requestChange(int value);

public slots:
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
		emit requestChange(1);
	}

	void slot_slot_checked(bool flag)
	{
		if (!isCheckable()) return;
		emit requestChange(flag);
	}

private:
	QString name;
	QString value;
};

#endif
