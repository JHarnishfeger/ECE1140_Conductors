/****************************************************************************
** Meta object code from reading C++ file 'uiswtraincontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../UITrainController/uiswtraincontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiswtraincontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UISWTrainController_t {
    QByteArrayData data[15];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UISWTrainController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UISWTrainController_t qt_meta_stringdata_UISWTrainController = {
    {
QT_MOC_LITERAL(0, 0, 19), // "UISWTrainController"
QT_MOC_LITERAL(1, 20, 9), // "timerInst"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 31), // "on_driverEmergencyBrake_clicked"
QT_MOC_LITERAL(4, 63, 25), // "on_leftDoors_valueChanged"
QT_MOC_LITERAL(5, 89, 5), // "value"
QT_MOC_LITERAL(6, 95, 26), // "on_rightDoors_valueChanged"
QT_MOC_LITERAL(7, 122, 30), // "on_interiorLights_valueChanged"
QT_MOC_LITERAL(8, 153, 30), // "on_exteriorLights_valueChanged"
QT_MOC_LITERAL(9, 184, 23), // "on_serviceBrake_clicked"
QT_MOC_LITERAL(10, 208, 26), // "on_modeswitch_valueChanged"
QT_MOC_LITERAL(11, 235, 26), // "on_announceStation_clicked"
QT_MOC_LITERAL(12, 262, 33), // "on_commandeVelocity_returnPre..."
QT_MOC_LITERAL(13, 296, 19), // "on_kp_returnPressed"
QT_MOC_LITERAL(14, 316, 19) // "on_ki_returnPressed"

    },
    "UISWTrainController\0timerInst\0\0"
    "on_driverEmergencyBrake_clicked\0"
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
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    1,   76,    2, 0x08 /* Private */,
       6,    1,   79,    2, 0x08 /* Private */,
       7,    1,   82,    2, 0x08 /* Private */,
       8,    1,   85,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    1,   89,    2, 0x08 /* Private */,
      11,    0,   92,    2, 0x08 /* Private */,
      12,    0,   93,    2, 0x08 /* Private */,
      13,    0,   94,    2, 0x08 /* Private */,
      14,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
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
        case 0: _t->timerInst(); break;
        case 1: _t->on_driverEmergencyBrake_clicked(); break;
        case 2: _t->on_leftDoors_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_rightDoors_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_interiorLights_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_exteriorLights_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_serviceBrake_clicked(); break;
        case 7: _t->on_modeswitch_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_announceStation_clicked(); break;
        case 9: _t->on_commandeVelocity_returnPressed(); break;
        case 10: _t->on_kp_returnPressed(); break;
        case 11: _t->on_ki_returnPressed(); break;
        default: ;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
