/****************************************************************************
** Meta object code from reading C++ file 'hwtcinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../AAA_TrainSystem/Conductors_TrainSystem/hwtcinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hwtcinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HWTCInterface_t {
    QByteArrayData data[22];
    char stringdata0[286];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HWTCInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HWTCInterface_t qt_meta_stringdata_HWTCInterface = {
    {
QT_MOC_LITERAL(0, 0, 13), // "HWTCInterface"
QT_MOC_LITERAL(1, 14, 15), // "sendHWWayStruct"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "WayStruct*"
QT_MOC_LITERAL(4, 42, 3), // "way"
QT_MOC_LITERAL(5, 46, 15), // "updateToHWTrack"
QT_MOC_LITERAL(6, 62, 13), // "vector<Block>"
QT_MOC_LITERAL(7, 76, 5), // "track"
QT_MOC_LITERAL(8, 82, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 104, 24), // "on_blockList_itemClicked"
QT_MOC_LITERAL(10, 129, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(11, 146, 4), // "item"
QT_MOC_LITERAL(12, 151, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(13, 175, 23), // "on_ModeBox_stateChanged"
QT_MOC_LITERAL(14, 199, 4), // "arg1"
QT_MOC_LITERAL(15, 204, 20), // "on_PLCButton_clicked"
QT_MOC_LITERAL(16, 225, 8), // "setTrack"
QT_MOC_LITERAL(17, 234, 17), // "updateFromHWTrack"
QT_MOC_LITERAL(18, 252, 14), // "vector<Block*>"
QT_MOC_LITERAL(19, 267, 3), // "red"
QT_MOC_LITERAL(20, 271, 5), // "green"
QT_MOC_LITERAL(21, 277, 8) // "runHWPLC"

    },
    "HWTCInterface\0sendHWWayStruct\0\0"
    "WayStruct*\0way\0updateToHWTrack\0"
    "vector<Block>\0track\0on_pushButton_clicked\0"
    "on_blockList_itemClicked\0QListWidgetItem*\0"
    "item\0on_pushButton_2_clicked\0"
    "on_ModeBox_stateChanged\0arg1\0"
    "on_PLCButton_clicked\0setTrack\0"
    "updateFromHWTrack\0vector<Block*>\0red\0"
    "green\0runHWPLC"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HWTCInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   70,    2, 0x08 /* Private */,
       9,    1,   71,    2, 0x08 /* Private */,
      12,    0,   74,    2, 0x08 /* Private */,
      13,    1,   75,    2, 0x08 /* Private */,
      15,    0,   78,    2, 0x08 /* Private */,
      16,    1,   79,    2, 0x0a /* Public */,
      17,    2,   82,    2, 0x0a /* Public */,
      21,    0,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 18,   19,   20,
    QMetaType::Void,

       0        // eod
};

void HWTCInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HWTCInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendHWWayStruct((*reinterpret_cast< WayStruct*(*)>(_a[1]))); break;
        case 1: _t->updateToHWTrack((*reinterpret_cast< vector<Block>(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_blockList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->on_ModeBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_PLCButton_clicked(); break;
        case 7: _t->setTrack((*reinterpret_cast< vector<Block>(*)>(_a[1]))); break;
        case 8: _t->updateFromHWTrack((*reinterpret_cast< vector<Block*>(*)>(_a[1])),(*reinterpret_cast< vector<Block*>(*)>(_a[2]))); break;
        case 9: _t->runHWPLC(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HWTCInterface::*)(WayStruct * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HWTCInterface::sendHWWayStruct)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HWTCInterface::*)(vector<Block> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HWTCInterface::updateToHWTrack)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HWTCInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_HWTCInterface.data,
    qt_meta_data_HWTCInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HWTCInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HWTCInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HWTCInterface.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int HWTCInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void HWTCInterface::sendHWWayStruct(WayStruct * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HWTCInterface::updateToHWTrack(vector<Block> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
