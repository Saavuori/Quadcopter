/****************************************************************************
** Meta object code from reading C++ file 'serial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PC/serial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SerialHandler_t {
    QByteArrayData data[16];
    char stringdata[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialHandler_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialHandler_t qt_meta_stringdata_SerialHandler = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 6),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 6),
QT_MOC_LITERAL(4, 29, 6),
QT_MOC_LITERAL(5, 36, 6),
QT_MOC_LITERAL(6, 43, 7),
QT_MOC_LITERAL(7, 51, 4),
QT_MOC_LITERAL(8, 56, 8),
QT_MOC_LITERAL(9, 65, 3),
QT_MOC_LITERAL(10, 69, 4),
QT_MOC_LITERAL(11, 74, 11),
QT_MOC_LITERAL(12, 86, 8),
QT_MOC_LITERAL(13, 95, 8),
QT_MOC_LITERAL(14, 104, 9),
QT_MOC_LITERAL(15, 114, 14)
    },
    "SerialHandler\0motor1\0\0motor2\0motor3\0"
    "motor4\0console\0text\0altitude\0alt\0send\0"
    "const char*\0openPort\0portname\0baundrate\0"
    "serialReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,
       4,    1,   70,    2, 0x06 /* Public */,
       5,    1,   73,    2, 0x06 /* Public */,
       6,    1,   76,    2, 0x06 /* Public */,
       8,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   82,    2, 0x0a /* Public */,
      10,    1,   85,    2, 0x0a /* Public */,
      12,    2,   88,    2, 0x0a /* Public */,
      15,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Double,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void, 0x80000000 | 11,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   13,   14,
    QMetaType::Void,

       0        // eod
};

void SerialHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialHandler *_t = static_cast<SerialHandler *>(_o);
        switch (_id) {
        case 0: _t->motor1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->motor2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->motor3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->motor4((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->console((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->altitude((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->send((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->send((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 8: _t->openPort((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< qint32(*)>(_a[2]))); break;
        case 9: _t->serialReceived(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SerialHandler::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialHandler::motor1)) {
                *result = 0;
            }
        }
        {
            typedef void (SerialHandler::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialHandler::motor2)) {
                *result = 1;
            }
        }
        {
            typedef void (SerialHandler::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialHandler::motor3)) {
                *result = 2;
            }
        }
        {
            typedef void (SerialHandler::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialHandler::motor4)) {
                *result = 3;
            }
        }
        {
            typedef void (SerialHandler::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialHandler::console)) {
                *result = 4;
            }
        }
        {
            typedef void (SerialHandler::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialHandler::altitude)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject SerialHandler::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SerialHandler.data,
      qt_meta_data_SerialHandler,  qt_static_metacall, 0, 0}
};


const QMetaObject *SerialHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SerialHandler.stringdata))
        return static_cast<void*>(const_cast< SerialHandler*>(this));
    return QThread::qt_metacast(_clname);
}

int SerialHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void SerialHandler::motor1(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialHandler::motor2(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialHandler::motor3(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SerialHandler::motor4(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SerialHandler::console(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SerialHandler::altitude(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
