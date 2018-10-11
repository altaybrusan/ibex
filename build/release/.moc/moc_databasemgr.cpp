/****************************************************************************
** Meta object code from reading C++ file 'databasemgr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../core/Utils/databasemgr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databasemgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataBaseMgr_t {
    QByteArrayData data[11];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataBaseMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataBaseMgr_t qt_meta_stringdata_DataBaseMgr = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DataBaseMgr"
QT_MOC_LITERAL(1, 12, 23), // "NotifyConnectionSuccess"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 22), // "NotifyConnectionFailed"
QT_MOC_LITERAL(4, 60, 25), // "NotifyFetchingDataStarted"
QT_MOC_LITERAL(5, 86, 26), // "NotifyFetchingDataFinished"
QT_MOC_LITERAL(6, 113, 20), // "NotifyDataFetchError"
QT_MOC_LITERAL(7, 134, 7), // "message"
QT_MOC_LITERAL(8, 142, 29), // "NotifyWritingToDatabaseFailed"
QT_MOC_LITERAL(9, 172, 32), // "NotifyDeletingFromDatabaseFailed"
QT_MOC_LITERAL(10, 205, 22) // "onDataFetchingFinished"

    },
    "DataBaseMgr\0NotifyConnectionSuccess\0"
    "\0NotifyConnectionFailed\0"
    "NotifyFetchingDataStarted\0"
    "NotifyFetchingDataFinished\0"
    "NotifyDataFetchError\0message\0"
    "NotifyWritingToDatabaseFailed\0"
    "NotifyDeletingFromDatabaseFailed\0"
    "onDataFetchingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataBaseMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    1,   58,    2, 0x06 /* Public */,
       8,    1,   61,    2, 0x06 /* Public */,
       9,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void DataBaseMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataBaseMgr *_t = static_cast<DataBaseMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NotifyConnectionSuccess(); break;
        case 1: _t->NotifyConnectionFailed(); break;
        case 2: _t->NotifyFetchingDataStarted(); break;
        case 3: _t->NotifyFetchingDataFinished(); break;
        case 4: _t->NotifyDataFetchError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->NotifyWritingToDatabaseFailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->NotifyDeletingFromDatabaseFailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->onDataFetchingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DataBaseMgr::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBaseMgr::NotifyConnectionSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DataBaseMgr::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBaseMgr::NotifyConnectionFailed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DataBaseMgr::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBaseMgr::NotifyFetchingDataStarted)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DataBaseMgr::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBaseMgr::NotifyFetchingDataFinished)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (DataBaseMgr::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBaseMgr::NotifyDataFetchError)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (DataBaseMgr::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBaseMgr::NotifyWritingToDatabaseFailed)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (DataBaseMgr::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataBaseMgr::NotifyDeletingFromDatabaseFailed)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject DataBaseMgr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataBaseMgr.data,
      qt_meta_data_DataBaseMgr,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataBaseMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataBaseMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataBaseMgr.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataBaseMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DataBaseMgr::NotifyConnectionSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DataBaseMgr::NotifyConnectionFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DataBaseMgr::NotifyFetchingDataStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DataBaseMgr::NotifyFetchingDataFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void DataBaseMgr::NotifyDataFetchError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DataBaseMgr::NotifyWritingToDatabaseFailed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DataBaseMgr::NotifyDeletingFromDatabaseFailed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
