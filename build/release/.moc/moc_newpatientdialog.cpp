/****************************************************************************
** Meta object code from reading C++ file 'newpatientdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../launch/newpatientdialog.h"
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
    QByteArrayData data[18];
    char stringdata0[465];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewPatientDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewPatientDialog_t qt_meta_stringdata_NewPatientDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "NewPatientDialog"
QT_MOC_LITERAL(1, 17, 23), // "OnBodyPartStatusChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 14), // "iBEX::BodyPart"
QT_MOC_LITERAL(4, 57, 8), // "bodyPart"
QT_MOC_LITERAL(5, 66, 10), // "isSelected"
QT_MOC_LITERAL(6, 77, 13), // "ActivateOkBtn"
QT_MOC_LITERAL(7, 91, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(8, 113, 35), // "on_lastNameLineEdit_editingFi..."
QT_MOC_LITERAL(9, 149, 36), // "on_firstNameLineEdit_editingF..."
QT_MOC_LITERAL(10, 186, 37), // "on_middleNameLineEdit_editing..."
QT_MOC_LITERAL(11, 224, 36), // "on_patientIdLineEdit_editingF..."
QT_MOC_LITERAL(12, 261, 27), // "on_dateEdit_editingFinished"
QT_MOC_LITERAL(13, 289, 37), // "on_genderComboBox_currentInde..."
QT_MOC_LITERAL(14, 327, 5), // "index"
QT_MOC_LITERAL(15, 333, 45), // "on_referringPhysicianLineEdit..."
QT_MOC_LITERAL(16, 379, 42), // "on_admissionNumberLineEdit_ed..."
QT_MOC_LITERAL(17, 422, 42) // "on_accessionNumberLineEdit_ed..."

    },
    "NewPatientDialog\0OnBodyPartStatusChanged\0"
    "\0iBEX::BodyPart\0bodyPart\0isSelected\0"
    "ActivateOkBtn\0on_buttonBox_accepted\0"
    "on_lastNameLineEdit_editingFinished\0"
    "on_firstNameLineEdit_editingFinished\0"
    "on_middleNameLineEdit_editingFinished\0"
    "on_patientIdLineEdit_editingFinished\0"
    "on_dateEdit_editingFinished\0"
    "on_genderComboBox_currentIndexChanged\0"
    "index\0on_referringPhysicianLineEdit_editingFinished\0"
    "on_admissionNumberLineEdit_editingFinished\0"
    "on_accessionNumberLineEdit_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewPatientDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    1,   86,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,
      16,    0,   90,    2, 0x08 /* Private */,
      17,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
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
        case 0: _t->OnBodyPartStatusChanged((*reinterpret_cast< iBEX::BodyPart(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->ActivateOkBtn(); break;
        case 2: _t->on_buttonBox_accepted(); break;
        case 3: _t->on_lastNameLineEdit_editingFinished(); break;
        case 4: _t->on_firstNameLineEdit_editingFinished(); break;
        case 5: _t->on_middleNameLineEdit_editingFinished(); break;
        case 6: _t->on_patientIdLineEdit_editingFinished(); break;
        case 7: _t->on_dateEdit_editingFinished(); break;
        case 8: _t->on_genderComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_referringPhysicianLineEdit_editingFinished(); break;
        case 10: _t->on_admissionNumberLineEdit_editingFinished(); break;
        case 11: _t->on_accessionNumberLineEdit_editingFinished(); break;
        default: ;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
