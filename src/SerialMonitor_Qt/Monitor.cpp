#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollBar>
#include <QDateTime>
#include <QPlainTextEdit>

void MainWindow::setSerialMonitor(QString str)
{
    if(ui->TimestampCheckBox->isChecked()){
        QString time = QDateTime::currentDateTime().toString("mm : ss . zzz");
        ui->SerialMonitor->appendPlainText(time + "    >\t" + str);
        ui->subSerialMonitor->setText(time + "    >\t" + str);
    }else{
        ui->SerialMonitor->appendPlainText(str);
        ui->subSerialMonitor->setText(str);
    }

}

void MainWindow::setLogMonitor(QString str, QString space, bool showPortData)
{
    QString time = QDateTime::currentDateTime().toString("hh : mm : ss . zzz");

    QString portName = ui->PortNameComboBox->currentText();
    QString portlate = ui->PortLateComboBox->currentText();


    if(showPortData==false)
        ui->LogMonitor->append(time + "    >\t" + str + space);
    else
        ui->LogMonitor->append(time + "    >\t" + str + space + portName + "\t" + portlate + "bps");

}

