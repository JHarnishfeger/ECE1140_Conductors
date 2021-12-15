/****************************************************************************
** Meta object code from reading C++ file 'traincontrollermainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../AAA_TrainSystem/Conductors_TrainSystem/HWTrainController/hw_TrainController/traincontrollermainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'traincontrollermainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrainControllerMainWindow_t {
    QByteArrayData data[10];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrainControllerMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrainControllerMainWindow_t qt_meta_stringdata_TrainControllerMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 25), // "TrainControllerMainWindow"
QT_MOC_LITERAL(1, 26, 22), // "on_enterButton_clicked"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 7), // "updates"
QT_MOC_LITERAL(4, 58, 21), // "on_testButton_clicked"
QT_MOC_LITERAL(5, 80, 12), // "setUtilities"
QT_MOC_LITERAL(6, 93, 8), // "setPower"
QT_MOC_LITERAL(7, 102, 41), // "on_connectionComboBox_current..."
QT_MOC_LITERAL(8, 144, 5), // "index"
QT_MOC_LITERAL(9, 150, 24) // "on_ConnectButton_clicked"

    },
    "TrainControllerMainWindow\0"
    "on_enterButton_clicked\0\0updates\0"
    "on_testButton_clicked\0setUtilities\0"
    "setPower\0on_connectionComboBox_currentIndexChanged\0"
    "index\0on_ConnectButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrainControllerMainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void TrainControllerMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrainControllerMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_enterButton_clicked(); break;
        case 1: _t->updates(); break;
        case 2: _t->on_testButton_clicked(); break;
        case 3: _t->setUtilities(); break;
        case 4: _t->setPower(); break;
        case 5: _t->on_connectionComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_ConnectButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TrainControllerMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_TrainControllerMainWindow.data,
    qt_meta_data_TrainControllerMainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TrainControllerMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrainControllerMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrainControllerMainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TrainControllerMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
