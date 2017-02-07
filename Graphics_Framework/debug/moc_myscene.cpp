/****************************************************************************
** Meta object code from reading C++ file 'myscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../myscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyScene_t {
    QByteArrayData data[18];
    char stringdata[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyScene_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyScene_t qt_meta_stringdata_MyScene = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 14),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 12),
QT_MOC_LITERAL(4, 37, 13),
QT_MOC_LITERAL(5, 51, 11),
QT_MOC_LITERAL(6, 63, 14),
QT_MOC_LITERAL(7, 78, 13),
QT_MOC_LITERAL(8, 92, 4),
QT_MOC_LITERAL(9, 97, 16),
QT_MOC_LITERAL(10, 114, 1),
QT_MOC_LITERAL(11, 116, 1),
QT_MOC_LITERAL(12, 118, 1),
QT_MOC_LITERAL(13, 120, 1),
QT_MOC_LITERAL(14, 122, 12),
QT_MOC_LITERAL(15, 135, 5),
QT_MOC_LITERAL(16, 141, 5),
QT_MOC_LITERAL(17, 147, 5)
    },
    "MyScene\0signalNewShape\0\0Qt::PenStyle\0"
    "rectangledraw\0changecolor\0slotUserDialog\0"
    "slotActivated\0rect\0slotShapeChanged\0"
    "r\0c\0w\0s\0slotAddShape\0color\0width\0style"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   58,    2, 0x0a /* Public */,
       5,    0,   59,    2, 0x0a /* Public */,
       6,    0,   60,    2, 0x0a /* Public */,
       7,    1,   61,    2, 0x0a /* Public */,
       9,    4,   64,    2, 0x0a /* Public */,
      14,    4,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QRectF, QMetaType::QColor, QMetaType::UInt, 0x80000000 | 3,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRectF,    8,
    QMetaType::Void, QMetaType::QRectF, QMetaType::QColor, QMetaType::UInt, 0x80000000 | 3,   10,   11,   12,   13,
    QMetaType::Void, QMetaType::QRectF, QMetaType::QColor, QMetaType::UInt, 0x80000000 | 3,    8,   15,   16,   17,

       0        // eod
};

void MyScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyScene *_t = static_cast<MyScene *>(_o);
        switch (_id) {
        case 0: _t->signalNewShape((*reinterpret_cast< QRectF(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< Qt::PenStyle(*)>(_a[4]))); break;
        case 1: _t->rectangledraw(); break;
        case 2: _t->changecolor(); break;
        case 3: _t->slotUserDialog(); break;
        case 4: _t->slotActivated((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 5: _t->slotShapeChanged((*reinterpret_cast< QRectF(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< Qt::PenStyle(*)>(_a[4]))); break;
        case 6: _t->slotAddShape((*reinterpret_cast< QRectF(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< Qt::PenStyle(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyScene::*_t)(QRectF , QColor , uint , Qt::PenStyle );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyScene::signalNewShape)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MyScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_MyScene.data,
      qt_meta_data_MyScene,  qt_static_metacall, 0, 0}
};


const QMetaObject *MyScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyScene.stringdata))
        return static_cast<void*>(const_cast< MyScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int MyScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MyScene::signalNewShape(QRectF _t1, QColor _t2, uint _t3, Qt::PenStyle _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
