/****************************************************************************
** Meta object code from reading C++ file 'bandpassfilter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../plugins/BandPassFilter/bandpassfilter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bandpassfilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BandPassFilter_t {
    QByteArrayData data[10];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BandPassFilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BandPassFilter_t qt_meta_stringdata_BandPassFilter = {
    {
QT_MOC_LITERAL(0, 0, 14), // "BandPassFilter"
QT_MOC_LITERAL(1, 15, 22), // "NotifyAlgorithmStarted"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 14), // "NotifyProgress"
QT_MOC_LITERAL(4, 54, 7), // "percent"
QT_MOC_LITERAL(5, 62, 11), // "NotifyError"
QT_MOC_LITERAL(6, 74, 7), // "message"
QT_MOC_LITERAL(7, 82, 23), // "NotifyAlgorithmFinished"
QT_MOC_LITERAL(8, 106, 18), // "OnParameterUpdated"
QT_MOC_LITERAL(9, 125, 22) // "OnHighFrequencyPressed"

    },
    "BandPassFilter\0NotifyAlgorithmStarted\0"
    "\0NotifyProgress\0percent\0NotifyError\0"
    "message\0NotifyAlgorithmFinished\0"
    "OnParameterUpdated\0OnHighFrequencyPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BandPassFilter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    1,   48,    2, 0x06 /* Public */,
       7,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   52,    2, 0x0a /* Public */,
       9,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BandPassFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BandPassFilter *_t = static_cast<BandPassFilter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NotifyAlgorithmStarted(); break;
        case 1: _t->NotifyProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->NotifyError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->NotifyAlgorithmFinished(); break;
        case 4: _t->OnParameterUpdated(); break;
        case 5: _t->OnHighFrequencyPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BandPassFilter::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BandPassFilter::NotifyAlgorithmStarted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BandPassFilter::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BandPassFilter::NotifyProgress)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BandPassFilter::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BandPassFilter::NotifyError)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (BandPassFilter::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BandPassFilter::NotifyAlgorithmFinished)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject BandPassFilter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BandPassFilter.data,
      qt_meta_data_BandPassFilter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BandPassFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BandPassFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BandPassFilter.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IAlgorithm"))
        return static_cast< IAlgorithm*>(this);
    if (!strcmp(_clname, "tr.edu.boun.IAlgorithm"))
        return static_cast< IAlgorithm*>(this);
    return QObject::qt_metacast(_clname);
}

int BandPassFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void BandPassFilter::NotifyAlgorithmStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BandPassFilter::NotifyProgress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BandPassFilter::NotifyError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BandPassFilter::NotifyAlgorithmFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

QT_PLUGIN_METADATA_SECTION const uint qt_section_alignment_dummy = 42;

#ifdef QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0x9c, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x88, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    0x16, 0x00, 't',  'r',  '.',  'e',  'd',  'u', 
    '.',  'b',  'o',  'u',  'n',  '.',  'I',  'A', 
    'l',  'g',  'o',  'r',  'i',  't',  'h',  'm', 
    0x1b, 0x08, 0x00, 0x00, 0x09, 0x00, 'c',  'l', 
    'a',  's',  's',  'N',  'a',  'm',  'e',  0x00,
    0x0e, 0x00, 'B',  'a',  'n',  'd',  'P',  'a', 
    's',  's',  'F',  'i',  'l',  't',  'e',  'r', 
    0x9a, ' ',  0xa1, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x11, 0x00, 0x00, 0x00, 0x05, 0x00, 'd',  'e', 
    'b',  'u',  'g',  0x00, 0x95, 0x0f, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 'l',  0x00, 0x00, 0x00,
    '0',  0x00, 0x00, 0x00, '`',  0x00, 0x00, 0x00,
    'P',  0x00, 0x00, 0x00
};

#else // QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0x9c, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x88, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    0x16, 0x00, 't',  'r',  '.',  'e',  'd',  'u', 
    '.',  'b',  'o',  'u',  'n',  '.',  'I',  'A', 
    'l',  'g',  'o',  'r',  'i',  't',  'h',  'm', 
    0x15, 0x08, 0x00, 0x00, 0x08, 0x00, 'M',  'e', 
    't',  'a',  'D',  'a',  't',  'a',  0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x9b, 0x0b, 0x00, 0x00,
    0x09, 0x00, 'c',  'l',  'a',  's',  's',  'N', 
    'a',  'm',  'e',  0x00, 0x0e, 0x00, 'B',  'a', 
    'n',  'd',  'P',  'a',  's',  's',  'F',  'i', 
    'l',  't',  'e',  'r',  '1',  0x00, 0x00, 0x00,
    0x05, 0x00, 'd',  'e',  'b',  'u',  'g',  0x00,
    0x9a, ' ',  0xa1, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, '0',  0x00, 0x00, 0x00,
    'L',  0x00, 0x00, 0x00, 'l',  0x00, 0x00, 0x00,
    'x',  0x00, 0x00, 0x00
};
#endif // QT_NO_DEBUG

QT_MOC_EXPORT_PLUGIN(BandPassFilter, BandPassFilter)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
