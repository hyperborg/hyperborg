#ifndef HUDCalendar_H
#define HUDCalendar_H

#include "hudelement.h"

#include <QColor>
#include <QString>
#include <QDateTime>
#include <QStringList>
#include <QRect>
#include <QFont>
#include <QFontMetrics>


class HUDCalendarEntry: public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDCalendarEntry);

    Q_PROPERTY(QString time MEMBER _time);
    Q_PROPERTY(QString text MEMBER _text);

public:
    HUDCalendarEntry(QQuickItem *parent = nullptr);
    ~HUDCalendarEntry();

    int type() const override { return HUDElementType::CalendarEntry; }

    void paint(QPainter* painter) override;

protected:
    QString _time;
    QString _text;
};


class HUDCalendarDay : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDCalendarDay);

public:
    HUDCalendarDay(QQuickItem *parent = nullptr);
    ~HUDCalendarDay();

    int type() const override { return HUDElementType::CalendarDay; }

    void paint(QPainter* painter) override;

private:

};

class HUDCalendar : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDCalendar)

    Q_PROPERTY(QString mode MEMBER _mode);  // mode: 1-day, 2-week, 3-weeks, 4-month
    Q_PROPERTY(QDate year MEMBER _date);

public:
    HUDCalendar(QQuickItem* parent = nullptr);
    ~HUDCalendar();

    int type() const override { return HUDElementType::Calendar; }

    void paint(QPainter* painter) override;

protected:
    void calculateInternalGeometry();
    void paintDay(QRect rect);

protected slots:

private:
    QString _mode;			        // possible values are: "day", "week", "weeks", "month"
    QDate _date;
    int _colcnt, _rowcnt;
    QList<int> hlines, vlines;		// starting coordinsates of horizontal and vertical lines
    QStringList hheaders;           // horizontal header entries
    QStringList vheaders;           // vertical header entries
    QStringList cheaders;           // cell headers
    QRect carea;			        // Calendar area where the days are 

    

};

#endif