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

void SerialManager::setPortName(QString portName){ this->portName = portName; }

void SerialManager::setPortlate(qint32 portlate){ this->portlate = portlate; }

void SerialManager::setInterval(qint32 intervalUs){ this->intervalUs = intervalUs; }

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

bool SerialManager::isOpen(){ return serial->isOpen(); }

bool SerialManager::isClose(){ return !serial->isOpen(); }

void SerialManager::clearError(){ isIntervalError = false; }

void SerialManager::send(QString sendData)
{
    if(serial->isOpen())
        serial->write(sendData.toStdString().c_str());
}

qint32 SerialManager::portCount(){ return QSerialPortInfo::availablePorts().count(); }

QByteArray SerialManager::getReceiveData(){ return receiveData; }

QList<QSerialPortInfo> SerialManager::portNameList(){ return QSerialPortInfo::availablePorts(); }

QList<qint32> SerialManager::portlateList(){ return QSerialPortInfo::standardBaudRates(); }

void SerialManager::receiveEvent() //受信割り込み
{
    //最後の通信からの経過時間を求める
    auto nowTime = std::chrono::system_clock::now();
    auto rowReceiveInterval = nowTime - lastTime;
    auto receiveInterval = std::chrono::duration_cast<std::chrono::microseconds>(rowReceiveInterval).count(); //ミリ秒に変換

    //データ量が多い場合のアプリ落ち防止
    if(receiveInterval <= intervalUs){ //ここなぜかよく呼び出される
        if(serial->isOpen())serial->clear(); //バッファ削除
        return;
    }

    if(serial->canReadLine()==false)return;
    while (serial->canReadLine()){
        receiveData = serial->readLine();
        emit receive();
    }

    lastTime = std::chrono::system_clock::now(); //最後の受信時刻を保存
}

void SerialManager::searchPort() //ポート検索用タイマー割り込み
{
    int openPortCount = portCount();

    if(openPortCount > lastPortCount)
        emit addPort(); //接続シグナル
    else if(openPortCount < lastPortCount)
        emit removePort(); //切断シグナル

    lastPortCount = openPortCount;
}
