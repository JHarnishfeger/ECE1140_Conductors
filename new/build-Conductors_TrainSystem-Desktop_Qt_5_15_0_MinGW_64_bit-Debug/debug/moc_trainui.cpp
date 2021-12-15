/****************************************************************************
** Meta object code from reading C++ file 'trainui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../AAA_TrainSystem/Conductors_TrainSystem/TrainModel/trainui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trainui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_trainUI_t {
    QByteArrayData data[19];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_trainUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_trainUI_t qt_meta_stringdata_trainUI = {
    {
QT_MOC_LITERAL(0, 0, 7), // "trainUI"
QT_MOC_LITERAL(1, 8, 15), // "callAgainTCData"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "uint8_t"
QT_MOC_LITERAL(4, 33, 12), // "currentBlock"
QT_MOC_LITERAL(5, 46, 7), // "trainID"
QT_MOC_LITERAL(6, 54, 4), // "RorG"
QT_MOC_LITERAL(7, 59, 7), // "update3"
QT_MOC_LITERAL(8, 67, 8), // "setBFail"
QT_MOC_LITERAL(9, 76, 8), // "setEFail"
QT_MOC_LITERAL(10, 85, 8), // "setSFail"
QT_MOC_LITERAL(11, 94, 8), // "updateUI"
QT_MOC_LITERAL(12, 103, 26), // "on_Temp_Change_sliderMoved"
QT_MOC_LITERAL(13, 130, 8), // "position"
QT_MOC_LITERAL(14, 139, 20), // "on_BrakeFail_clicked"
QT_MOC_LITERAL(15, 160, 21), // "on_EngineFail_clicked"
QT_MOC_LITERAL(16, 182, 21), // "on_SignalFail_clicked"
QT_MOC_LITERAL(17, 204, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(18, 226, 10) // "callTCData"

    },
    "trainUI\0callAgainTCData\0\0uint8_t\0"
    "currentBlock\0trainID\0RorG\0update3\0"
    "setBFail\0setEFail\0setSFail\0updateUI\0"
    "on_Temp_Change_sliderMoved\0position\0"
    "on_BrakeFail_clicked\0on_EngineFail_clicked\0"
    "on_SignalFail_clicked\0on_pushButton_clicked\0"
    "callTCData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_trainUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   74,    2, 0x06 /* Public */,
       7,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   82,    2, 0x0a /* Public */,
       9,    0,   83,    2, 0x0a /* Public */,
      10,    0,   84,    2, 0x0a /* Public */,
      11,    0,   85,    2, 0x0a /* Public */,
      12,    1,   86,    2, 0x0a /* Public */,
      14,    0,   89,    2, 0x0a /* Public */,
      15,    0,   90,    2, 0x0a /* Public */,
      16,    0,   91,    2, 0x0a /* Public */,
      17,    0,   92,    2, 0x0a /* Public */,
      18,    1,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Bool,    4,    5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void trainUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<trainUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->callAgainTCData((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->update3(); break;
        case 2: { QString _r = _t->setBFail();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->setEFail();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->setSFail();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->updateUI(); break;
        case 6: _t->on_Temp_Change_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_BrakeFail_clicked(); break;
        case 8: _t->on_EngineFail_clicked(); break;
        case 9: _t->on_SignalFail_clicked(); break;
        case 10: _t->on_pushButton_clicked(); break;
        case 11: _t->callTCData((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (trainUI::*)(uint8_t , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&trainUI::callAgainTCData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (trainUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&trainUI::update3)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject trainUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_trainUI.data,
    qt_meta_data_trainUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *trainUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *trainUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_trainUI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int trainUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void trainUI::callAgainTCData(uint8_t _t1, int _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void trainUI::update3()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
