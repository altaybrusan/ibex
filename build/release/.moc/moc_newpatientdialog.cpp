/****************************************************************************
** Meta object code from reading C++ file 'newpatientdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../core/View/newpatientdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newpatientdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NewPatientDialog_t {
    QByteArrayData data[20];
    char stringdata0[515];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewPatientDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewPatientDialog_t qt_meta_stringdata_NewPatientDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "NewPatientDialog"
QT_MOC_LITERAL(1, 17, 27), // "OnRegistrationFormCompleted"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 23), // "OnBodyPartStatusChanged"
QT_MOC_LITERAL(4, 70, 15), // "iBEX::BODY_PART"
QT_MOC_LITERAL(5, 86, 8), // "bodyPart"
QT_MOC_LITERAL(6, 95, 10), // "isSelected"
QT_MOC_LITERAL(7, 106, 12), // "RefreshOkBtn"
QT_MOC_LITERAL(8, 119, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(9, 141, 35), // "on_lastNameLineEdit_editingFi..."
QT_MOC_LITERAL(10, 177, 36), // "on_firstNameLineEdit_editingF..."
QT_MOC_LITERAL(11, 214, 37), // "on_middleNameLineEdit_editing..."
QT_MOC_LITERAL(12, 252, 36), // "on_patientIdLineEdit_editingF..."
QT_MOC_LITERAL(13, 289, 27), // "on_dateEdit_editingFinished"
QT_MOC_LITERAL(14, 317, 37), // "on_genderComboBox_currentInde..."
QT_MOC_LITERAL(15, 355, 5), // "index"
QT_MOC_LITERAL(16, 361, 45), // "on_referringPhysicianLineEdit..."
QT_MOC_LITERAL(17, 407, 42), // "on_admissionNumberLineEdit_ed..."
QT_MOC_LITERAL(18, 450, 42), // "on_accessionNumberLineEdit_ed..."
QT_MOC_LITERAL(19, 493, 21) // "on_buttonBox_rejected"

    },
    "NewPatientDialog\0OnRegistrationFormCompleted\0"
    "\0OnBodyPartStatusChanged\0iBEX::BODY_PART\0"
    "bodyPart\0isSelected\0RefreshOkBtn\0"
    "on_buttonBox_accepted\0"
    "on_lastNameLineEdit_editingFinished\0"
    "on_firstNameLineEdit_editingFinished\0"
    "on_middleNameLineEdit_editingFinished\0"
    "on_patientIdLineEdit_editingFinished\0"
    "on_dateEdit_editingFinished\0"
    "on_genderComboBox_currentIndexChanged\0"
    "index\0on_referringPhysicianLineEdit_editingFinished\0"
    "on_admissionNumberLineEdit_editingFinished\0"
    "on_accessionNumberLineEdit_editingFinished\0"
    "on_buttonBox_rejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewPatientDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   85,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    1,   97,    2, 0x08 /* Private */,
      16,    0,  100,    2, 0x08 /* Private */,
      17,    0,  101,    2, 0x08 /* Private */,
      18,    0,  102,    2, 0x08 /* Private */,
      19,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, QMetaType::Bool,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewPatientDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewPatientDialog *_t = static_cast<NewPatientDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnRegistrationFormCompleted(); break;
        case 1: _t->OnBodyPartStatusChanged((*reinterpret_cast< iBEX::BODY_PART(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->RefreshOkBtn(); break;
        case 3: _t->on_buttonBox_accepted(); break;
        case 4: _t->on_lastNameLineEdit_editingFinished(); break;
        case 5: _t->on_firstNameLineEdit_editingFinished(); break;
        case 6: _t->on_middleNameLineEdit_editingFinished(); break;
        case 7: _t->on_patientIdLineEdit_editingFinished(); break;
        case 8: _t->on_dateEdit_editingFinished(); break;
        case 9: _t->on_genderComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_referringPhysicianLineEdit_editingFinished(); break;
        case 11: _t->on_admissionNumberLineEdit_editingFinished(); break;
        case 12: _t->on_accessionNumberLineEdit_editingFinished(); break;
        case 13: _t->on_buttonBox_rejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (NewPatientDialog::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NewPatientDialog::OnRegistrationFormCompleted)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject NewPatientDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewPatientDialog.data,
      qt_meta_data_NewPatientDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *NewPatientDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewPatientDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NewPatientDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int NewPatientDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void NewPatientDialog::OnRegistrationFormCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
