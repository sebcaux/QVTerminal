#ifndef VT_H
#define VT_H

#include <QByteArray>
#include <QString>

class QVTerminal;

class VT
{
public:
    VT(QVTerminal *terminal);

    QVTerminal *terminal() const;

    virtual QByteArray dataFromKey(const QString &text, int key, Qt::KeyboardModifiers modifiers);

protected:
    QVTerminal *_terminal;
};

#endif  // VT_H
