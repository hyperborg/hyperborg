#ifndef HUDELEMENTS_H
#define HUDELEMENTS_H

#include <QDebug>
#include <QObject>
#include <QString>
#include <QPushButton>
#include <QToolButton>
#include <QVariant>

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

class HUDButton : public QToolButton
{
Q_OBJECT
public:
    HUDButton(QWidget* parent) : QToolButton(parent)
    {
	setCheckable(true);
	QObject::connect(this, SIGNAL(clicked()), this, SLOT(slot_clicked()));
	QObject::connect(this, SIGNAL(toggled(bool)), this, SLOT(slot_toggled(bool)));
    }
    ~HUDButton() {}

signals:
    void requestChange(QString id, QVariant value, bool finish);

public slots:
    void valueChanged(QHash<QString, QVariant> vals)
    {
	qDebug() << "HUDB vals.count() " << vals.count();
	qDebug() << "status: " << vals.value("status", -1).toInt();
	valueChanged(vals.value("status", 0).toInt());
    }

    void valueChanged(int value)
    {
	if (isCheckable())
	{
	    qDebug() << "Button " << text() << " set checked state to: " << value;
	    setChecked(value);
	}
    }

protected slots:
    void slot_clicked()
    {
	printf("SLOT_CLICKED \n");
	if (isCheckable()) return;
	emit requestChange("status", 1, true);
    }

    void slot_toggled(bool flag)
    {
	printf("SLOT TOGGLED\n");
	if (!isCheckable()) return;
	emit requestChange("status", isChecked()?"1":"0", true);
    }

private:
	QString name;
	QString value;
};

#endif
