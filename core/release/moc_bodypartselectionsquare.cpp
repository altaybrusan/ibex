/****************************************************************************
** Meta object code from reading C++ file 'bodypartselectionsquare.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../temp/ibex-master/core/View/bodypartselectionsquare.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bodypartselectionsquare.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BodyPartSelectionSquare_t {
    QByteArrayData data[6];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BodyPartSelectionSquare_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BodyPartSelectionSquare_t qt_meta_stringdata_BodyPartSelectionSquare = {
    {
QT_MOC_LITERAL(0, 0, 23), // "BodyPartSelectionSquare"
QT_MOC_LITERAL(1, 24, 30), // "NotifyBodyPartSelectionChanged"
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 15), // "iBEX::BODY_PART"
QT_MOC_LITERAL(4, 72, 8), // "bodypart"
QT_MOC_LITERAL(5, 81, 10) // "isSelected"

    },
    "BodyPartSelectionSquare\0"
    "NotifyBodyPartSelectionChanged\0\0"
    "iBEX::BODY_PART\0bodypart\0isSelected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BodyPartSelectionSquare[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,

       0        // eod
};

void BodyPartSelectionSquare::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BodyPartSelectionSquare *_t = static_cast<BodyPartSelectionSquare *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NotifyBodyPartSelectionChanged((*reinterpret_cast< iBEX::BODY_PART(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BodyPartSelectionSquare::*_t)(iBEX::BODY_PART , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BodyPartSelectionSquare::NotifyBodyPartSelectionChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject BodyPartSelectionSquare::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BodyPartSelectionSquare.data,
      qt_meta_data_BodyPartSelectionSquare,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BodyPartSelectionSquare::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BodyPartSelectionSquare::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BodyPartSelectionSquare.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return QObject::qt_metacast(_clname);
}

int BodyPartSelectionSquare::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void BodyPartSelectionSquare::NotifyBodyPartSelectionChanged(iBEX::BODY_PART _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE