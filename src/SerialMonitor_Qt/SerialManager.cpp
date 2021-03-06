#include "SerialManager.h"
#include <QtDebug>
#include <chrono>

SerialManager::SerialManager(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SerialManager::searchPort);
    timer->start(100); //default 100ms
    searchPort();
}

void SerialManager::setPortName(const QString &portName)
{
    this->portName = portName;
}

void SerialManager::setPortlate(qint32 portlate)
{
    this->portlate = portlate;
}

void SerialManager::setInterval(qint32 intervalUs)
{
    this->intervalUs = intervalUs;
}

void SerialManager::open()
{
    if(serial->isOpen())serial->close();
    serial->setPortName(portName);
    serial->setBaudRate(portlate);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    connect(serial, &QIODevice::readyRead, this, &SerialManager::receiveEvent);
}

void SerialManager::close()
{
    if(serial->isOpen())serial->close();
    disconnect(serial, &QIODevice::readyRead, this, &SerialManager::receiveEvent);
}

void SerialManager::claer()
{
    if(serial->isOpen())
        serial->clear();
}

bool SerialManager::isOpen()
{
    return serial->isOpen();
}

bool SerialManager::isClose()
{
    return !serial->isOpen();
}

void SerialManager::clearError()
{
    isIntervalError = false;
}

void SerialManager::send(const QString &sendData)
{
    if(serial->isOpen())
        serial->write(sendData.toStdString().c_str());
}

qint32 SerialManager::portCount()
{
    return QSerialPortInfo::availablePorts().count();
}

QByteArray SerialManager::getReceiveData()
{
    return receiveData;
}

QList<QSerialPortInfo> SerialManager::portNameList()
{
    return QSerialPortInfo::availablePorts();
}

QList<qint32> SerialManager::portlateList()
{
    return QSerialPortInfo::standardBaudRates();
}

void SerialManager::receiveEvent() //??????????????????
{
    //????????????????????????????????????????????????
    auto nowTime = std::chrono::system_clock::now();
    auto rowReceiveInterval = nowTime - lastTime;
    auto receiveInterval = std::chrono::duration_cast<std::chrono::microseconds>(rowReceiveInterval).count(); //??????????????????

    //?????????????????????(???????????????????????????)??????????????????????????????
    if(receiveInterval < intervalUs){
        if(serial->isOpen())serial->clear(); //??????????????????
        return;
    }

    lastTime = std::chrono::system_clock::now(); //??????????????????????????????

    if(serial->canReadLine()==false)return;
    while (serial->canReadLine()){
        receiveData = serial->readLine();
        emit receive();
    }

}

void SerialManager::searchPort() //??????????????????????????????????????????
{
    int openPortCount = portCount();

    if(openPortCount > lastPortCount)
        emit addPort(); //??????????????????
    else if(openPortCount < lastPortCount)
        emit removePort(); //??????????????????

    lastPortCount = openPortCount;
}
