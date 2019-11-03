/****************************************************************************
** Meta object code from reading C++ file 'dailyrollingfileappender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../temp/ibex-master/log4qt/dailyrollingfileappender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dailyrollingfileappender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Log4Qt__DailyRollingFileAppender_t {
    QByteArrayData data[9];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Log4Qt__DailyRollingFileAppender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Log4Qt__DailyRollingFileAppender_t qt_meta_stringdata_Log4Qt__DailyRollingFileAppender = {
    {
QT_MOC_LITERAL(0, 0, 32), // "Log4Qt::DailyRollingFileAppender"
QT_MOC_LITERAL(1, 33, 11), // "datePattern"
QT_MOC_LITERAL(2, 45, 11), // "DatePattern"
QT_MOC_LITERAL(3, 57, 17), // "MINUTELY_ROLLOVER"
QT_MOC_LITERAL(4, 75, 15), // "HOURLY_ROLLOVER"
QT_MOC_LITERAL(5, 91, 18), // "HALFDAILY_ROLLOVER"
QT_MOC_LITERAL(6, 110, 14), // "DAILY_ROLLOVER"
QT_MOC_LITERAL(7, 125, 15), // "WEEKLY_ROLLOVER"
QT_MOC_LITERAL(8, 141, 16) // "MONTHLY_ROLLOVER"

    },
    "Log4Qt::DailyRollingFileAppender\0"
    "datePattern\0DatePattern\0MINUTELY_ROLLOVER\0"
    "HOURLY_ROLLOVER\0HALFDAILY_ROLLOVER\0"
    "DAILY_ROLLOVER\0WEEKLY_ROLLOVER\0"
    "MONTHLY_ROLLOVER"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Log4Qt__DailyRollingFileAppender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       1,   17, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,

 // enums: name, flags, count, data
       2, 0x0,    6,   21,

 // enum data: key, value
       3, uint(Log4Qt::DailyRollingFileAppender::MINUTELY_ROLLOVER),
       4, uint(Log4Qt::DailyRollingFileAppender::HOURLY_ROLLOVER),
       5, uint(Log4Qt::DailyRollingFileAppender::HALFDAILY_ROLLOVER),
       6, uint(Log4Qt::DailyRollingFileAppender::DAILY_ROLLOVER),
       7, uint(Log4Qt::DailyRollingFileAppender::WEEKLY_ROLLOVER),
       8, uint(Log4Qt::DailyRollingFileAppender::MONTHLY_ROLLOVER),

       0        // eod
};

void Log4Qt::DailyRollingFileAppender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        DailyRollingFileAppender *_t = static_cast<DailyRollingFileAppender *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->datePattern(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        DailyRollingFileAppender *_t = static_cast<DailyRollingFileAppender *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDatePattern(*reinterpret_cast< QString*>(_v)); break;
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

const QMetaObject Log4Qt::DailyRollingFileAppender::staticMetaObject = {
    { &FileAppender::staticMetaObject, qt_meta_stringdata_Log4Qt__DailyRollingFileAppender.data,
      qt_meta_data_Log4Qt__DailyRollingFileAppender,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Log4Qt::DailyRollingFileAppender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Log4Qt::DailyRollingFileAppender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Log4Qt__DailyRollingFileAppender.stringdata0))
        return static_cast<void*>(this);
    return FileAppender::qt_metacast(_clname);
}

int Log4Qt::DailyRollingFileAppender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = FileAppender::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
