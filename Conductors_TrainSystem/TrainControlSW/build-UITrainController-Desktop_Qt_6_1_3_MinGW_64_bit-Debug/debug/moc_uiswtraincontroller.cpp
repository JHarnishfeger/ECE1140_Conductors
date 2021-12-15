/****************************************************************************
** Meta object code from reading C++ file 'uiswtraincontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../UITrainController/uiswtraincontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiswtraincontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UISWTrainController_t {
    const uint offsetsAndSize[30];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_UISWTrainController_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_UISWTrainController_t qt_meta_stringdata_UISWTrainController = {
    {
QT_MOC_LITERAL(0, 19), // "UISWTrainController"
QT_MOC_LITERAL(20, 9), // "timerInst"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 31), // "on_driverEmergencyBrake_clicked"
QT_MOC_LITERAL(63, 25), // "on_leftDoors_valueChanged"
QT_MOC_LITERAL(89, 5), // "value"
QT_MOC_LITERAL(95, 26), // "on_rightDoors_valueChanged"
QT_MOC_LITERAL(122, 30), // "on_interiorLights_valueChanged"
QT_MOC_LITERAL(153, 30), // "on_exteriorLights_valueChanged"
QT_MOC_LITERAL(184, 23), // "on_serviceBrake_clicked"
QT_MOC_LITERAL(208, 26), // "on_modeswitch_valueChanged"
QT_MOC_LITERAL(235, 26), // "on_announceStation_clicked"
QT_MOC_LITERAL(262, 33), // "on_commandeVelocity_returnPre..."
QT_MOC_LITERAL(296, 19), // "on_kp_returnPressed"
QT_MOC_LITERAL(316, 19) // "on_ki_returnPressed"

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
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    0 /* Private */,
       3,    0,   87,    2, 0x08,    1 /* Private */,
       4,    1,   88,    2, 0x08,    2 /* Private */,
       6,    1,   91,    2, 0x08,    4 /* Private */,
       7,    1,   94,    2, 0x08,    6 /* Private */,
       8,    1,   97,    2, 0x08,    8 /* Private */,
       9,    0,  100,    2, 0x08,   10 /* Private */,
      10,    1,  101,    2, 0x08,   11 /* Private */,
      11,    0,  104,    2, 0x08,   13 /* Private */,
      12,    0,  105,    2, 0x08,   14 /* Private */,
      13,    0,  106,    2, 0x08,   15 /* Private */,
      14,    0,  107,    2, 0x08,   16 /* Private */,

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
        (void)_t;
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

const QMetaObject UISWTrainController::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_UISWTrainController.offsetsAndSize,
    qt_meta_data_UISWTrainController,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_UISWTrainController_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
