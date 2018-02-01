/****************************************************************************
** Meta object code from reading C++ file 'rollingbinaryfileappender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../plugins/log4qt/rollingbinaryfileappender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rollingbinaryfileappender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Log4Qt__RollingBinaryFileAppender_t {
    QByteArrayData data[11];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Log4Qt__RollingBinaryFileAppender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Log4Qt__RollingBinaryFileAppender_t qt_meta_stringdata_Log4Qt__RollingBinaryFileAppender = {
    {
QT_MOC_LITERAL(0, 0, 33), // "Log4Qt::RollingBinaryFileAppe..."
QT_MOC_LITERAL(1, 34, 14), // "maxBackupIndex"
QT_MOC_LITERAL(2, 49, 15), // "maximumFileSize"
QT_MOC_LITERAL(3, 65, 11), // "datePattern"
QT_MOC_LITERAL(4, 77, 11), // "DatePattern"
QT_MOC_LITERAL(5, 89, 17), // "MINUTELY_ROLLOVER"
QT_MOC_LITERAL(6, 107, 15), // "HOURLY_ROLLOVER"
QT_MOC_LITERAL(7, 123, 18), // "HALFDAILY_ROLLOVER"
QT_MOC_LITERAL(8, 142, 14), // "DAILY_ROLLOVER"
QT_MOC_LITERAL(9, 157, 15), // "WEEKLY_ROLLOVER"
QT_MOC_LITERAL(10, 173, 16) // "MONTHLY_ROLLOVER"

    },
    "Log4Qt::RollingBinaryFileAppender\0"
    "maxBackupIndex\0maximumFileSize\0"
    "datePattern\0DatePattern\0MINUTELY_ROLLOVER\0"
    "HOURLY_ROLLOVER\0HALFDAILY_ROLLOVER\0"
    "DAILY_ROLLOVER\0WEEKLY_ROLLOVER\0"
    "MONTHLY_ROLLOVER"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Log4Qt__RollingBinaryFileAppender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       3,   14, // properties
       1,   23, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095103,
       2, QMetaType::LongLong, 0x00095103,
       3, QMetaType::QString, 0x00095103,

 // enums: name, flags, count, data
       4, 0x0,    6,   27,

 // enum data: key, value
       5, uint(Log4Qt::RollingBinaryFileAppender::MINUTELY_ROLLOVER),
       6, uint(Log4Qt::RollingBinaryFileAppender::HOURLY_ROLLOVER),
       7, uint(Log4Qt::RollingBinaryFileAppender::HALFDAILY_ROLLOVER),
       8, uint(Log4Qt::RollingBinaryFileAppender::DAILY_ROLLOVER),
       9, uint(Log4Qt::RollingBinaryFileAppender::WEEKLY_ROLLOVER),
      10, uint(Log4Qt::RollingBinaryFileAppender::MONTHLY_ROLLOVER),

       0        // eod
};

void Log4Qt::RollingBinaryFileAppender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        RollingBinaryFileAppender *_t = static_cast<RollingBinaryFileAppender *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->maxBackupIndex(); break;
        case 1: *reinterpret_cast< qint64*>(_v) = _t->maximumFileSize(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->datePattern(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        RollingBinaryFileAppender *_t = static_cast<RollingBinaryFileAppender *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMaxBackupIndex(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setMaximumFileSize(*reinterpret_cast< qint64*>(_v)); break;
        case 2: _t->setDatePattern(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Log4Qt::RollingBinaryFileAppender::staticMetaObject = {
    { &BinaryFileAppender::staticMetaObject, qt_meta_stringdata_Log4Qt__RollingBinaryFileAppender.data,
      qt_meta_data_Log4Qt__RollingBinaryFileAppender,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Log4Qt::RollingBinaryFileAppender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Log4Qt::RollingBinaryFileAppender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Log4Qt__RollingBinaryFileAppender.stringdata0))
        return static_cast<void*>(this);
    return BinaryFileAppender::qt_metacast(_clname);
}

int Log4Qt::RollingBinaryFileAppender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BinaryFileAppender::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
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
