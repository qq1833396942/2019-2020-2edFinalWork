/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../project_one/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "on_add_clicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "on_cut_clicked"
QT_MOC_LITERAL(4, 42, 16), // "on_check_clicked"
QT_MOC_LITERAL(5, 59, 16), // "on_LoopA_clicked"
QT_MOC_LITERAL(6, 76, 16), // "on_LoopB_clicked"
QT_MOC_LITERAL(7, 93, 4), // "cutm"
QT_MOC_LITERAL(8, 98, 1), // "m"
QT_MOC_LITERAL(9, 100, 5), // "cutmn"
QT_MOC_LITERAL(10, 106, 1), // "n"
QT_MOC_LITERAL(11, 108, 15), // "EntryNodeOfLoop"
QT_MOC_LITERAL(12, 124, 8), // "LinkList"
QT_MOC_LITERAL(13, 133, 1), // "L"
QT_MOC_LITERAL(14, 135, 15), // "EntryNodeOfToop"
QT_MOC_LITERAL(15, 151, 7), // "reBuild"
QT_MOC_LITERAL(16, 159, 1), // "T"
QT_MOC_LITERAL(17, 161, 15), // "on_lift_clicked"
QT_MOC_LITERAL(18, 177, 11), // "IsIntersect"
QT_MOC_LITERAL(19, 189, 6), // "LNode*"
QT_MOC_LITERAL(20, 196, 21) // "on_pushButton_clicked"

    },
    "MainWindow\0on_add_clicked\0\0on_cut_clicked\0"
    "on_check_clicked\0on_LoopA_clicked\0"
    "on_LoopB_clicked\0cutm\0m\0cutmn\0n\0"
    "EntryNodeOfLoop\0LinkList\0L\0EntryNodeOfToop\0"
    "reBuild\0T\0on_lift_clicked\0IsIntersect\0"
    "LNode*\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    1,   84,    2, 0x08 /* Private */,
       9,    2,   87,    2, 0x08 /* Private */,
      11,    1,   92,    2, 0x08 /* Private */,
      14,    1,   95,    2, 0x08 /* Private */,
      15,    4,   98,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,
      18,    2,  108,    2, 0x08 /* Private */,
      20,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 12, QMetaType::Int, QMetaType::Int,   13,   16,    8,   10,
    QMetaType::Void,
    0x80000000 | 19, 0x80000000 | 12, 0x80000000 | 12,   13,   16,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_add_clicked(); break;
        case 1: _t->on_cut_clicked(); break;
        case 2: _t->on_check_clicked(); break;
        case 3: _t->on_LoopA_clicked(); break;
        case 4: _t->on_LoopB_clicked(); break;
        case 5: _t->cutm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->cutmn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->EntryNodeOfLoop((*reinterpret_cast< LinkList(*)>(_a[1]))); break;
        case 8: _t->EntryNodeOfToop((*reinterpret_cast< LinkList(*)>(_a[1]))); break;
        case 9: _t->reBuild((*reinterpret_cast< LinkList(*)>(_a[1])),(*reinterpret_cast< LinkList(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 10: _t->on_lift_clicked(); break;
        case 11: { LNode* _r = _t->IsIntersect((*reinterpret_cast< LinkList(*)>(_a[1])),(*reinterpret_cast< LinkList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< LNode**>(_a[0]) = std::move(_r); }  break;
        case 12: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
