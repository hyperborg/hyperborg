#ifndef ColorRange_H
#define ColorRange_H

#include <QColor>

class ColorRange
{
public:
    ColorRange(double _from, double _to, QColor c)
    {
        from = _from;
        to = _to;
        color = c;

    }
    ColorRange(QColor c)
    {
        from = 0;
        to = 100;
        color = c;
    }
    ColorRange(double _to, QColor c)
    {
        from = 0;
        to = _to;
        color = c;
    }

    ~ColorRange() {}

    double from;
    double to;
    QColor color;

};

#endif
