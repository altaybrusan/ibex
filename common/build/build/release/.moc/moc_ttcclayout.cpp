/****************************************************************************
** Meta object code from reading C++ file 'ttcclayout.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../plugins/log4qt/ttcclayout.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ttcclayout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Log4Qt__TTCCLayout_t {
    QByteArrayData data[11];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Log4Qt__TTCCLayout_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Log4Qt__TTCCLayout_t qt_meta_stringdata_Log4Qt__TTCCLayout = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Log4Qt::TTCCLayout"
QT_MOC_LITERAL(1, 19, 17), // "categoryPrefixing"
QT_MOC_LITERAL(2, 37, 15), // "contextPrinting"
QT_MOC_LITERAL(3, 53, 10), // "dateFormat"
QT_MOC_LITERAL(4, 64, 14), // "threadPrinting"
QT_MOC_LITERAL(5, 79, 10), // "DateFormat"
QT_MOC_LITERAL(6, 90, 4), // "NONE"
QT_MOC_LITERAL(7, 95, 7), // "ISO8601"
QT_MOC_LITERAL(8, 103, 8), // "ABSOLUTE"
QT_MOC_LITERAL(9, 112, 4), // "DATE"
QT_MOC_LITERAL(10, 117, 8) // "RELATIVE"

    },
    "Log4Qt::TTCCLayout\0categoryPrefixing\0"
    "contextPrinting\0dateFormat\0threadPrinting\0"
    "DateFormat\0NONE\0ISO8601\0ABSOLUTE\0DATE\0"
    "RELATIVE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Log4Qt__TTCCLayout[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       4,   14, // properties
       1,   26, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Bool, 0x00095103,
       2, QMetaType::Bool, 0x00095103,
       3, QMetaType::QString, 0x00095103,
       4, QMetaType::Bool, 0x00095103,

 // enums: name, flags, count, data
       5, 0x0,    5,   30,

 // enum data: key, value
       6, uint(Log4Qt::TTCCLayout::NONE),
       7, uint(Log4Qt::TTCCLayout::ISO8601),
       8, uint(Log4Qt::TTCCLayout::ABSOLUTE),
       9, uint(Log4Qt::TTCCLayout::DATE),
      10, uint(Log4Qt::TTCCLayout::RELATIVE),

       0        // eod
};

void Log4Qt::TTCCLayout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        TTCCLayout *_t = static_cast<TTCCLayout *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->categoryPrefixing(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->contextPrinting(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->dateFormat(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->threadPrinting(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        TTCCLayout *_t = static_cast<TTCCLayout *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCategoryPrefixing(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setContextPrinting(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setDateFormat(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setThreadPrinting(*reinterpret_cast< bool*>(_v)); break;
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

const QMetaObject Log4Qt::TTCCLayout::staticMetaObject = {
    { &Layout::staticMetaObject, qt_meta_stringdata_Log4Qt__TTCCLayout.data,
      qt_meta_data_Log4Qt__TTCCLayout,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Log4Qt::TTCCLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Log4Qt::TTCCLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Log4Qt__TTCCLayout.stringdata0))
        return static_cast<void*>(this);
    return Layout::qt_metacast(_clname);
}

int Log4Qt::TTCCLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
