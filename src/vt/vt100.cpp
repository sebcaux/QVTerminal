#include "vt100.h"

VT100::VT100(QVTerminal *terminal)
    : VT(terminal)
{
}

QByteArray VT100::dataFromKey(const QString &text, int key, Qt::KeyboardModifiers modifiers)
{
    Q_UNUSED(modifiers)

    QByteArray data;

    switch (key)
    {
        case Qt::Key_Up:
            data.append(0x1B);
            data.append('[');
            data.append('A');
            break;

        case Qt::Key_Down:
            data.append(0x1B);
            data.append('[');
            data.append('B');
            break;

        case Qt::Key_Right:
            data.append(0x1B);
            data.append('[');
            data.append('C');
            break;

        case Qt::Key_Left:
            data.append(0x1B);
            data.append('[');
            data.append('D');
            break;

        case Qt::Key_Home:
            data.append(0x01);
            break;

        case Qt::Key_End:
            data.append(0x05);
            break;

        case Qt::Key_Backspace:
            data.append(127);
            break;

        default:
            data.append(text.toLatin1());
            break;
    }

    return data;
}
