/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ui/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[392];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 26), // "on_AddPersonButton_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 29), // "on_DeletePersonButton_clicked"
QT_MOC_LITERAL(4, 69, 32), // "on_SavePersonTableButton_clicked"
QT_MOC_LITERAL(5, 102, 31), // "on_MainTabWidget_currentChanged"
QT_MOC_LITERAL(6, 134, 5), // "index"
QT_MOC_LITERAL(7, 140, 24), // "on_AddBookButton_clicked"
QT_MOC_LITERAL(8, 165, 27), // "on_DeleteBookButton_clicked"
QT_MOC_LITERAL(9, 193, 30), // "on_SaveBookTableButton_clicked"
QT_MOC_LITERAL(10, 224, 26), // "on_actionBeenden_triggered"
QT_MOC_LITERAL(11, 251, 22), // "on_AddCDButton_clicked"
QT_MOC_LITERAL(12, 274, 25), // "on_DeleteCDButton_clicked"
QT_MOC_LITERAL(13, 300, 28), // "on_SaveCDTableButton_clicked"
QT_MOC_LITERAL(14, 329, 32), // "on_actionDefault_Theme_triggered"
QT_MOC_LITERAL(15, 362, 29) // "on_actionDark_Theme_triggered"

    },
    "MainWindow\0on_AddPersonButton_clicked\0"
    "\0on_DeletePersonButton_clicked\0"
    "on_SavePersonTableButton_clicked\0"
    "on_MainTabWidget_currentChanged\0index\0"
    "on_AddBookButton_clicked\0"
    "on_DeleteBookButton_clicked\0"
    "on_SaveBookTableButton_clicked\0"
    "on_actionBeenden_triggered\0"
    "on_AddCDButton_clicked\0on_DeleteCDButton_clicked\0"
    "on_SaveCDTableButton_clicked\0"
    "on_actionDefault_Theme_triggered\0"
    "on_actionDark_Theme_triggered"
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
       5,    1,   82,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_AddPersonButton_clicked(); break;
        case 1: _t->on_DeletePersonButton_clicked(); break;
        case 2: _t->on_SavePersonTableButton_clicked(); break;
        case 3: _t->on_MainTabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_AddBookButton_clicked(); break;
        case 5: _t->on_DeleteBookButton_clicked(); break;
        case 6: _t->on_SaveBookTableButton_clicked(); break;
        case 7: _t->on_actionBeenden_triggered(); break;
        case 8: _t->on_AddCDButton_clicked(); break;
        case 9: _t->on_DeleteCDButton_clicked(); break;
        case 10: _t->on_SaveCDTableButton_clicked(); break;
        case 11: _t->on_actionDefault_Theme_triggered(); break;
        case 12: _t->on_actionDark_Theme_triggered(); break;
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
