/****************************************************************************
** Meta object code from reading C++ file 'trackmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../AAA_TrainSystem/Conductors_TrainSystem/trackmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trackmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrackModel_t {
    QByteArrayData data[31];
    char stringdata0[510];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrackModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrackModel_t qt_meta_stringdata_TrackModel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TrackModel"
QT_MOC_LITERAL(1, 11, 9), // "giveTrack"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "vector<Block*>"
QT_MOC_LITERAL(4, 37, 3), // "red"
QT_MOC_LITERAL(5, 41, 5), // "green"
QT_MOC_LITERAL(6, 47, 14), // "updateWaysides"
QT_MOC_LITERAL(7, 62, 6), // "TCData"
QT_MOC_LITERAL(8, 69, 8), // "uint64_t"
QT_MOC_LITERAL(9, 78, 16), // "TrackCircuitData"
QT_MOC_LITERAL(10, 95, 2), // "ID"
QT_MOC_LITERAL(11, 98, 10), // "BeaconData"
QT_MOC_LITERAL(12, 109, 8), // "uint16_t"
QT_MOC_LITERAL(13, 118, 26), // "on_loadTrackButton_clicked"
QT_MOC_LITERAL(14, 145, 30), // "on_trackHeaterOnButton_clicked"
QT_MOC_LITERAL(15, 176, 31), // "on_trackHeaterOffButton_clicked"
QT_MOC_LITERAL(16, 208, 30), // "on_railStatusFixButton_clicked"
QT_MOC_LITERAL(17, 239, 32), // "on_railStatusBreakButton_clicked"
QT_MOC_LITERAL(18, 272, 27), // "on_circuitStatusFix_clicked"
QT_MOC_LITERAL(19, 300, 29), // "on_circuitStatusBreak_clicked"
QT_MOC_LITERAL(20, 330, 25), // "on_powerStatusFix_clicked"
QT_MOC_LITERAL(21, 356, 27), // "on_powerStatusBreak_clicked"
QT_MOC_LITERAL(22, 384, 28), // "on_selectBlockButton_clicked"
QT_MOC_LITERAL(23, 413, 13), // "updateDisplay"
QT_MOC_LITERAL(24, 427, 17), // "updateFromWayside"
QT_MOC_LITERAL(25, 445, 13), // "vector<Block>"
QT_MOC_LITERAL(26, 459, 14), // "wasysideBlocks"
QT_MOC_LITERAL(27, 474, 9), // "TrainInfo"
QT_MOC_LITERAL(28, 484, 7), // "uint8_t"
QT_MOC_LITERAL(29, 492, 12), // "currentBlock"
QT_MOC_LITERAL(30, 505, 4) // "line"

    },
    "TrackModel\0giveTrack\0\0vector<Block*>\0"
    "red\0green\0updateWaysides\0TCData\0"
    "uint64_t\0TrackCircuitData\0ID\0BeaconData\0"
    "uint16_t\0on_loadTrackButton_clicked\0"
    "on_trackHeaterOnButton_clicked\0"
    "on_trackHeaterOffButton_clicked\0"
    "on_railStatusFixButton_clicked\0"
    "on_railStatusBreakButton_clicked\0"
    "on_circuitStatusFix_clicked\0"
    "on_circuitStatusBreak_clicked\0"
    "on_powerStatusFix_clicked\0"
    "on_powerStatusBreak_clicked\0"
    "on_selectBlockButton_clicked\0updateDisplay\0"
    "updateFromWayside\0vector<Block>\0"
    "wasysideBlocks\0TrainInfo\0uint8_t\0"
    "currentBlock\0line"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrackModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   99,    2, 0x06 /* Public */,
       6,    2,  104,    2, 0x06 /* Public */,
       7,    2,  109,    2, 0x06 /* Public */,
      11,    2,  114,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  119,    2, 0x08 /* Private */,
      14,    0,  120,    2, 0x08 /* Private */,
      15,    0,  121,    2, 0x08 /* Private */,
      16,    0,  122,    2, 0x08 /* Private */,
      17,    0,  123,    2, 0x08 /* Private */,
      18,    0,  124,    2, 0x08 /* Private */,
      19,    0,  125,    2, 0x08 /* Private */,
      20,    0,  126,    2, 0x08 /* Private */,
      21,    0,  127,    2, 0x08 /* Private */,
      22,    0,  128,    2, 0x08 /* Private */,
      23,    0,  129,    2, 0x08 /* Private */,
      24,    1,  130,    2, 0x0a /* Public */,
      27,    3,  133,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int,    9,   10,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int,   11,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, 0x80000000 | 28, QMetaType::Int, QMetaType::Bool,   29,   10,   30,

       0        // eod
};

void TrackModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrackModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->giveTrack((*reinterpret_cast< vector<Block*>(*)>(_a[1])),(*reinterpret_cast< vector<Block*>(*)>(_a[2]))); break;
        case 1: _t->updateWaysides((*reinterpret_cast< vector<Block*>(*)>(_a[1])),(*reinterpret_cast< vector<Block*>(*)>(_a[2]))); break;
        case 2: _t->TCData((*reinterpret_cast< uint64_t(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->BeaconData((*reinterpret_cast< uint16_t(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_loadTrackButton_clicked(); break;
        case 5: _t->on_trackHeaterOnButton_clicked(); break;
        case 6: _t->on_trackHeaterOffButton_clicked(); break;
        case 7: _t->on_railStatusFixButton_clicked(); break;
        case 8: _t->on_railStatusBreakButton_clicked(); break;
        case 9: _t->on_circuitStatusFix_clicked(); break;
        case 10: _t->on_circuitStatusBreak_clicked(); break;
        case 11: _t->on_powerStatusFix_clicked(); break;
        case 12: _t->on_powerStatusBreak_clicked(); break;
        case 13: _t->on_selectBlockButton_clicked(); break;
        case 14: _t->updateDisplay(); break;
        case 15: _t->updateFromWayside((*reinterpret_cast< vector<Block>(*)>(_a[1]))); break;
        case 16: _t->TrainInfo((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TrackModel::*)(vector<Block*> , vector<Block*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrackModel::giveTrack)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TrackModel::*)(vector<Block*> , vector<Block*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrackModel::updateWaysides)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TrackModel::*)(uint64_t , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrackModel::TCData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TrackModel::*)(uint16_t , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrackModel::BeaconData)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TrackModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_TrackModel.data,
    qt_meta_data_TrackModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TrackModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrackModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrackModel.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TrackModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void TrackModel::giveTrack(vector<Block*> _t1, vector<Block*> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TrackModel::updateWaysides(vector<Block*> _t1, vector<Block*> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TrackModel::TCData(uint64_t _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TrackModel::BeaconData(uint16_t _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
