/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SerialMonitor_Qt/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[36];
    char stringdata0[381];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 11), // "connectPort"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 14), // "disconnectPort"
QT_MOC_LITERAL(39, 12), // "receiveEvent"
QT_MOC_LITERAL(52, 21), // "on_SendButton_clicked"
QT_MOC_LITERAL(74, 29), // "on_PortLateComboBox_activated"
QT_MOC_LITERAL(104, 5), // "index"
QT_MOC_LITERAL(110, 29), // "on_PortNameComboBox_activated"
QT_MOC_LITERAL(140, 26), // "on_PortStateButton_clicked"
QT_MOC_LITERAL(167, 25), // "on_PageDownButton_clicked"
QT_MOC_LITERAL(193, 33), // "on_ClearMainMonitorButton_cli..."
QT_MOC_LITERAL(227, 30), // "on_ClearPropertyButton_clicked"
QT_MOC_LITERAL(258, 30), // "on_MaxLineSpinBox_valueChanged"
QT_MOC_LITERAL(289, 4), // "arg1"
QT_MOC_LITERAL(294, 34), // "on_BruetoothEnableChackBox_cl..."
QT_MOC_LITERAL(329, 22), // "on_BinCheckBox_clicked"
QT_MOC_LITERAL(352, 28) // "on_TimestampCheckBox_clicked"

    },
    "MainWindow\0connectPort\0\0disconnectPort\0"
    "receiveEvent\0on_SendButton_clicked\0"
    "on_PortLateComboBox_activated\0index\0"
    "on_PortNameComboBox_activated\0"
    "on_PortStateButton_clicked\0"
    "on_PageDownButton_clicked\0"
    "on_ClearMainMonitorButton_clicked\0"
    "on_ClearPropertyButton_clicked\0"
    "on_MaxLineSpinBox_valueChanged\0arg1\0"
    "on_BruetoothEnableChackBox_clicked\0"
    "on_BinCheckBox_clicked\0"
    "on_TimestampCheckBox_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    1,  102,    2, 0x08,    5 /* Private */,
       8,    1,  105,    2, 0x08,    7 /* Private */,
       9,    0,  108,    2, 0x08,    9 /* Private */,
      10,    0,  109,    2, 0x08,   10 /* Private */,
      11,    0,  110,    2, 0x08,   11 /* Private */,
      12,    0,  111,    2, 0x08,   12 /* Private */,
      13,    1,  112,    2, 0x08,   13 /* Private */,
      15,    0,  115,    2, 0x08,   15 /* Private */,
      16,    0,  116,    2, 0x08,   16 /* Private */,
      17,    0,  117,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connectPort(); break;
        case 1: _t->disconnectPort(); break;
        case 2: _t->receiveEvent(); break;
        case 3: _t->on_SendButton_clicked(); break;
        case 4: _t->on_PortLateComboBox_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_PortNameComboBox_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_PortStateButton_clicked(); break;
        case 7: _t->on_PageDownButton_clicked(); break;
        case 8: _t->on_ClearMainMonitorButton_clicked(); break;
        case 9: _t->on_ClearPropertyButton_clicked(); break;
        case 10: _t->on_MaxLineSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_BruetoothEnableChackBox_clicked(); break;
        case 12: _t->on_BinCheckBox_clicked(); break;
        case 13: _t->on_TimestampCheckBox_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
