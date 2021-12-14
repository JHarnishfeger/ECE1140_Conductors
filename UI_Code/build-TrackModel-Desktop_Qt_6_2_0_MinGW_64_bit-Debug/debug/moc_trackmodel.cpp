/****************************************************************************
** Meta object code from reading C++ file 'trackmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../TrackModel/trackmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trackmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrackModel_t {
    const uint offsetsAndSize[40];
    char stringdata0[404];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TrackModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TrackModel_t qt_meta_stringdata_TrackModel = {
    {
QT_MOC_LITERAL(0, 10), // "TrackModel"
QT_MOC_LITERAL(11, 9), // "giveTrack"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 14), // "vector<Block*>"
QT_MOC_LITERAL(37, 3), // "red"
QT_MOC_LITERAL(41, 5), // "green"
QT_MOC_LITERAL(47, 14), // "updateWaysides"
QT_MOC_LITERAL(62, 26), // "on_loadTrackButton_clicked"
QT_MOC_LITERAL(89, 30), // "on_trackHeaterOnButton_clicked"
QT_MOC_LITERAL(120, 31), // "on_trackHeaterOffButton_clicked"
QT_MOC_LITERAL(152, 30), // "on_railStatusFixButton_clicked"
QT_MOC_LITERAL(183, 32), // "on_railStatusBreakButton_clicked"
QT_MOC_LITERAL(216, 27), // "on_circuitStatusFix_clicked"
QT_MOC_LITERAL(244, 29), // "on_circuitStatusBreak_clicked"
QT_MOC_LITERAL(274, 25), // "on_powerStatusFix_clicked"
QT_MOC_LITERAL(300, 27), // "on_powerStatusBreak_clicked"
QT_MOC_LITERAL(328, 28), // "on_selectBlockButton_clicked"
QT_MOC_LITERAL(357, 17), // "updateFromWayside"
QT_MOC_LITERAL(375, 13), // "vector<Block>"
QT_MOC_LITERAL(389, 14) // "wasysideBlocks"

    },
    "TrackModel\0giveTrack\0\0vector<Block*>\0"
    "red\0green\0updateWaysides\0"
    "on_loadTrackButton_clicked\0"
    "on_trackHeaterOnButton_clicked\0"
    "on_trackHeaterOffButton_clicked\0"
    "on_railStatusFixButton_clicked\0"
    "on_railStatusBreakButton_clicked\0"
    "on_circuitStatusFix_clicked\0"
    "on_circuitStatusBreak_clicked\0"
    "on_powerStatusFix_clicked\0"
    "on_powerStatusBreak_clicked\0"
    "on_selectBlockButton_clicked\0"
    "updateFromWayside\0vector<Block>\0"
    "wasysideBlocks"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrackModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   92,    2, 0x06,    1 /* Public */,
       6,    2,   97,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,  102,    2, 0x08,    7 /* Private */,
       8,    0,  103,    2, 0x08,    8 /* Private */,
       9,    0,  104,    2, 0x08,    9 /* Private */,
      10,    0,  105,    2, 0x08,   10 /* Private */,
      11,    0,  106,    2, 0x08,   11 /* Private */,
      12,    0,  107,    2, 0x08,   12 /* Private */,
      13,    0,  108,    2, 0x08,   13 /* Private */,
      14,    0,  109,    2, 0x08,   14 /* Private */,
      15,    0,  110,    2, 0x08,   15 /* Private */,
      16,    0,  111,    2, 0x08,   16 /* Private */,
      17,    1,  112,    2, 0x0a,   17 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

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
    QMetaType::Void, 0x80000000 | 18,   19,

       0        // eod
};

void TrackModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrackModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->giveTrack((*reinterpret_cast< vector<Block*>(*)>(_a[1])),(*reinterpret_cast< vector<Block*>(*)>(_a[2]))); break;
        case 1: _t->updateWaysides((*reinterpret_cast< vector<Block*>(*)>(_a[1])),(*reinterpret_cast< vector<Block*>(*)>(_a[2]))); break;
        case 2: _t->on_loadTrackButton_clicked(); break;
        case 3: _t->on_trackHeaterOnButton_clicked(); break;
        case 4: _t->on_trackHeaterOffButton_clicked(); break;
        case 5: _t->on_railStatusFixButton_clicked(); break;
        case 6: _t->on_railStatusBreakButton_clicked(); break;
        case 7: _t->on_circuitStatusFix_clicked(); break;
        case 8: _t->on_circuitStatusBreak_clicked(); break;
        case 9: _t->on_powerStatusFix_clicked(); break;
        case 10: _t->on_powerStatusBreak_clicked(); break;
        case 11: _t->on_selectBlockButton_clicked(); break;
        case 12: _t->updateFromWayside((*reinterpret_cast< vector<Block>(*)>(_a[1]))); break;
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
    }
}

const QMetaObject TrackModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_TrackModel.offsetsAndSize,
    qt_meta_data_TrackModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TrackModel_t
, QtPrivate::TypeAndForceComplete<TrackModel, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<Block*>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<Block*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<Block*>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<Block*>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<Block>, std::false_type>


>,
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
