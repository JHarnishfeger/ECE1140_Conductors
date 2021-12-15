/****************************************************************************
** Meta object code from reading C++ file 'trainmaker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../AAA_TrainSystem/Conductors_TrainSystem/TrainModel/trainmaker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trainmaker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_trainMaker_t {
    QByteArrayData data[21];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_trainMaker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_trainMaker_t qt_meta_stringdata_trainMaker = {
    {
QT_MOC_LITERAL(0, 0, 10), // "trainMaker"
QT_MOC_LITERAL(1, 11, 9), // "TrainInfo"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "uint8_t"
QT_MOC_LITERAL(4, 30, 12), // "currentBlock"
QT_MOC_LITERAL(5, 43, 2), // "ID"
QT_MOC_LITERAL(6, 46, 4), // "RorG"
QT_MOC_LITERAL(7, 51, 14), // "transferCoords"
QT_MOC_LITERAL(8, 66, 7), // "trainID"
QT_MOC_LITERAL(9, 74, 8), // "distance"
QT_MOC_LITERAL(10, 83, 7), // "update2"
QT_MOC_LITERAL(11, 91, 6), // "TCData"
QT_MOC_LITERAL(12, 98, 8), // "uint64_t"
QT_MOC_LITERAL(13, 107, 16), // "TrackCircuitData"
QT_MOC_LITERAL(14, 124, 10), // "BeaconData"
QT_MOC_LITERAL(15, 135, 8), // "uint16_t"
QT_MOC_LITERAL(16, 144, 7), // "setAuth"
QT_MOC_LITERAL(17, 152, 12), // "authDistance"
QT_MOC_LITERAL(18, 165, 9), // "authSpeed"
QT_MOC_LITERAL(19, 175, 15), // "callAgainTCData"
QT_MOC_LITERAL(20, 191, 6) // "update"

    },
    "trainMaker\0TrainInfo\0\0uint8_t\0"
    "currentBlock\0ID\0RorG\0transferCoords\0"
    "trainID\0distance\0update2\0TCData\0"
    "uint64_t\0TrackCircuitData\0BeaconData\0"
    "uint16_t\0setAuth\0authDistance\0authSpeed\0"
    "callAgainTCData\0update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_trainMaker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   54,    2, 0x06 /* Public */,
       7,    3,   61,    2, 0x06 /* Public */,
      10,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    2,   69,    2, 0x0a /* Public */,
      14,    2,   74,    2, 0x0a /* Public */,
      16,    3,   79,    2, 0x0a /* Public */,
      19,    3,   86,    2, 0x0a /* Public */,
      20,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Bool,    4,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double,    8,    4,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int,   13,    5,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int,   14,    5,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int,   17,   18,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Bool,    4,    8,    6,
    QMetaType::Void,

       0        // eod
};

void trainMaker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<trainMaker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TrainInfo((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->transferCoords((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->update2(); break;
        case 3: _t->TCData((*reinterpret_cast< uint64_t(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->BeaconData((*reinterpret_cast< uint16_t(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->setAuth((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->callAgainTCData((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 7: _t->update(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (trainMaker::*)(uint8_t , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&trainMaker::TrainInfo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (trainMaker::*)(int , int , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&trainMaker::transferCoords)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (trainMaker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&trainMaker::update2)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject trainMaker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_trainMaker.data,
    qt_meta_data_trainMaker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *trainMaker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *trainMaker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_trainMaker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int trainMaker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void trainMaker::TrainInfo(uint8_t _t1, int _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void trainMaker::transferCoords(int _t1, int _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void trainMaker::update2()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
