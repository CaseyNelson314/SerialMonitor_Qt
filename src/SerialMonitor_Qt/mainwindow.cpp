#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QScrollBar>
#include <QTimer>
#include <QDebug>

#include "SerialManager.h"
#include "UiList.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->PortStateButton->setEnabled(false);
    ui->SendButton->setEnabled(false);
    ui->PortLateComboBox->setEnabled(false);

    /*ポート情報取得*/
    serial = new SerialManager;
    serial->setInterval(2000);
    portUpdate();
    connectPort();
    connect(serial, &SerialManager::addPort, this, &MainWindow::connectPort);
    connect(serial, &SerialManager::removePort, this, &MainWindow::disconnectPort);
    connect(serial, &SerialManager::receive, this, &MainWindow::receiveEvent);
    serial->setPortName(ui->PortNameComboBox->currentText());
    serial->setPortlate(ui->PortLateComboBox->currentText().toInt());

    connect(ui->PropertyPortData->verticalScrollBar(), &QAbstractSlider::valueChanged, ui->PropertyPortName->verticalScrollBar(), &QAbstractSlider::setValue);//プロパティスクロール同期
    connect(ui->PropertyPortName->verticalScrollBar(), &QAbstractSlider::valueChanged, ui->PropertyPortData->verticalScrollBar(), &QAbstractSlider::setValue);//プロパティスクロール同期

    ui->subSerialMonitor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->SerialMonitor->setMaximumBlockCount(ui->MaxLineSpinBox->value());
}

MainWindow::~MainWindow()
{
    if(serial->isOpen())serial->close();
    delete ui;
}

void MainWindow::connectPort()
{
    if(portUpdate())serial->open();
    if(ui->PortNameComboBox->currentText()==Combo::PORT_NOFOUND){
        ui->PortStateButton->setEnabled(false);
        ui->SendButton->setEnabled(false);
        ui->PortLateComboBox->setEnabled(false);
        return;
    }
    ui->SerialMonitor->clear();

    if(serial->isOpen()){
        ui->PortStateButton->setEnabled(true);
        ui->SendButton->setEnabled(true);
        ui->PortLateComboBox->setEnabled(true);
        ui->PortStateButton->setText(Button::BOTTON_CLOSE);
        setSerialMonitor(Log::PORTOPEN, ui->TimestampCheckBox->isChecked());
        setLogMonitor(Log::CONNECT, true);
        setLogMonitor(Log::PORTOPEN, true);
    }else{ //ポートが開けない
        ui->PortStateButton->setText(Button::BOTTON_OPEN);
        setSerialMonitor(Log::CANTOPEN, ui->TimestampCheckBox->isChecked());
        setLogMonitor(Log::CANTOPEN, true);
    }
}

void MainWindow::disconnectPort()
{
    if(serial->isClose())return;
    serial->close();
    setSerialMonitor(Log::PORTCLOSE, ui->TimestampCheckBox->isChecked());
    setLogMonitor(Log::DISCONNECT, true);
    setLogMonitor(Log::PORTCLOSE, true);
    portUpdate();
    if(ui->PortNameComboBox->currentText()!=Combo::PORT_NOFOUND){
        ui->PortStateButton->setEnabled(false);
        ui->SendButton->setEnabled(false);
        ui->PortLateComboBox->setEnabled(false);
    }
}

int lastReceiveSize;
void MainWindow::receiveEvent()
{
    const QString tabName = ui->MonitorSelector->tabText(ui->MonitorSelector->currentIndex());

    QString sendText;

    QByteArray receiveData = serial->getReceiveData();

    if(ui->BinCheckBox->isChecked()) //digits > binary
        for (auto i = 0; i < receiveData.size(); ++i)
            sendText.append(QString::number(receiveData[i], 2) + "\t");
    else
        sendText = receiveData;

    if(tabName==Menu::MONITOR || tabName==Menu::PROPERTY)
        setSerialMonitor(sendText.trimmed(), ui->TimestampCheckBox->isChecked());

}

bool MainWindow::portUpdate() //通常ポートであるかどうかを返す Bruetoothポートを除くため
{
    ui->PortNameComboBox->clear();
    ui->PropertyPortName->clear();
    ui->PropertyPortData->clear();

    int bruetoothPortCount = 0;
    foreach (auto &info, serial->portNameList()){
        if(info.description().contains("Bluetooth", Qt::CaseInsensitive) && ui->BruetoothEnableChackBox->isChecked()==false){
            bruetoothPortCount++;
            continue; //Bruetoothポート除外
        }
        ui->PortNameComboBox->addItem(info.portName());
        ui->PropertyPortName->addItem(info.portName());
        ui->PropertyPortData->addItem(info.description());
    }

    if(serial->portCount()-bruetoothPortCount<=0){
        ui->PortNameComboBox->addItem(Combo::PORT_NOFOUND);
        return false;
    }
    serial->setPortName(ui->PortNameComboBox->currentText());
    serial->setPortlate(ui->PortLateComboBox->currentText().toInt());

    return true; //取得正常終了
}

void MainWindow::on_SendButton_clicked()
{
    if(serial->isClose()){
        setLogMonitor(Log::PORTISCLOSE, false);
        return;
    }

    QString sendData = ui->writeText->text();
    if(serial->isOpen() && sendData!=nullptr){
        serial->send(sendData);
        setLogMonitor(sendData, false);
    }

    ui->writeText->clear();
}

