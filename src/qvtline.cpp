#include "qvtline.h"

QVTLine::QVTLine()
{
}

void QVTLine::append(const QVTChar &c)
{
    _chars.append(c);
}

const QList<QVTChar> &QVTLine::chars() const
{
    return _chars;
}

int QVTLine::size() const
{
    return _chars.size();
}
