#include "hudcalendar.h"

//======================================== HUDCalendarEntry =================================================
HUDCalendarEntry::HUDCalendarEntry(QQuickItem* parent) : HUDElement(parent)
{
}

HUDCalendarEntry::~HUDCalendarEntry()
{
}

void HUDCalendarEntry::paint(QPainter* painter)
{
}


//======================================== HUDCalendarDay =================================================

HUDCalendarDay::HUDCalendarDay(QQuickItem* parent) : HUDElement(parent)
{
}

HUDCalendarDay::~HUDCalendarDay()
{
}

void HUDCalendarDay::paint(QPainter* painter)
{
}

//======================================== HUDCalendar =================================================

HUDCalendar::HUDCalendar(QQuickItem* parent) : HUDElement(parent)
{
    _mode = "week";
    _date = QDate::currentDate();
    calculateInternalGeometry();
    update();
}

HUDCalendar::~HUDCalendar()
{
}

void HUDCalendar::calculateInternalGeometry()
{
    int w = width();
    int h = height();

    if (!w || !h) return;

    // clear cache entries
    hlines.clear();
    vlines.clear();
    hheaders.clear();
    vheaders.clear();
    cheaders.clear();

    // setup basic values
    int hh = 0;         // horizontal header height
    int vh = 0;         // vertical header height
    _colcnt = 1;
    _rowcnt = 1;
    QFont font("Arial");
    QFontMetrics fm(font);
    hh = fm.height();

    _mode = _mode.toLower();
    if (_mode == "day")
    {
        _colcnt = 24;
        _rowcnt = 1;
        vh = fm.horizontalAdvance("88:88");
    }
    else if (_mode == "week")
    {
        _colcnt = 24;
        _rowcnt = 7;

        QDate tdate = _date;
        int siw = tdate.dayOfWeek();                                      // start in the week
        for (int i = 0; i < siw - 1; ++i) tdate = tdate.addDays(-1);   // step back to Monday

        // generate cell headers
        for (int i = 0; i <  7; ++i)
        {
            QString cheader;
            int cday = tdate.day();
            int cdim = tdate.daysInMonth();
            if (cday == 1 || cday == cdim)
            {
                cheader = tdate.toString("MMM") + ". ";
            }
            cheader += QString::number(cday);
            hheaders.append(cheader);
            tdate = tdate.addDays(1);
        }

        for (int i = 0; i < _colcnt; ++i)
        {
            vheaders.append(QString::number(i) + ":00");
        }
    }
    else if (_mode == "weeks")
    {
        _colcnt = 7;
        _rowcnt = 4;

        QDate tdate = _date;
        int siw = tdate.dayOfWeek();                                      // start in the week
        for (int i = 0; i < siw-1; ++i) tdate = tdate.addDays(-1);   // step back to Monday

        // generate cell headers
        for (int i = 0; i < _rowcnt * 7; ++i)
        {
            QString cheader;
            int cday = tdate.day();
            int cdim = tdate.daysInMonth();
            if (cday == 1 || cday == cdim)
            {
                cheader = tdate.toString("MMM") + ". ";
            }
            cheader += QString::number(cday);
            cheaders.append(cheader);
            tdate = tdate.addDays(1);
        }
    }
    else if (_mode == "month")
    {
        _colcnt = 7;
        QDate tdate;
        tdate.setDate(_date.year(), _date.month(), 1);
        int siw = tdate.dayOfWeek();                                        // start in the week
        int dim = tdate.daysInMonth();                                      // days in the month
        for (int i = 0; i < siw-1; ++i) tdate = tdate.addDays(-1);     // step back to Monday
        int tday = (siw - 1) + dim;
        int fw = tday / 7;                                                  // how many full weeks we have
        int fd = tday % 7;                                                  // the last week fills this many days within the current month
        int pd = 7 - fd;                                                    // this many days should be padded as an extra

        if (pd == 0) _rowcnt = fw;
        else _rowcnt = fw + 1;

        // generate cell headers
        for (int i = 0; i < _rowcnt * 7;++i)
        {
            QString cheader;
            int cday = tdate.day();
            int cdim = tdate.daysInMonth();
            if (cday == 1 || cday == cdim)
            {
                cheader = tdate.toString("MMM") + ". ";
            }
            cheader += QString::number(cday);
            cheaders.append(cheader);
            tdate = tdate.addDays(1);
        }
    }

    // horizontal lines 
    int hgap = (h - hh) / _colcnt;
    for (int i = 0; i < _colcnt; ++i)
    {
        hlines.append(i * hgap);
    }

    // vertical lines;
    int vgap = (w - vh) / _rowcnt;
    for (int i = 0; i < _rowcnt; ++i)
    {
        vlines.append(i * vgap);
    }
}

void HUDCalendar::paint(QPainter* painter)
{
    calculateInternalGeometry();

    // draw grid
    int w = width();
    int h = height();

    QPen pen(Qt::white);
    painter->setPen(pen);

    if (!hlines.count() || !vlines.count())
    {
        return;
    }

    // draw frame
    painter->drawRect(0, 0, w-1, h-1);


    // draw horizontal lines
    int sx = vlines.at(0);
    for (int i = 0; i < hlines.count(); ++i)
    {
        int y = hlines.at(i);
        painter->drawLine(sx, y, w, y);
    }

    int sy = hlines.at(0);
    // draw vertical lines
    for (int i = 0; i < vlines.count(); ++i)
    {
        int x = vlines.at(i);
        painter->drawLine(x, sy, x, h);
    }

    // draw contents

    if (_mode == "day")
    {
    }
    else if (_mode == "week")
    {
        for (int x = 0; x < hheaders.count(); ++x)
        {
            painter->drawText(vlines.at(x), 15, hheaders.at(x));
        }

        for (int y = 0; y < vheaders.count(); ++y)
        {
            painter->drawText(2, hlines.at(y), vheaders.at(y));
        }
    }
    if (_mode == "weeks" || _mode == "month")
    {
        for (int x = 0; x < vlines.count(); ++x)
        {
            for (int y = 0; y < hlines.count(); ++y)
            {
                int idx = y * 7 + x;
                painter->drawText(vlines.at(x)+2, hlines.at(y)+15, cheaders.at(idx));
            }
        }
    }
}


