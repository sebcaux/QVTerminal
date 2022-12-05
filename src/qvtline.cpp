#include "qvtline.h"

QVTLine::QVTLine()
{
}

void QVTLine::append(const QVTChar &c)
{
    _chars.append(c);
}

void QVTLine::insert(const QVTChar &c, int pos)
{
    if (pos > _chars.size())
    {
        return;
    }
    _chars.insert(pos, c);
}

void QVTLine::replace(const QVTChar &c, int pos)
{
    if (pos > _chars.size())
    {
        return;
    }
    if (pos < _chars.size())
    {
        _chars[pos] = c;
        return;
    }
    _chars.insert(pos, c);
}

const QList<QVTChar> &QVTLine::chars() const
{
    return _chars;
}

int QVTLine::size() const
{
    return _chars.size();
}
