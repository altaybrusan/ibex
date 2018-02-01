/****************************************************************************
** Meta object code from reading C++ file 'telnetappender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../plugins/log4qt/telnetappender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'telnetappender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Log4Qt__TelnetAppender_t {
    QByteArrayData data[8];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Log4Qt__TelnetAppender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Log4Qt__TelnetAppender_t qt_meta_stringdata_Log4Qt__TelnetAppender = {
    {
QT_MOC_LITERAL(0, 0, 22), // "Log4Qt::TelnetAppender"
QT_MOC_LITERAL(1, 23, 15), // "onNewConnection"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 20), // "onClientDisconnected"
QT_MOC_LITERAL(4, 61, 4), // "port"
QT_MOC_LITERAL(5, 66, 14), // "immediateFlush"
QT_MOC_LITERAL(6, 81, 7), // "address"
QT_MOC_LITERAL(7, 89, 12) // "QHostAddress"

    },
    "Log4Qt::TelnetAppender\0onNewConnection\0"
    "\0onClientDisconnected\0port\0immediateFlush\0"
    "address\0QHostAddress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Log4Qt__TelnetAppender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       3,   26, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::Int, 0x00095103,
       5, QMetaType::Bool, 0x00095103,
       6, 0x80000000 | 7, 0x0009510b,

       0        // eod
};

void Log4Qt::TelnetAppender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TelnetAppender *_t = static_cast<TelnetAppender *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNewConnection(); break;
        case 1: _t->onClientDisconnected(); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        TelnetAppender *_t = static_cast<TelnetAppender *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->port(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->immediateFlush(); break;
        case 2: *reinterpret_cast< QHostAddress*>(_v) = _t->address(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        TelnetAppender *_t = static_cast<TelnetAppender *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPort(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setImmediateFlush(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setAddress(*reinterpret_cast< QHostAddress*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject Log4Qt::TelnetAppender::staticMetaObject = {
    { &AppenderSkeleton::staticMetaObject, qt_meta_stringdata_Log4Qt__TelnetAppender.data,
      qt_meta_data_Log4Qt__TelnetAppender,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Log4Qt::TelnetAppender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Log4Qt::TelnetAppender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Log4Qt__TelnetAppender.stringdata0))
        return static_cast<void*>(this);
    return AppenderSkeleton::qt_metacast(_clname);
}

int Log4Qt::TelnetAppender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AppenderSkeleton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
