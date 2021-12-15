/****************************************************************************
** Meta object code from reading C++ file 'ctcwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../AAA_TrainSystem/Conductors_TrainSystem/ctcwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ctcwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CTCWindow_t {
    QByteArrayData data[20];
    char stringdata0[465];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CTCWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CTCWindow_t qt_meta_stringdata_CTCWindow = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CTCWindow"
QT_MOC_LITERAL(1, 10, 12), // "makeNewTrain"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 20), // "initializeWaystructs"
QT_MOC_LITERAL(4, 45, 23), // "std::vector<WayStruct>*"
QT_MOC_LITERAL(5, 69, 13), // "sw_waystructs"
QT_MOC_LITERAL(6, 83, 10), // "WayStruct*"
QT_MOC_LITERAL(7, 94, 12), // "hw_waystruct"
QT_MOC_LITERAL(8, 107, 16), // "makeNewTrainEmit"
QT_MOC_LITERAL(9, 124, 6), // "update"
QT_MOC_LITERAL(10, 131, 32), // "on_button_chooseSchedule_clicked"
QT_MOC_LITERAL(11, 164, 36), // "on_horizontalSlider_mode_slid..."
QT_MOC_LITERAL(12, 201, 8), // "position"
QT_MOC_LITERAL(13, 210, 37), // "on_lineEdit_selectBlock_retur..."
QT_MOC_LITERAL(14, 248, 46), // "on_pushButton_openCloseForMai..."
QT_MOC_LITERAL(15, 295, 35), // "on_pushButton_selectBlockGo_c..."
QT_MOC_LITERAL(16, 331, 35), // "on_pushButton_dispatchTrain_c..."
QT_MOC_LITERAL(17, 367, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(18, 389, 37), // "on_pushButton_openCloseSwitch..."
QT_MOC_LITERAL(19, 427, 37) // "on_pushButton_dispatchTrain_2..."

    },
    "CTCWindow\0makeNewTrain\0\0initializeWaystructs\0"
    "std::vector<WayStruct>*\0sw_waystructs\0"
    "WayStruct*\0hw_waystruct\0makeNewTrainEmit\0"
    "update\0on_button_chooseSchedule_clicked\0"
    "on_horizontalSlider_mode_sliderMoved\0"
    "position\0on_lineEdit_selectBlock_returnPressed\0"
    "on_pushButton_openCloseForMaintenecnce_clicked\0"
    "on_pushButton_selectBlockGo_clicked\0"
    "on_pushButton_dispatchTrain_clicked\0"
    "on_comboBox_activated\0"
    "on_pushButton_openCloseSwitch_clicked\0"
    "on_pushButton_dispatchTrain_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CTCWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   80,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    1,   88,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,
      16,    0,   94,    2, 0x08 /* Private */,
      17,    0,   95,    2, 0x08 /* Private */,
      18,    0,   96,    2, 0x08 /* Private */,
      19,    0,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CTCWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CTCWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->makeNewTrain(); break;
        case 1: _t->initializeWaystructs((*reinterpret_cast< std::vector<WayStruct>*(*)>(_a[1])),(*reinterpret_cast< WayStruct*(*)>(_a[2]))); break;
        case 2: _t->makeNewTrainEmit(); break;
        case 3: _t->update(); break;
        case 4: _t->on_button_chooseSchedule_clicked(); break;
        case 5: _t->on_horizontalSlider_mode_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_lineEdit_selectBlock_returnPressed(); break;
        case 7: _t->on_pushButton_openCloseForMaintenecnce_clicked(); break;
        case 8: _t->on_pushButton_selectBlockGo_clicked(); break;
        case 9: _t->on_pushButton_dispatchTrain_clicked(); break;
        case 10: _t->on_comboBox_activated(); break;
        case 11: _t->on_pushButton_openCloseSwitch_clicked(); break;
        case 12: _t->on_pushButton_dispatchTrain_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CTCWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CTCWindow::makeNewTrain)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CTCWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CTCWindow.data,
    qt_meta_data_CTCWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CTCWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTCWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CTCWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CTCWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CTCWindow::makeNewTrain()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
