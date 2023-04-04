#ifndef QVTLINE_H
#define QVTLINE_H

#include "qvtchar.h"

class QVTLine
{
public:
    QVTLine();

    void append(const QVTChar &c);
    void insert(const QVTChar &c, int pos);
    void replace(const QVTChar &c, int pos);

    const QList<QVTChar> &chars() const;

    QString text() const;
    QString text(qsizetype position, qsizetype n = -1) const;

    qsizetype size() const;

protected:
    QList<QVTChar> _chars;
};

#endif  // QVTLINE_H
