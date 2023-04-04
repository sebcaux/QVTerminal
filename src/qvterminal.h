#ifndef QVTERMINAL_H
#define QVTERMINAL_H

#include <QAbstractScrollArea>
#include <QAction>
#include <QTimer>

#include <vt/vt.h>

#include "qvtlayout.h"

class QVTerminal : public QAbstractScrollArea
{
    Q_OBJECT
public:
    explicit QVTerminal(QWidget *parent = nullptr);
    ~QVTerminal() override;

    void setIODevice(QIODevice *device);

    // style
    const QVTCharFormat &format() const;
    void setFormat(const QVTCharFormat &format);

    // mode
    bool echo() const;
    void setEcho(bool echo);

    bool crlf() const;
    void setCrlf(bool crlf);

    QPoint cursorPos() const;

signals:
    void cursorMoved(QPoint cursorPos);

public slots:
    void writeData(const QByteArray &data);

    void paste();
    void clear();

protected slots:
    void read();
    void appendData(const QByteArray &data);
    void appendString(const QString &str);
    void toggleCursor();

private:
    QIODevice *_device;

    // parser
    enum State
    {
        Text,
        Escape,
        Format,
        ResetFont
    };
    State _state;
    int _formatValue;

    // cursor
    void setCursorPos(int x, int y);
    void setCursorPos(QPoint cursorPos);
    QVTCharFormat _format;
    QVTCharFormat _curentFormat;
    int _cw;
    int _ch;
    QPoint _cursorPos;
    QTimer _cursorTimer;
    bool _cvisible;

    // data
    QVTLayout *_layout;

    // mode
    bool _echo;
    bool _crlf;

    QAction *_pasteAction;
    QAction *_clearAction;
    VT *_vt;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif  // QT_NO_CONTEXTMENU

    // QAbstractScrollArea interface
protected:
    bool viewportEvent(QEvent *event) override;
    QColor vt100color(char c);
};

#endif  // QVTERMINAL_H
