/****************************************************************************
** Meta object code from reading C++ file 'levelrangefilter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../plugins/log4qt/varia/levelrangefilter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'levelrangefilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Log4Qt__LevelRangeFilter_t {
    QByteArrayData data[5];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Log4Qt__LevelRangeFilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Log4Qt__LevelRangeFilter_t qt_meta_stringdata_Log4Qt__LevelRangeFilter = {
    {
QT_MOC_LITERAL(0, 0, 24), // "Log4Qt::LevelRangeFilter"
QT_MOC_LITERAL(1, 25, 13), // "acceptOnMatch"
QT_MOC_LITERAL(2, 39, 8), // "levelMax"
QT_MOC_LITERAL(3, 48, 13), // "Log4Qt::Level"
QT_MOC_LITERAL(4, 62, 8) // "levelMin"

    },
    "Log4Qt::LevelRangeFilter\0acceptOnMatch\0"
    "levelMax\0Log4Qt::Level\0levelMin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Log4Qt__LevelRangeFilter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       3,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Bool, 0x00095103,
       2, 0x80000000 | 3, 0x0009510b,
       4, 0x80000000 | 3, 0x0009510b,

       0        // eod
};

void Log4Qt::LevelRangeFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Log4Qt::Level >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        LevelRangeFilter *_t = static_cast<LevelRangeFilter *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->acceptOnMatch(); break;
        case 1: *reinterpret_cast< Log4Qt::Level*>(_v) = _t->levelMax(); break;
        case 2: *reinterpret_cast< Log4Qt::Level*>(_v) = _t->levelMin(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        LevelRangeFilter *_t = static_cast<LevelRangeFilter *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAcceptOnMatch(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setLevelMax(*reinterpret_cast< Log4Qt::Level*>(_v)); break;
        case 2: _t->setLevelMin(*reinterpret_cast< Log4Qt::Level*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
}

const QMetaObject Log4Qt::LevelRangeFilter::staticMetaObject = {
    { &Filter::staticMetaObject, qt_meta_stringdata_Log4Qt__LevelRangeFilter.data,
      qt_meta_data_Log4Qt__LevelRangeFilter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Log4Qt::LevelRangeFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Log4Qt::LevelRangeFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Log4Qt__LevelRangeFilter.stringdata0))
        return static_cast<void*>(this);
    return Filter::qt_metacast(_clname);
}

int Log4Qt::LevelRangeFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Filter::qt_metacall(_c, _id, _a);
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
