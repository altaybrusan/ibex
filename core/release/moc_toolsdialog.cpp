/****************************************************************************
** Meta object code from reading C++ file 'toolsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../temp/ibex-master/core/View/toolsdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ToolsDialog_t {
    QByteArrayData data[8];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToolsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToolsDialog_t qt_meta_stringdata_ToolsDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ToolsDialog"
QT_MOC_LITERAL(1, 12, 13), // "NotifyAddUser"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 16), // "NotifyRemoveUser"
QT_MOC_LITERAL(4, 44, 20), // "NotifyDialogAccepted"
QT_MOC_LITERAL(5, 65, 21), // "on_addUserBtn_clicked"
QT_MOC_LITERAL(6, 87, 24), // "on_removeUserBtn_clicked"
QT_MOC_LITERAL(7, 112, 21) // "on_buttonBox_accepted"

    },
    "ToolsDialog\0NotifyAddUser\0\0NotifyRemoveUser\0"
    "NotifyDialogAccepted\0on_addUserBtn_clicked\0"
    "on_removeUserBtn_clicked\0on_buttonBox_accepted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToolsDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ToolsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ToolsDialog *_t = static_cast<ToolsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NotifyAddUser(); break;
        case 1: _t->NotifyRemoveUser(); break;
        case 2: _t->NotifyDialogAccepted(); break;
        case 3: _t->on_addUserBtn_clicked(); break;
        case 4: _t->on_removeUserBtn_clicked(); break;
        case 5: _t->on_buttonBox_accepted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ToolsDialog::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ToolsDialog::NotifyAddUser)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ToolsDialog::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ToolsDialog::NotifyRemoveUser)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ToolsDialog::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ToolsDialog::NotifyDialogAccepted)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ToolsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ToolsDialog.data,
      qt_meta_data_ToolsDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ToolsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ToolsDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ToolsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ToolsDialog::NotifyAddUser()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ToolsDialog::NotifyRemoveUser()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ToolsDialog::NotifyDialogAccepted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
