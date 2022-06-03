#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QObject>
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

namespace timer = std::chrono;

class SerialManager : public QObject
{
    Q_OBJECT
public:
    SerialManager(QObject *parent=nullptr);

    void setPortName(QString portName);
    void setPortlate(qint32 portlate);

    void setInterval(qint32 delay);

    void open();
    void close();
    void claer();

    bool isOpen();
    bool isClose();

    void clearError();

    void send(QString sendData); //.toStdString().c_str()

    qint32 portCount();
    QByteArray getReceiveData();

    QList<QSerialPortInfo> portNameList();
    QList<qint32> portlateList();

signals:
    void receive();

    void addPort();

    void removePort();

public slots:

    void receiveEvent();

    void searchPort();

private:
    QSerialPort *serial;

    bool isIntervalError = true;
    QString portName;
    qint32 portlate;
    qint32 intervalUs;
    QByteArray receiveData;
    qint32 lastPortCount;

    std::chrono::system_clock::time_point lastTime;
};





#endif // SERIALMANAGER_H
