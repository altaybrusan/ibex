/****************************************************************************
** Meta object code from reading C++ file 'rs232connector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rs232connector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rs232connector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RS232Connector_t {
    QByteArrayData data[8];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RS232Connector_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RS232Connector_t qt_meta_stringdata_RS232Connector = {
    {
QT_MOC_LITERAL(0, 0, 14), // "RS232Connector"
QT_MOC_LITERAL(1, 15, 13), // "NotifyMessage"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "message"
QT_MOC_LITERAL(4, 38, 21), // "NotifyConnectionError"
QT_MOC_LITERAL(5, 60, 5), // "error"
QT_MOC_LITERAL(6, 66, 22), // "NotifyConnectionOpened"
QT_MOC_LITERAL(7, 89, 22) // "NotifyConnectionClosed"

    },
    "RS232Connector\0NotifyMessage\0\0message\0"
    "NotifyConnectionError\0error\0"
    "NotifyConnectionOpened\0NotifyConnectionClosed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RS232Connector[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       6,    0,   40,    2, 0x06 /* Public */,
       7,    0,   41,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RS232Connector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RS232Connector *_t = static_cast<RS232Connector *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NotifyMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->NotifyConnectionError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->NotifyConnectionOpened(); break;
        case 3: _t->NotifyConnectionClosed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RS232Connector::*_t)(const QString ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RS232Connector::NotifyMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RS232Connector::*_t)(const QString ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RS232Connector::NotifyConnectionError)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RS232Connector::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RS232Connector::NotifyConnectionOpened)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RS232Connector::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RS232Connector::NotifyConnectionClosed)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject RS232Connector::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RS232Connector.data,
      qt_meta_data_RS232Connector,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RS232Connector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RS232Connector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RS232Connector.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IConnector"))
        return static_cast< IConnector*>(this);
    if (!strcmp(_clname, "tr.edu.boun.IConnector"))
        return static_cast< IConnector*>(this);
    return QObject::qt_metacast(_clname);
}

int RS232Connector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void RS232Connector::NotifyMessage(const QString _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< RS232Connector *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RS232Connector::NotifyConnectionError(const QString _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< RS232Connector *>(this), &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RS232Connector::NotifyConnectionOpened()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void RS232Connector::NotifyConnectionClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
