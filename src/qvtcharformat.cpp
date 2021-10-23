#include "qvtcharformat.h"

QVTCharFormat::QVTCharFormat()
{
}

const QFont &QVTCharFormat::font() const
{
    return _font;
}

QFont &QVTCharFormat::font()
{
    return _font;
}

void QVTCharFormat::setFont(const QFont &font)
{
    _font = font;
}

const QColor &QVTCharFormat::foreground() const
{
    return _foreground;
}

void QVTCharFormat::setForeground(const QColor &foreground)
{
    _foreground = foreground;
}

const QColor &QVTCharFormat::background() const
{
    return _background;
}

void QVTCharFormat::setBackground(const QColor &background)
{
    _background = background;
}
