#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qvterminal.h"

#include <QMainWindow>

#include <QSerialPort>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void error(QSerialPort::SerialPortError err);

private:
    QVTerminal *terminal;

    QSerialPort *_port;
};

#endif // MAINWINDOW_H
