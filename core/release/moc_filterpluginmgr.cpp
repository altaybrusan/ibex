/****************************************************************************
** Meta object code from reading C++ file 'filterpluginmgr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../temp/ibex-master/core/Controller/filterpluginmgr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filterpluginmgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterPluginMgr_t {
    QByteArrayData data[6];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterPluginMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterPluginMgr_t qt_meta_stringdata_FilterPluginMgr = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FilterPluginMgr"
QT_MOC_LITERAL(1, 16, 28), // "OnActivateFilterPluginDialog"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 18), // "OnItemCheckChanged"
QT_MOC_LITERAL(4, 65, 3), // "row"
QT_MOC_LITERAL(5, 69, 5) // "check"

    },
    "FilterPluginMgr\0OnActivateFilterPluginDialog\0"
    "\0OnItemCheckChanged\0row\0check"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterPluginMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    2,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    4,    5,

       0        // eod
};

void FilterPluginMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FilterPluginMgr *_t = static_cast<FilterPluginMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnActivateFilterPluginDialog(); break;
        case 1: _t->OnItemCheckChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject FilterPluginMgr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FilterPluginMgr.data,
      qt_meta_data_FilterPluginMgr,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FilterPluginMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterPluginMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterPluginMgr.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FilterPluginMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
