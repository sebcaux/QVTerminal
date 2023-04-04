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

QString QVTLine::text() const
{
    QString text;
    for (const QVTChar &c : _chars)
    {
        text.append(c.c());
    }
    return text;
}

QString QVTLine::text(qsizetype position, qsizetype n) const
{
    if (position >= _chars.size() || position < 0)
    {
        return QString();
    }

    qsizetype size = n;
    if (position + size > _chars.size())
    {
        size = _chars.size() - position;
    }

    QString text;
    for (qsizetype col = position; col < position + size; col++)
    {
        text.append(_chars[col].c());
    }
    return text;
}

qsizetype QVTLine::size() const
{
    return _chars.size();
}
