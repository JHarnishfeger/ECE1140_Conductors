/****************************************************************************
** Meta object code from reading C++ file 'uiswtraincontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../AAA_TrainSystem/Conductors_TrainSystem/TrainControlSW/uiswtraincontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiswtraincontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UISWTrainController_t {
    QByteArrayData data[20];
    char stringdata0[395];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UISWTrainController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UISWTrainController_t qt_meta_stringdata_UISWTrainController = {
    {
QT_MOC_LITERAL(0, 0, 19), // "UISWTrainController"
QT_MOC_LITERAL(1, 20, 14), // "getnewTCSignal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "uint8_t"
QT_MOC_LITERAL(4, 44, 12), // "encodedBlock"
QT_MOC_LITERAL(5, 57, 9), // "timerInst"
QT_MOC_LITERAL(6, 67, 8), // "updateUI"
QT_MOC_LITERAL(7, 76, 13), // "decodeSignals"
QT_MOC_LITERAL(8, 90, 31), // "on_driverEmergencyBrake_clicked"
QT_MOC_LITERAL(9, 122, 25), // "on_leftDoors_valueChanged"
QT_MOC_LITERAL(10, 148, 5), // "value"
QT_MOC_LITERAL(11, 154, 26), // "on_rightDoors_valueChanged"
QT_MOC_LITERAL(12, 181, 30), // "on_interiorLights_valueChanged"
QT_MOC_LITERAL(13, 212, 30), // "on_exteriorLights_valueChanged"
QT_MOC_LITERAL(14, 243, 23), // "on_serviceBrake_clicked"
QT_MOC_LITERAL(15, 267, 26), // "on_modeswitch_valueChanged"
QT_MOC_LITERAL(16, 294, 26), // "on_announceStation_clicked"
QT_MOC_LITERAL(17, 321, 33), // "on_commandeVelocity_returnPre..."
QT_MOC_LITERAL(18, 355, 19), // "on_kp_returnPressed"
QT_MOC_LITERAL(19, 375, 19) // "on_ki_returnPressed"

    },
    "UISWTrainController\0getnewTCSignal\0\0"
    "uint8_t\0encodedBlock\0timerInst\0updateUI\0"
    "decodeSignals\0on_driverEmergencyBrake_clicked\0"
    "on_leftDoors_valueChanged\0value\0"
    "on_rightDoors_valueChanged\0"
    "on_interiorLights_valueChanged\0"
    "on_exteriorLights_valueChanged\0"
    "on_serviceBrake_clicked\0"
    "on_modeswitch_valueChanged\0"
    "on_announceStation_clicked\0"
    "on_commandeVelocity_returnPressed\0"
    "on_kp_returnPressed\0on_ki_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UISWTrainController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    1,   96,    2, 0x08 /* Private */,
      11,    1,   99,    2, 0x08 /* Private */,
      12,    1,  102,    2, 0x08 /* Private */,
      13,    1,  105,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    1,  109,    2, 0x08 /* Private */,
      16,    0,  112,    2, 0x08 /* Private */,
      17,    0,  113,    2, 0x08 /* Private */,
      18,    0,  114,    2, 0x08 /* Private */,
      19,    0,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UISWTrainController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UISWTrainController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getnewTCSignal((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 1: _t->timerInst(); break;
        case 2: _t->updateUI(); break;
        case 3: _t->decodeSignals(); break;
        case 4: _t->on_driverEmergencyBrake_clicked(); break;
        case 5: _t->on_leftDoors_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_rightDoors_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_interiorLights_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_exteriorLights_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_serviceBrake_clicked(); break;
        case 10: _t->on_modeswitch_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_announceStation_clicked(); break;
        case 12: _t->on_commandeVelocity_returnPressed(); break;
        case 13: _t->on_kp_returnPressed(); break;
        case 14: _t->on_ki_returnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UISWTrainController::*)(uint8_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UISWTrainController::getnewTCSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UISWTrainController::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_UISWTrainController.data,
    qt_meta_data_UISWTrainController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UISWTrainController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UISWTrainController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UISWTrainController.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int UISWTrainController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void UISWTrainController::getnewTCSignal(uint8_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
