#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollBar>
#include <QDateTime>
#include <QPlainTextEdit>

QString &space(int spaceSize);

void MainWindow::setSerialMonitor(const QString &str, bool isTimesptampMode)
{
    if(isTimesptampMode){
        const QString time = QDateTime::currentDateTime().toString("mm : ss . zzz");
        ui->SerialMonitor->appendPlainText(time + "    >\t" + str);
        ui->subSerialMonitor->setText(time + "    >\t" + str);
    }
    else{
        ui->SerialMonitor->appendPlainText(str);
        ui->subSerialMonitor->setText(str);
    }
}

void MainWindow::setLogMonitor(const QString &str, bool showPortData)
{

    const QString time = QDateTime::currentDateTime().toString("hh : mm : ss . zzz");

    const QString portName = ui->PortNameComboBox->currentText();
    const QString portlate = ui->PortLateComboBox->currentText();

    if(showPortData==false)
        ui->LogMonitor->append(time + "    " + str);
    else
        ui->LogMonitor->append(time + "    " + portName + "    " + portlate + "bps" + "    " + str);

}


QString &space(int spaceSize){
    static QString str;
    str = "";
    for(int i = 0; i < spaceSize; i++)str += " ";  // append space 'spaceSize' times
    return str;
}