void MainWindow::on_PortLateComboBox_activated(int)
{
    if(ui->PortNameComboBox->currentText()==Combo::PORT_NOFOUND){
        ui->PortStateButton->setEnabled(false);
        ui->SendButton->setEnabled(false);
        ui->PortLateComboBox->setEnabled(false);
        return;
    }
    if(portUpdate())serial->open();
    if(serial->isOpen()){ //ポートが開けた
        ui->SendButton->setEnabled(true);
        ui->PortStateButton->setText(Button::BOTTON_CLOSE);
        setSerialMonitor(Log::PORTOPEN, ui->TimestampCheckBox->isChecked());
        setLogMonitor(Log::PORTOPEN, true);
    }else{ //ポートが開けない
        ui->SendButton->setEnabled(false);
        ui->PortStateButton->setText(Button::BOTTON_OPEN);
        setSerialMonitor(Log::CANTOPEN, ui->TimestampCheckBox->isChecked());
        setLogMonitor(Log::CANTOPEN, true);
    }
}

void MainWindow::on_PortNameComboBox_activated(int)
{

    if(ui->PortNameComboBox->currentText()==Combo::PORT_NOFOUND){
        ui->PortStateButton->setEnabled(false);
        ui->SendButton->setEnabled(false);
        ui->PortLateComboBox->setEnabled(false);
        return;
    }
    serial->setPortName(ui->PortNameComboBox->currentText());
    serial->setPortlate(ui->PortLateComboBox->currentText().toInt());
    serial->open();
    if(serial->isOpen()){ //ポートが開けた
        ui->PortLateComboBox->setEnabled(true);
        ui->PortStateButton->setEnabled(true);
        ui->SendButton->setEnabled(true);
        ui->PortStateButton->setText(Button::BOTTON_CLOSE);
        setSerialMonitor(Log::PORTOPEN, ui->TimestampCheckBox->isChecked());
        setLogMonitor(Log::PORTOPEN, true);
    }else{ //ポートが開けない
        ui->PortLateComboBox->setEnabled(false);
        ui->SendButton->setEnabled(false);
        ui->PortStateButton->setText(Button::BOTTON_OPEN);
        setSerialMonitor(Log::CANTOPEN, ui->TimestampCheckBox->isChecked());
        setLogMonitor(Log::CANTOPEN, true);
    }
}

void MainWindow::on_PortStateButton_clicked()
{
    if(serial->isOpen()){ //ポートを閉じる
        serial->close();
        ui->SendButton->setEnabled(false);
        ui->PortStateButton->setText(Button::BOTTON_OPEN);
        setSerialMonitor(Log::PORTCLOSE, ui->TimestampCheckBox->isChecked());
        setLogMonitor(Log::PORTCLOSE, true);
    }else{ //ポートを開ける
        if(portUpdate())serial->open();

        if(serial->isOpen()){ //ポートが開けた
            ui->SendButton->setEnabled(true);
            ui->PortStateButton->setText(Button::BOTTON_CLOSE);
            setSerialMonitor(Log::PORTOPEN, ui->TimestampCheckBox->isChecked());
            setLogMonitor(Log::PORTOPEN, true);
        }else{ //ポートが開けない
            ui->SendButton->setEnabled(false);
            ui->PortStateButton->setText(Button::BOTTON_OPEN);
            setSerialMonitor(Log::CANTOPEN, ui->TimestampCheckBox->isChecked());
            setLogMonitor(Log::CANTOPEN, true);
        }

    }
}


void MainWindow::on_PageDownButton_clicked()
{
    ui->SerialMonitor->verticalScrollBar()->setValue(ui->SerialMonitor->verticalScrollBar()->maximum());
}

void MainWindow::on_ClearMainMonitorButton_clicked()
{
    ui->SerialMonitor->clear();
    ui->SerialMonitor->verticalScrollBar()->setValue(ui->SerialMonitor->verticalScrollBar()->maximum());
}

void MainWindow::on_ClearPropertyButton_clicked()
{
    ui->LogMonitor->clear();
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    ui->SerialMonitor->verticalScrollBar()->setValue(ui->SerialMonitor->verticalScrollBar()->maximum());
}

void MainWindow::moveEvent(QMoveEvent *)
{
    serial->claer();
}

void MainWindow::on_MaxLineSpinBox_valueChanged(int arg1)
{
    //最小値が1 & 100ずつ増加な為、数値を増やしたときに101になるのを防ぐ
    if(arg1==101)arg1=100;
    ui->MaxLineSpinBox->setValue(arg1);
    ui->SerialMonitor->setMaximumBlockCount(arg1);
}

void MainWindow::on_BruetoothEnableChackBox_clicked()
{
    portUpdate();
    if(ui->PortNameComboBox->currentText()!=Combo::PORT_NOFOUND){
        if(serial->isClose()){
            ui->PortStateButton->setEnabled(true);
            ui->PortLateComboBox->setEnabled(true);
            ui->PortStateButton->setText(Button::BOTTON_OPEN);
        }
    }else{
        ui->PortStateButton->setEnabled(false);
        ui->PortLateComboBox->setEnabled(false);
    }
}

void MainWindow::on_BinCheckBox_clicked()
{
    ui->SerialMonitor->verticalScrollBar()->setValue(ui->SerialMonitor->verticalScrollBar()->maximum());
}

void MainWindow::on_TimestampCheckBox_clicked()
{
    ui->SerialMonitor->verticalScrollBar()->setValue(ui->SerialMonitor->verticalScrollBar()->maximum());
}

