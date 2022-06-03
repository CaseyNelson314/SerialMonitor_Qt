#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTreeWidgetItem>

#include <memory>

#include "SerialManager.h"
#include "UiList.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void connectPort();
    void disconnectPort();
    void receiveEvent();

    void on_SendButton_clicked();
    void on_PortLateComboBox_activated(int index);
    void on_PortNameComboBox_activated(int index);
    void on_PortStateButton_clicked();
    void on_PageDownButton_clicked();
    void on_ClearMainMonitorButton_clicked();
    void on_ClearPropertyButton_clicked();
    void on_MaxLineSpinBox_valueChanged(int arg1);
    void on_BruetoothEnableChackBox_clicked();
    void on_BinCheckBox_clicked();
    void on_TimestampCheckBox_clicked();

private:

    //mainwindow.cpp
    SerialManager *serial = nullptr;

    int lastPortNum;

    bool portUpdate();
    void resizeEvent(QResizeEvent*)override;  //ウィンドウリサイズ時のコールバック関数
    void moveEvent(QMoveEvent *)override; //ウィンドウ移動時のry

    //Monitor.cpp
    void setSerialMonitor(QString str);

    void setLogMonitor(QString str, QString space, bool showPortData);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
