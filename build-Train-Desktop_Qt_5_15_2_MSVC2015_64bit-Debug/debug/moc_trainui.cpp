/****************************************************************************
** Meta object code from reading C++ file 'trainui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../HWTrainController/TrainModel/trainui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trainui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_trainUI_t {
    QByteArrayData data[17];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_trainUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_trainUI_t qt_meta_stringdata_trainUI = {
    {
QT_MOC_LITERAL(0, 0, 7), // "trainUI"
QT_MOC_LITERAL(1, 8, 8), // "setBFail"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 2), // "bf"
QT_MOC_LITERAL(4, 21, 8), // "setEFail"
QT_MOC_LITERAL(5, 30, 2), // "ef"
QT_MOC_LITERAL(6, 33, 8), // "setSFail"
QT_MOC_LITERAL(7, 42, 2), // "sf"
QT_MOC_LITERAL(8, 45, 12), // "updateTestUI"
QT_MOC_LITERAL(9, 58, 30), // "on_Temp_Change_actionTriggered"
QT_MOC_LITERAL(10, 89, 6), // "action"
QT_MOC_LITERAL(11, 96, 26), // "on_Temp_Change_sliderMoved"
QT_MOC_LITERAL(12, 123, 8), // "position"
QT_MOC_LITERAL(13, 132, 20), // "on_BrakeFail_clicked"
QT_MOC_LITERAL(14, 153, 21), // "on_EngineFail_clicked"
QT_MOC_LITERAL(15, 175, 21), // "on_SignalFail_clicked"
QT_MOC_LITERAL(16, 197, 21) // "on_pushButton_clicked"

    },
    "trainUI\0setBFail\0\0bf\0setEFail\0ef\0"
    "setSFail\0sf\0updateTestUI\0"
    "on_Temp_Change_actionTriggered\0action\0"
    "on_Temp_Change_sliderMoved\0position\0"
    "on_BrakeFail_clicked\0on_EngineFail_clicked\0"
    "on_SignalFail_clicked\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_trainUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    1,   67,    2, 0x08 /* Private */,
       6,    1,   70,    2, 0x08 /* Private */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    1,   74,    2, 0x08 /* Private */,
      11,    1,   77,    2, 0x08 /* Private */,
      13,    0,   80,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x08 /* Private */,
      15,    0,   82,    2, 0x08 /* Private */,
      16,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::QString, QMetaType::Bool,    3,
    QMetaType::QString, QMetaType::Bool,    5,
    QMetaType::QString, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void trainUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<trainUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->setBFail((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->setEFail((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->setSFail((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->updateTestUI(); break;
        case 4: _t->on_Temp_Change_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_Temp_Change_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_BrakeFail_clicked(); break;
        case 7: _t->on_EngineFail_clicked(); break;
        case 8: _t->on_SignalFail_clicked(); break;
        case 9: _t->on_pushButton_clicked(); break;
        default: ;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
