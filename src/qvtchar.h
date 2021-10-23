#ifndef QVTCHAR_H
#define QVTCHAR_H

#include "qvtcharformat.h"

class QVTChar
{
public:
    QVTChar(QChar c, const QVTCharFormat &format);

    QChar c() const;
    void setC(QChar c);

    QVTCharFormat &format();
    const QVTCharFormat &format() const;

protected:
    QChar _c;
    QVTCharFormat _format;
};

#endif  // QVTCHAR_H
