#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QKeyEvent>
#include <QtDebug>

class MyClass : public QWidget
{
    Q_OBJECT
public:
    explicit MyClass(QWidget *parent = 0):QWidget(parent){}

protected:
     void keyPressEvent(QKeyEvent *event) override
     {
         if(event->key() == Qt::Key_R)
         {
             //Do something when 'R' key is pressed
             qDebug() << "push";
         }
     }
};

#endif // KEYBOARD_H
