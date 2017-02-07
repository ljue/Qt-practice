/****************************************************************************
** Meta object code from reading C++ file 'mymodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mymodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mymodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyModel_t {
    QByteArrayData data[21];
    char stringdata[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyModel_t qt_meta_stringdata_MyModel = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 15),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 4),
QT_MOC_LITERAL(4, 30, 18),
QT_MOC_LITERAL(5, 49, 12),
QT_MOC_LITERAL(6, 62, 11),
QT_MOC_LITERAL(7, 74, 14),
QT_MOC_LITERAL(8, 89, 12),
QT_MOC_LITERAL(9, 102, 13),
QT_MOC_LITERAL(10, 116, 9),
QT_MOC_LITERAL(11, 126, 8),
QT_MOC_LITERAL(12, 135, 8),
QT_MOC_LITERAL(13, 144, 20),
QT_MOC_LITERAL(14, 165, 15),
QT_MOC_LITERAL(15, 181, 9),
QT_MOC_LITERAL(16, 191, 8),
QT_MOC_LITERAL(17, 200, 14),
QT_MOC_LITERAL(18, 215, 14),
QT_MOC_LITERAL(19, 230, 18),
QT_MOC_LITERAL(20, 249, 12)
    },
    "MyModel\0signalActivated\0\0rect\0"
    "signalShapeChanged\0Qt::PenStyle\0"
    "signalClear\0signalAddShape\0slotNewShape\0"
    "slotActivated\0slotClear\0slotSave\0"
    "slotOpen\0slotCreateConnection\0"
    "slotCreateTable\0slotWrite\0slotRead\0"
    "slotQueryModel\0slotTableModel\0"
    "slotBdTableChanged\0index_tmodel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    4,   97,    2, 0x06 /* Public */,
       6,    0,  106,    2, 0x06 /* Public */,
       7,    4,  107,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    4,  116,    2, 0x0a /* Public */,
       9,    1,  125,    2, 0x0a /* Public */,
      10,    0,  128,    2, 0x0a /* Public */,
      11,    0,  129,    2, 0x0a /* Public */,
      12,    0,  130,    2, 0x0a /* Public */,
      13,    0,  131,    2, 0x0a /* Public */,
      14,    0,  132,    2, 0x0a /* Public */,
      15,    0,  133,    2, 0x0a /* Public */,
      16,    0,  134,    2, 0x0a /* Public */,
      17,    0,  135,    2, 0x0a /* Public */,
      18,    0,  136,    2, 0x0a /* Public */,
      19,    1,  137,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QRectF,    3,
    QMetaType::Void, QMetaType::QRectF, QMetaType::QColor, QMetaType::UInt, 0x80000000 | 5,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRectF, QMetaType::QColor, QMetaType::UInt, 0x80000000 | 5,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QRectF, QMetaType::QColor, QMetaType::UInt, 0x80000000 | 5,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   20,

       0        // eod
};

void MyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyModel *_t = static_cast<MyModel *>(_o);
        switch (_id) {
        case 0: _t->signalActivated((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 1: _t->signalShapeChanged((*reinterpret_cast< QRectF(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< Qt::PenStyle(*)>(_a[4]))); break;
        case 2: _t->signalClear(); break;
        case 3: _t->signalAddShape((*reinterpret_cast< QRectF(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< Qt::PenStyle(*)>(_a[4]))); break;
        case 4: _t->slotNewShape((*reinterpret_cast< QRectF(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< Qt::PenStyle(*)>(_a[4]))); break;
        case 5: _t->slotActivated((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: _t->slotClear(); break;
        case 7: _t->slotSave(); break;
        case 8: _t->slotOpen(); break;
        case 9: _t->slotCreateConnection(); break;
        case 10: _t->slotCreateTable(); break;
        case 11: _t->slotWrite(); break;
        case 12: _t->slotRead(); break;
        case 13: _t->slotQueryModel(); break;
        case 14: _t->slotTableModel(); break;
        case 15: _t->slotBdTableChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyModel::*_t)(QRectF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyModel::signalActivated)) {
                *result = 0;
            }
        }
        {
            typedef void (MyModel::*_t)(QRectF , QColor , uint , Qt::PenStyle );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyModel::signalShapeChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (MyModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyModel::signalClear)) {
                *result = 2;
            }
        }
        {
            typedef void (MyModel::*_t)(QRectF , QColor , uint , Qt::PenStyle );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyModel::signalAddShape)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject MyModel::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_MyModel.data,
      qt_meta_data_MyModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *MyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyModel.stringdata))
        return static_cast<void*>(const_cast< MyModel*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int MyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MyModel::signalActivated(QRectF _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyModel::signalShapeChanged(QRectF _t1, QColor _t2, uint _t3, Qt::PenStyle _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyModel::signalClear()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MyModel::signalAddShape(QRectF _t1, QColor _t2, uint _t3, Qt::PenStyle _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
