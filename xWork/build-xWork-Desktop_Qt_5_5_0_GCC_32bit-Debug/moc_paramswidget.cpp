/****************************************************************************
** Meta object code from reading C++ file 'paramswidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../xWork/paramswidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paramswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParamsWidget_t {
    QByteArrayData data[14];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParamsWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParamsWidget_t qt_meta_stringdata_ParamsWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ParamsWidget"
QT_MOC_LITERAL(1, 13, 21), // "SetDrawTypeFlagSignal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 17), // "SetPenColorSignal"
QT_MOC_LITERAL(4, 54, 16), // "SetBgColorSignal"
QT_MOC_LITERAL(5, 71, 16), // "SetPenSizeSignal"
QT_MOC_LITERAL(6, 88, 16), // "SetPenTypeSignal"
QT_MOC_LITERAL(7, 105, 17), // "CurrentIndexSlots"
QT_MOC_LITERAL(8, 123, 5), // "index"
QT_MOC_LITERAL(9, 129, 24), // "CurrentIndexPenTypeSlots"
QT_MOC_LITERAL(10, 154, 21), // "PenWidthCurindexSlots"
QT_MOC_LITERAL(11, 176, 21), // "PenColorCurIndexSlots"
QT_MOC_LITERAL(12, 198, 20), // "BackgroundColorSlots"
QT_MOC_LITERAL(13, 219, 20) // "DefaultParamBtnSLots"

    },
    "ParamsWidget\0SetDrawTypeFlagSignal\0\0"
    "SetPenColorSignal\0SetBgColorSignal\0"
    "SetPenSizeSignal\0SetPenTypeSignal\0"
    "CurrentIndexSlots\0index\0"
    "CurrentIndexPenTypeSlots\0PenWidthCurindexSlots\0"
    "PenColorCurIndexSlots\0BackgroundColorSlots\0"
    "DefaultParamBtnSLots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParamsWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    1,   72,    2, 0x06 /* Public */,
       4,    1,   75,    2, 0x06 /* Public */,
       5,    1,   78,    2, 0x06 /* Public */,
       6,    1,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   84,    2, 0x0a /* Public */,
       9,    1,   87,    2, 0x0a /* Public */,
      10,    1,   90,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ParamsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParamsWidget *_t = static_cast<ParamsWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetDrawTypeFlagSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SetPenColorSignal((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->SetBgColorSignal((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->SetPenSizeSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->SetPenTypeSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->CurrentIndexSlots((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->CurrentIndexPenTypeSlots((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->PenWidthCurindexSlots((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->PenColorCurIndexSlots(); break;
        case 9: _t->BackgroundColorSlots(); break;
        case 10: _t->DefaultParamBtnSLots(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ParamsWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParamsWidget::SetDrawTypeFlagSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (ParamsWidget::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParamsWidget::SetPenColorSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (ParamsWidget::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParamsWidget::SetBgColorSignal)) {
                *result = 2;
            }
        }
        {
            typedef void (ParamsWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParamsWidget::SetPenSizeSignal)) {
                *result = 3;
            }
        }
        {
            typedef void (ParamsWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParamsWidget::SetPenTypeSignal)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject ParamsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ParamsWidget.data,
      qt_meta_data_ParamsWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ParamsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParamsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ParamsWidget.stringdata0))
        return static_cast<void*>(const_cast< ParamsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ParamsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ParamsWidget::SetDrawTypeFlagSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ParamsWidget::SetPenColorSignal(QColor _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ParamsWidget::SetBgColorSignal(QColor _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ParamsWidget::SetPenSizeSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ParamsWidget::SetPenTypeSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
