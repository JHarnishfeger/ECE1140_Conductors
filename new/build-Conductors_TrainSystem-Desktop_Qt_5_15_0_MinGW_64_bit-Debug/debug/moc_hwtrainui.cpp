/****************************************************************************
** Meta object code from reading C++ file 'hwtrainui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../AAA_TrainSystem/Conductors_TrainSystem/HWTrainController/hw_TrainController/hwtrainui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hwtrainui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HWTrainUI_t {
    QByteArrayData data[12];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HWTrainUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HWTrainUI_t qt_meta_stringdata_HWTrainUI = {
    {
QT_MOC_LITERAL(0, 0, 9), // "HWTrainUI"
QT_MOC_LITERAL(1, 10, 14), // "getnewTCSignal"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "uint8_t"
QT_MOC_LITERAL(4, 34, 12), // "encodedBlock"
QT_MOC_LITERAL(5, 47, 13), // "decodeSignals"
QT_MOC_LITERAL(6, 61, 24), // "on_connectButton_clicked"
QT_MOC_LITERAL(7, 86, 31), // "on_commandedSpeed_returnPressed"
QT_MOC_LITERAL(8, 118, 22), // "on_enterButton_clicked"
QT_MOC_LITERAL(9, 141, 7), // "updates"
QT_MOC_LITERAL(10, 149, 28), // "on_ports_currentIndexChanged"
QT_MOC_LITERAL(11, 178, 5) // "index"

    },
    "HWTrainUI\0getnewTCSignal\0\0uint8_t\0"
    "encodedBlock\0decodeSignals\0"
    "on_connectButton_clicked\0"
    "on_commandedSpeed_returnPressed\0"
    "on_enterButton_clicked\0updates\0"
    "on_ports_currentIndexChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HWTrainUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    0,   56,    2, 0x08 /* Private */,
      10,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void HWTrainUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HWTrainUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getnewTCSignal((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 1: _t->decodeSignals(); break;
        case 2: _t->on_connectButton_clicked(); break;
        case 3: _t->on_commandedSpeed_returnPressed(); break;
        case 4: _t->on_enterButton_clicked(); break;
        case 5: _t->updates(); break;
        case 6: _t->on_ports_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HWTrainUI::*)(uint8_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HWTrainUI::getnewTCSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HWTrainUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_HWTrainUI.data,
    qt_meta_data_HWTrainUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HWTrainUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HWTrainUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HWTrainUI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int HWTrainUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void HWTrainUI::getnewTCSignal(uint8_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
