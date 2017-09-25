#include "mainwindow.h"

#include <QDebug>
#include <QFile>
#include <QProcess>
#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    terminal = new QVTerminal();

    foreach (QSerialPortInfo info, QSerialPortInfo::availablePorts())
        qDebug()<<info.description()<<info.manufacturer()<<"busy"<<info.isBusy()<<info.portName();

    // serial port test
    /*_port = new QSerialPort("ttyUSB0");
    qDebug()<<_port->open(QIODevice::ReadWrite);
    _port->setBaudRate(125000);
    connect(_port, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(error(QSerialPort::SerialPortError)));
    terminal->setIODevice(_port);*/

    // raw file test
    /*QFile *file = new QFile("/home/seb/Seafile/my_lib_rt/rtprog/test/holotips/out");
    file->open(QIODevice::ReadOnly);
    terminal->setIODevice(file);*/

    // process test
    QProcess *process = new QProcess();
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("TERM", "vt100");
    env.insert("COLUMNS", "80");
    env.insert("PS1", "> ");
    process->setProcessEnvironment(env);
    process->setProcessChannelMode(QProcess::MergedChannels);
    process->setArguments(QStringList()<<"--verbose");
    terminal->setIODevice(process);
    process->start("bash");

    setCentralWidget(terminal);
}

MainWindow::~MainWindow()
{
    delete terminal;
}

void MainWindow::error(QSerialPort::SerialPortError err)
{
    qDebug()<<"error"<<err;
}
