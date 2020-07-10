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

/* Non-interactive button mainly for system status feedback
*/

class HUDLED : public QLabel
{
    Q_OBJECT
public:
    HUDLED(QWidget* parent) : QLabel(parent)
    {
        // should install eventfilter here 
        // so user could not acti
    }
    ~HUDLED() {}

public slots:
    void valueChanged(QHash<QString, QVariant> vals)
    {
        valueChanged(vals.value("status", 0).toInt());
    }

    virtual void valueChanged(int value)
    {
        if (value == 0)
        {
            setStyleSheet("background-color: rgb(255, 0, 0);");
        }
        else
        {
            setStyleSheet("background-color: rgb(0, 170, 0);");
        }
    }

private:
    QString name;
    QString value;
};


#endif
