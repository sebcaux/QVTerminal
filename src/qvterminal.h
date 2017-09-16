#ifndef QVTERMINAL_H
#define QVTERMINAL_H

#include <QAbstractScrollArea>

#include "qvtline.h"

class QVTerminal : public QAbstractScrollArea
{
    Q_OBJECT
public:
    explicit QVTerminal(QWidget *parent = nullptr);
    ~QVTerminal();

    void setIODevice(QIODevice *device);

    // style
    const QVTCharFormat &format() const;
    void setFormat(const QVTCharFormat &format);

    // mode
    bool echo() const;
    void setEcho(bool echo);

    bool crlf() const;
    void setCrlf(bool crlf);

signals:

public slots:
    void appendData(QByteArray data);

protected slots:
    void read();
    void appendString(QString str);

private:
    QIODevice *_device;

    // parser
    enum State {
        Text,
        Escape,
        Format,
        ResetFont
    };
    State _state;
    int _formatValue;

    // cursor
    QVTCharFormat _format;
    QVTCharFormat _curentFormat;
    int _cw;
    int _ch;
    QPoint _cursorPos;

    // data
    QList< QVTLine > _data;

    // mode
    bool _echo;
    bool _crlf;

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);

    // QAbstractScrollArea interface
protected:
    virtual bool viewportEvent(QEvent *event);
    QColor vt100color(char c);
};

#endif // QVTERMINAL_H
