/****************************************************************************
** Meta object code from reading C++ file 'configuratorhelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../plugins/log4qt/helpers/configuratorhelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configuratorhelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Log4Qt__ConfiguratorHelper_t {
    QByteArrayData data[10];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Log4Qt__ConfiguratorHelper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Log4Qt__ConfiguratorHelper_t qt_meta_stringdata_Log4Qt__ConfiguratorHelper = {
    {
QT_MOC_LITERAL(0, 0, 26), // "Log4Qt::ConfiguratorHelper"
QT_MOC_LITERAL(1, 27, 24), // "configurationFileChanged"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 9), // "rFileName"
QT_MOC_LITERAL(4, 63, 5), // "error"
QT_MOC_LITERAL(5, 69, 26), // "doConfigurationFileChanged"
QT_MOC_LITERAL(6, 96, 8), // "fileName"
QT_MOC_LITERAL(7, 105, 35), // "doConfigurationFileDirectoryC..."
QT_MOC_LITERAL(8, 141, 4), // "path"
QT_MOC_LITERAL(9, 146, 27) // "tryToReAddConfigurationFile"

    },
    "Log4Qt::ConfiguratorHelper\0"
    "configurationFileChanged\0\0rFileName\0"
    "error\0doConfigurationFileChanged\0"
    "fileName\0doConfigurationFileDirectoryChanged\0"
    "path\0tryToReAddConfigurationFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Log4Qt__ConfiguratorHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   39,    2, 0x08 /* Private */,
       7,    1,   42,    2, 0x08 /* Private */,
       9,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void Log4Qt::ConfiguratorHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfiguratorHelper *_t = static_cast<ConfiguratorHelper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->configurationFileChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->doConfigurationFileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->doConfigurationFileDirectoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->tryToReAddConfigurationFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ConfiguratorHelper::*_t)(const QString & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfiguratorHelper::configurationFileChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Log4Qt::ConfiguratorHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Log4Qt__ConfiguratorHelper.data,
      qt_meta_data_Log4Qt__ConfiguratorHelper,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Log4Qt::ConfiguratorHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Log4Qt::ConfiguratorHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Log4Qt__ConfiguratorHelper.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Log4Qt::ConfiguratorHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Log4Qt::ConfiguratorHelper::configurationFileChanged(const QString & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
