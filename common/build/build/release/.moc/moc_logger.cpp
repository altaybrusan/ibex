/****************************************************************************
** Meta object code from reading C++ file 'logger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../plugins/log4qt/logger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Log4Qt__Logger_t {
    QByteArrayData data[9];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Log4Qt__Logger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Log4Qt__Logger_t qt_meta_stringdata_Log4Qt__Logger = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Log4Qt::Logger"
QT_MOC_LITERAL(1, 15, 10), // "additivity"
QT_MOC_LITERAL(2, 26, 5), // "level"
QT_MOC_LITERAL(3, 32, 13), // "Log4Qt::Level"
QT_MOC_LITERAL(4, 46, 16), // "loggerRepository"
QT_MOC_LITERAL(5, 63, 17), // "LoggerRepository*"
QT_MOC_LITERAL(6, 81, 4), // "name"
QT_MOC_LITERAL(7, 86, 12), // "parentLogger"
QT_MOC_LITERAL(8, 99, 7) // "Logger*"

    },
    "Log4Qt::Logger\0additivity\0level\0"
    "Log4Qt::Level\0loggerRepository\0"
    "LoggerRepository*\0name\0parentLogger\0"
    "Logger*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Log4Qt__Logger[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Bool, 0x00095103,
       2, 0x80000000 | 3, 0x0009510b,
       4, 0x80000000 | 5, 0x00095009,
       6, QMetaType::QString, 0x00095001,
       7, 0x80000000 | 8, 0x00095009,

       0        // eod
};

void Log4Qt::Logger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Log4Qt::Level >(); break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Logger* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Logger *_t = static_cast<Logger *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->additivity(); break;
        case 1: *reinterpret_cast< Log4Qt::Level*>(_v) = _t->level(); break;
        case 2: *reinterpret_cast< LoggerRepository**>(_v) = _t->loggerRepository(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 4: *reinterpret_cast< Logger**>(_v) = _t->parentLogger(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Logger *_t = static_cast<Logger *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAdditivity(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setLevel(*reinterpret_cast< Log4Qt::Level*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
}

const QMetaObject Log4Qt::Logger::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Log4Qt__Logger.data,
      qt_meta_data_Log4Qt__Logger,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Log4Qt::Logger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Log4Qt::Logger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Log4Qt__Logger.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "AppenderAttachable"))
        return static_cast< AppenderAttachable*>(this);
    return QObject::qt_metacast(_clname);
}

int Log4Qt::Logger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
