/****************************************************************************
** Meta object code from reading C++ file 'zamekapp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ZamekApp/zamekapp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zamekapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ZamekApp_t {
    QByteArrayData data[13];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZamekApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZamekApp_t qt_meta_stringdata_ZamekApp = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ZamekApp"
QT_MOC_LITERAL(1, 9, 11), // "handleError"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(4, 51, 5), // "error"
QT_MOC_LITERAL(5, 57, 30), // "on_serialRefreshButton_clicked"
QT_MOC_LITERAL(6, 88, 37), // "on_serialComboBox_currentInde..."
QT_MOC_LITERAL(7, 126, 23), // "on_backupButton_clicked"
QT_MOC_LITERAL(8, 150, 24), // "on_restoreButton_clicked"
QT_MOC_LITERAL(9, 175, 28), // "on_lockRefreshButton_clicked"
QT_MOC_LITERAL(10, 204, 34), // "on_entryNumberSpinBox_valueCh..."
QT_MOC_LITERAL(11, 239, 21), // "on_loadButton_clicked"
QT_MOC_LITERAL(12, 261, 21) // "on_saveButton_clicked"

    },
    "ZamekApp\0handleError\0\0"
    "QSerialPort::SerialPortError\0error\0"
    "on_serialRefreshButton_clicked\0"
    "on_serialComboBox_currentIndexChanged\0"
    "on_backupButton_clicked\0"
    "on_restoreButton_clicked\0"
    "on_lockRefreshButton_clicked\0"
    "on_entryNumberSpinBox_valueChanged\0"
    "on_loadButton_clicked\0on_saveButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZamekApp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    0,   68,    2, 0x08 /* Private */,
      12,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
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

void ZamekApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZamekApp *_t = static_cast<ZamekApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 1: _t->on_serialRefreshButton_clicked(); break;
        case 2: _t->on_serialComboBox_currentIndexChanged(); break;
        case 3: _t->on_backupButton_clicked(); break;
        case 4: _t->on_restoreButton_clicked(); break;
        case 5: _t->on_lockRefreshButton_clicked(); break;
        case 6: _t->on_entryNumberSpinBox_valueChanged(); break;
        case 7: _t->on_loadButton_clicked(); break;
        case 8: _t->on_saveButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ZamekApp::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ZamekApp.data,
      qt_meta_data_ZamekApp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ZamekApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZamekApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZamekApp.stringdata0))
        return static_cast<void*>(const_cast< ZamekApp*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ZamekApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
