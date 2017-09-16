#include "qvtchar.h"

QVTChar::QVTChar(QChar c, const QVTCharFormat &format)
{
    _c = c;
    _format = format;
}

QChar QVTChar::c() const
{
    return _c;
}

void QVTChar::setC(QChar c)
{
    _c = c;
}

QVTCharFormat &QVTChar::format()
{
    return _format;
}

const QVTCharFormat &QVTChar::format() const
{
    return _format;
}
