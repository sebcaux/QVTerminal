#ifndef QVTLINE_H
#define QVTLINE_H

#include "qvtchar.h"

class QVTLine
{
public:
    QVTLine();

    void append(const QVTChar &c);
    const QList<QVTChar> &chars() const;
    int size() const;

protected:
    QList<QVTChar> _chars;
};

#endif  // QVTLINE_H
