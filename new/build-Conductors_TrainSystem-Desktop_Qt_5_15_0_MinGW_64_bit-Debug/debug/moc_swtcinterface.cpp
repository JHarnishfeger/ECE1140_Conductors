/****************************************************************************
** Meta object code from reading C++ file 'swtcinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../AAA_TrainSystem/Conductors_TrainSystem/swtcinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'swtcinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SWTCInterface_t {
    QByteArrayData data[31];
    char stringdata0[393];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SWTCInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SWTCInterface_t qt_meta_stringdata_SWTCInterface = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SWTCInterface"
QT_MOC_LITERAL(1, 14, 5), // "hwSet"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "vector<Block>"
QT_MOC_LITERAL(4, 35, 5), // "hwtrk"
QT_MOC_LITERAL(5, 41, 11), // "waysidesSet"
QT_MOC_LITERAL(6, 53, 23), // "std::vector<WayStruct>*"
QT_MOC_LITERAL(7, 77, 13), // "sw_waystructs"
QT_MOC_LITERAL(8, 91, 10), // "WayStruct*"
QT_MOC_LITERAL(9, 102, 12), // "hw_waystruct"
QT_MOC_LITERAL(10, 115, 23), // "updateWaysidesFromTrack"
QT_MOC_LITERAL(11, 139, 14), // "vector<Block*>"
QT_MOC_LITERAL(12, 154, 3), // "red"
QT_MOC_LITERAL(13, 158, 5), // "green"
QT_MOC_LITERAL(14, 164, 13), // "updateToTrack"
QT_MOC_LITERAL(15, 178, 25), // "on_CreateWaysides_clicked"
QT_MOC_LITERAL(16, 204, 29), // "on_DesignateHWWayside_clicked"
QT_MOC_LITERAL(17, 234, 26), // "on_WaysideList_itemClicked"
QT_MOC_LITERAL(18, 261, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(19, 278, 4), // "item"
QT_MOC_LITERAL(20, 283, 24), // "on_autoMode_stateChanged"
QT_MOC_LITERAL(21, 308, 4), // "arg1"
QT_MOC_LITERAL(22, 313, 8), // "setTrack"
QT_MOC_LITERAL(23, 322, 2), // "rl"
QT_MOC_LITERAL(24, 325, 2), // "gl"
QT_MOC_LITERAL(25, 328, 14), // "getHWWaystruct"
QT_MOC_LITERAL(26, 343, 8), // "hwWaystr"
QT_MOC_LITERAL(27, 352, 6), // "update"
QT_MOC_LITERAL(28, 359, 15), // "updateFromTrack"
QT_MOC_LITERAL(29, 375, 13), // "updateWayside"
QT_MOC_LITERAL(30, 389, 3) // "sec"

    },
    "SWTCInterface\0hwSet\0\0vector<Block>\0"
    "hwtrk\0waysidesSet\0std::vector<WayStruct>*\0"
    "sw_waystructs\0WayStruct*\0hw_waystruct\0"
    "updateWaysidesFromTrack\0vector<Block*>\0"
    "red\0green\0updateToTrack\0"
    "on_CreateWaysides_clicked\0"
    "on_DesignateHWWayside_clicked\0"
    "on_WaysideList_itemClicked\0QListWidgetItem*\0"
    "item\0on_autoMode_stateChanged\0arg1\0"
    "setTrack\0rl\0gl\0getHWWaystruct\0hwWaystr\0"
    "update\0updateFromTrack\0updateWayside\0"
    "sec"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SWTCInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       5,    2,   82,    2, 0x06 /* Public */,
      10,    2,   87,    2, 0x06 /* Public */,
      14,    1,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,   95,    2, 0x08 /* Private */,
      16,    0,   96,    2, 0x08 /* Private */,
      17,    1,   97,    2, 0x08 /* Private */,
      20,    1,  100,    2, 0x08 /* Private */,
      22,    2,  103,    2, 0x0a /* Public */,
      25,    1,  108,    2, 0x0a /* Public */,
      27,    0,  111,    2, 0x0a /* Public */,
      28,    2,  112,    2, 0x0a /* Public */,
      29,    1,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 11,   12,   13,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 11,   23,   24,
    QMetaType::Void, 0x80000000 | 8,   26,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 11,   12,   13,
    QMetaType::Void, 0x80000000 | 3,   30,

       0        // eod
};

void SWTCInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SWTCInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hwSet((*reinterpret_cast< vector<Block>(*)>(_a[1]))); break;
        case 1: _t->waysidesSet((*reinterpret_cast< std::vector<WayStruct>*(*)>(_a[1])),(*reinterpret_cast< WayStruct*(*)>(_a[2]))); break;
        case 2: _t->updateWaysidesFromTrack((*reinterpret_cast< vector<Block*>(*)>(_a[1])),(*reinterpret_cast< vector<Block*>(*)>(_a[2]))); break;
        case 3: _t->updateToTrack((*reinterpret_cast< vector<Block>(*)>(_a[1]))); break;
        case 4: _t->on_CreateWaysides_clicked(); break;
        case 5: _t->on_DesignateHWWayside_clicked(); break;
        case 6: _t->on_WaysideList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->on_autoMode_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setTrack((*reinterpret_cast< vector<Block*>(*)>(_a[1])),(*reinterpret_cast< vector<Block*>(*)>(_a[2]))); break;
        case 9: _t->getHWWaystruct((*reinterpret_cast< WayStruct*(*)>(_a[1]))); break;
        case 10: _t->update(); break;
        case 11: _t->updateFromTrack((*reinterpret_cast< vector<Block*>(*)>(_a[1])),(*reinterpret_cast< vector<Block*>(*)>(_a[2]))); break;
        case 12: _t->updateWayside((*reinterpret_cast< vector<Block>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SWTCInterface::*)(vector<Block> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SWTCInterface::hwSet)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SWTCInterface::*)(std::vector<WayStruct> * , WayStruct * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SWTCInterface::waysidesSet)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SWTCInterface::*)(vector<Block*> , vector<Block*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SWTCInterface::updateWaysidesFromTrack)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SWTCInterface::*)(vector<Block> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SWTCInterface::updateToTrack)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SWTCInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SWTCInterface.data,
    qt_meta_data_SWTCInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SWTCInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SWTCInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SWTCInterface.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SWTCInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void SWTCInterface::hwSet(vector<Block> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SWTCInterface::waysidesSet(std::vector<WayStruct> * _t1, WayStruct * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SWTCInterface::updateWaysidesFromTrack(vector<Block*> _t1, vector<Block*> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SWTCInterface::updateToTrack(vector<Block> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
