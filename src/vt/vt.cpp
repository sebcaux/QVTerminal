#include "vt.h"

VT::VT(QVTerminal *terminal)
    : _terminal(terminal)
{
}

QVTerminal *VT::terminal() const
{
    return _terminal;
}

QByteArray VT::dataFromKey(const QString &text, int key, Qt::KeyboardModifiers modifiers)
{
    Q_UNUSED(modifiers)
    Q_UNUSED(key)

    QByteArray data;
    data.append(text.toUtf8());
    return data;
}
