#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QScrollBar>
#include <QDateTime>
#include <QTimer>


void MainWindow::serialReceiveEvent()
{
    QString tabName = ui->MonitorSelector->tabText(ui->MonitorSelector->currentIndex());

    receiveData = serial->readAll();

    if(tabName == "Monitor"){ //シリアルモニター

        //受信データ表示
        setSerialMonitor(receiveData.trimmed());

    }else if(tabName == "Plotter"){ //シリアルプロッタ



    }else if(tabName == "Property"){ //プロパティー

        setSerialMonitor(receiveData.trimmed());

    }
    receiveData = nullptr;
}

void MainWindow::timerSearchPortEvent() //使用可能ポート検出
{
    QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();

    if(portList.count() != lastPortNum){ //ポート数が変更された場合

        serialClose();

        bool isAddPort = portList.count() > lastPortNum;

        if(isAddPort == false){
            setSerialMonitor("Device disconnect.");
            setLogMonitor("Device disconnect.", "\t", true);
        }

        ui->PortNameComboBox->clear();
        ui->PropertyPortName->clear();
        ui->PropertyPortData->clear();

        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
            ui->PortNameComboBox->addItem(info.portName());
            ui->PropertyPortName->addItem(info.portName());
            ui->PropertyPortData->addItem(info.description());
        }

        if(isAddPort){
            setSerialMonitor("Device connected.");
            setLogMonitor("Device connected.", "\t", true);
            serialOpen();
        }

        if(portList.count() == 0) //ポート見つからない
            ui->PortNameComboBox->addItem("No Found");

    }


    lastPortNum = portList.count();
}


void MainWindow::serialOpen()
{
    if(serial->isOpen())serial->close();

    serial->setPortName(ui->PortNameComboBox->currentText());
    serial->setBaudRate(ui->PortLateComboBox->currentText().toInt());
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    serial->open(QIODevice::ReadWrite);

    ui->SerialMonitor->clear();

    if(serial->isOpen()){
        setSerialMonitor("Port open.");
        setLogMonitor("Port open.", "\t\t", true);
        ui->SendButton->setEnabled(true);
        ui->PortStateButton->setEnabled(true);
    }else{
        setSerialMonitor("Could't open port.");
        setLogMonitor("Could't open port.", "\t", true);
        ui->PortStateButton->setText("Open");
        ui->SendButton->setEnabled(false);
        ui->PortStateButton->setEnabled(false);
    }

}

void MainWindow::serialClose()
{
    if(serial->isOpen()==false)return;
    setSerialMonitor("Port closed.");
    setLogMonitor("Port closed.", "\t\t", true);
    serial->close();
    ui->SendButton->setEnabled(false);
}
