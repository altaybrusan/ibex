/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../core/View/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[449];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "NotifyMainWindowIsLoaded"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 33), // "NotifyNewStudyWorkFlowIsTrigg..."
QT_MOC_LITERAL(4, 71, 35), // "NotifyQuickStudyWorkFlowIsTri..."
QT_MOC_LITERAL(5, 107, 34), // "NotifyUpdatePACSSettingIsTrig..."
QT_MOC_LITERAL(6, 142, 26), // "NotifyLoadStudyIsTriggered"
QT_MOC_LITERAL(7, 169, 39), // "NotifyUpdateWorklistSettingsI..."
QT_MOC_LITERAL(8, 209, 34), // "NotifyOpenStudyWorkFlowIsTrig..."
QT_MOC_LITERAL(9, 244, 26), // "on_actionNewStudytriggered"
QT_MOC_LITERAL(10, 271, 28), // "on_actionQuickStarttriggered"
QT_MOC_LITERAL(11, 300, 27), // "on_actionLoadStudytriggered"
QT_MOC_LITERAL(12, 328, 27), // "on_actionOpenStudytriggered"
QT_MOC_LITERAL(13, 356, 47), // "on_action_Update_PACS_Server_..."
QT_MOC_LITERAL(14, 404, 44) // "on_action_Update_Worklist_Set..."

    },
    "MainWindow\0NotifyMainWindowIsLoaded\0"
    "\0NotifyNewStudyWorkFlowIsTriggered\0"
    "NotifyQuickStudyWorkFlowIsTriggered\0"
    "NotifyUpdatePACSSettingIsTriggered\0"
    "NotifyLoadStudyIsTriggered\0"
    "NotifyUpdateWorklistSettingsIsTriggered\0"
    "NotifyOpenStudyWorkFlowIsTriggered\0"
    "on_actionNewStudytriggered\0"
    "on_actionQuickStarttriggered\0"
    "on_actionLoadStudytriggered\0"
    "on_actionOpenStudytriggered\0"
    "on_action_Update_PACS_Server_Settings_triggered\0"
    "on_action_Update_Worklist_Settings_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,
       7,    0,   84,    2, 0x06 /* Public */,
       8,    0,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NotifyMainWindowIsLoaded(); break;
        case 1: _t->NotifyNewStudyWorkFlowIsTriggered(); break;
        case 2: _t->NotifyQuickStudyWorkFlowIsTriggered(); break;
        case 3: _t->NotifyUpdatePACSSettingIsTriggered(); break;
        case 4: _t->NotifyLoadStudyIsTriggered(); break;
        case 5: _t->NotifyUpdateWorklistSettingsIsTriggered(); break;
        case 6: _t->NotifyOpenStudyWorkFlowIsTriggered(); break;
        case 7: _t->on_actionNewStudytriggered(); break;
        case 8: _t->on_actionQuickStarttriggered(); break;
        case 9: _t->on_actionLoadStudytriggered(); break;
        case 10: _t->on_actionOpenStudytriggered(); break;
        case 11: _t->on_action_Update_PACS_Server_Settings_triggered(); break;
        case 12: _t->on_action_Update_Worklist_Settings_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::NotifyMainWindowIsLoaded)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::NotifyNewStudyWorkFlowIsTriggered)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::NotifyQuickStudyWorkFlowIsTriggered)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::NotifyUpdatePACSSettingIsTriggered)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::NotifyLoadStudyIsTriggered)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::NotifyUpdateWorklistSettingsIsTriggered)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::NotifyOpenStudyWorkFlowIsTriggered)) {
                *result = 6;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::NotifyMainWindowIsLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::NotifyNewStudyWorkFlowIsTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::NotifyQuickStudyWorkFlowIsTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::NotifyUpdatePACSSettingIsTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::NotifyLoadStudyIsTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::NotifyUpdateWorklistSettingsIsTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MainWindow::NotifyOpenStudyWorkFlowIsTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
