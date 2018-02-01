/****************************************************************************
** Meta object code from reading C++ file 'binaryfileappender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../plugins/log4qt/binaryfileappender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'binaryfileappender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Log4Qt__BinaryFileAppender_t {
    QByteArrayData data[10];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Log4Qt__BinaryFileAppender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Log4Qt__BinaryFileAppender_t qt_meta_stringdata_Log4Qt__BinaryFileAppender = {
    {
QT_MOC_LITERAL(0, 0, 26), // "Log4Qt::BinaryFileAppender"
QT_MOC_LITERAL(1, 27, 10), // "appendFile"
QT_MOC_LITERAL(2, 38, 10), // "bufferedIo"
QT_MOC_LITERAL(3, 49, 4), // "file"
QT_MOC_LITERAL(4, 54, 9), // "byteOrder"
QT_MOC_LITERAL(5, 64, 22), // "QDataStream::ByteOrder"
QT_MOC_LITERAL(6, 87, 22), // "floatingPointPrecision"
QT_MOC_LITERAL(7, 110, 35), // "QDataStream::FloatingPointPre..."
QT_MOC_LITERAL(8, 146, 13), // "streamVersion"
QT_MOC_LITERAL(9, 160, 20) // "QDataStream::Version"

    },
    "Log4Qt::BinaryFileAppender\0appendFile\0"
    "bufferedIo\0file\0byteOrder\0"
    "QDataStream::ByteOrder\0floatingPointPrecision\0"
    "QDataStream::FloatingPointPrecision\0"
    "streamVersion\0QDataStream::Version"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Log4Qt__BinaryFileAppender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       6,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Bool, 0x00095103,
       2, QMetaType::Bool, 0x00095103,
       3, QMetaType::QString, 0x00095103,
       4, 0x80000000 | 5, 0x0009510b,
       6, 0x80000000 | 7, 0x0009510b,
       8, 0x80000000 | 9, 0x0009510b,

       0        // eod
};

void Log4Qt::BinaryFileAppender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        BinaryFileAppender *_t = static_cast<BinaryFileAppender *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->appendFile(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->bufferedIo(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->file(); break;
        case 3: *reinterpret_cast< QDataStream::ByteOrder*>(_v) = _t->byteOrder(); break;
        case 4: *reinterpret_cast< QDataStream::FloatingPointPrecision*>(_v) = _t->floatingPointPrecision(); break;
        case 5: *reinterpret_cast< QDataStream::Version*>(_v) = _t->streamVersion(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        BinaryFileAppender *_t = static_cast<BinaryFileAppender *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAppendFile(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setBufferedIo(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setFile(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setByteOrder(*reinterpret_cast< QDataStream::ByteOrder*>(_v)); break;
        case 4: _t->setFloatingPointPrecision(*reinterpret_cast< QDataStream::FloatingPointPrecision*>(_v)); break;
        case 5: _t->setStreamVersion(*reinterpret_cast< QDataStream::Version*>(_v)); break;
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

const QMetaObject Log4Qt::BinaryFileAppender::staticMetaObject = {
    { &BinaryWriterAppender::staticMetaObject, qt_meta_stringdata_Log4Qt__BinaryFileAppender.data,
      qt_meta_data_Log4Qt__BinaryFileAppender,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Log4Qt::BinaryFileAppender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Log4Qt::BinaryFileAppender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Log4Qt__BinaryFileAppender.stringdata0))
        return static_cast<void*>(this);
    return BinaryWriterAppender::qt_metacast(_clname);
}

int Log4Qt::BinaryFileAppender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BinaryWriterAppender::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
