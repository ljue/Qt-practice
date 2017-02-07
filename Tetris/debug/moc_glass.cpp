/****************************************************************************
** Meta object code from reading C++ file 'glass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../glass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GLASS_t {
    QByteArrayData data[14];
    char stringdata[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GLASS_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GLASS_t qt_meta_stringdata_GLASS = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 15),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 11),
QT_MOC_LITERAL(4, 35, 7),
QT_MOC_LITERAL(5, 43, 4),
QT_MOC_LITERAL(6, 48, 8),
QT_MOC_LITERAL(7, 57, 13),
QT_MOC_LITERAL(8, 71, 11),
QT_MOC_LITERAL(9, 83, 11),
QT_MOC_LITERAL(10, 95, 7),
QT_MOC_LITERAL(11, 103, 4),
QT_MOC_LITERAL(12, 108, 10),
QT_MOC_LITERAL(13, 119, 7)
    },
    "GLASS\0signalGlassInit\0\0drawPattern\0"
    "Figure*\0next\0setScore\0slotGlassInit\0"
    "slotNewGame\0helpMessage\0setRows\0rows\0"
    "setColumns\0columns"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GLASS[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       2,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       6,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   61,    2, 0x0a /* Public */,
       8,    0,   62,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,
      10,    1,   64,    2, 0x0a /* Public */,
      12,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   11,
    QMetaType::Void, QMetaType::UInt,   13,

 // properties: name, type, flags
      11, QMetaType::UInt, 0x00095103,
      13, QMetaType::UInt, 0x00095103,

       0        // eod
};

void GLASS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GLASS *_t = static_cast<GLASS *>(_o);
        switch (_id) {
        case 0: _t->signalGlassInit(); break;
        case 1: _t->drawPattern((*reinterpret_cast< Figure*(*)>(_a[1]))); break;
        case 2: _t->setScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slotGlassInit(); break;
        case 4: _t->slotNewGame(); break;
        case 5: _t->helpMessage(); break;
        case 6: _t->setRows((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 7: _t->setColumns((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GLASS::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLASS::signalGlassInit)) {
                *result = 0;
            }
        }
        {
            typedef void (GLASS::*_t)(Figure * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLASS::drawPattern)) {
                *result = 1;
            }
        }
        {
            typedef void (GLASS::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLASS::setScore)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject GLASS::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GLASS.data,
      qt_meta_data_GLASS,  qt_static_metacall, 0, 0}
};


const QMetaObject *GLASS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GLASS::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLASS.stringdata))
        return static_cast<void*>(const_cast< GLASS*>(this));
    return QWidget::qt_metacast(_clname);
}

int GLASS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint*>(_v) = rows(); break;
        case 1: *reinterpret_cast< uint*>(_v) = columns(); break;
        default: break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setRows(*reinterpret_cast< uint*>(_v)); break;
        case 1: setColumns(*reinterpret_cast< uint*>(_v)); break;
        default: break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void GLASS::signalGlassInit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GLASS::drawPattern(Figure * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GLASS::setScore(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
