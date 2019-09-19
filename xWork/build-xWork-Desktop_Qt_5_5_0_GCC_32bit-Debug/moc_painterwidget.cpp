/****************************************************************************
** Meta object code from reading C++ file 'painterwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../xWork/painterwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'painterwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PainterWidget_t {
    QByteArrayData data[18];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PainterWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PainterWidget_t qt_meta_stringdata_PainterWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PainterWidget"
QT_MOC_LITERAL(1, 14, 12), // "NewFileSlots"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "SavePixmapSlots"
QT_MOC_LITERAL(4, 44, 17), // "SaveAsPixmapSlots"
QT_MOC_LITERAL(5, 62, 10), // "CloseSlots"
QT_MOC_LITERAL(6, 73, 15), // "OpenPixmapSlots"
QT_MOC_LITERAL(7, 89, 17), // "SetPaintFlagSlots"
QT_MOC_LITERAL(8, 107, 20), // "SetDrawTypeFlagSLots"
QT_MOC_LITERAL(9, 128, 16), // "SetPenColorSlots"
QT_MOC_LITERAL(10, 145, 15), // "SetPenSizeSlots"
QT_MOC_LITERAL(11, 161, 15), // "SetBgColorSlots"
QT_MOC_LITERAL(12, 177, 15), // "SetPenTypeSlots"
QT_MOC_LITERAL(13, 193, 8), // "AddTexts"
QT_MOC_LITERAL(14, 202, 11), // "TurnUpSlots"
QT_MOC_LITERAL(15, 214, 13), // "TurnDownSlots"
QT_MOC_LITERAL(16, 228, 16), // "TurnDefaultSlots"
QT_MOC_LITERAL(17, 245, 12) // "ForwardSlots"

    },
    "PainterWidget\0NewFileSlots\0\0SavePixmapSlots\0"
    "SaveAsPixmapSlots\0CloseSlots\0"
    "OpenPixmapSlots\0SetPaintFlagSlots\0"
    "SetDrawTypeFlagSLots\0SetPenColorSlots\0"
    "SetPenSizeSlots\0SetBgColorSlots\0"
    "SetPenTypeSlots\0AddTexts\0TurnUpSlots\0"
    "TurnDownSlots\0TurnDefaultSlots\0"
    "ForwardSlots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PainterWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x0a /* Public */,
       5,    0,   97,    2, 0x0a /* Public */,
       6,    0,   98,    2, 0x0a /* Public */,
       7,    1,   99,    2, 0x0a /* Public */,
       8,    1,  102,    2, 0x0a /* Public */,
       9,    1,  105,    2, 0x0a /* Public */,
      10,    1,  108,    2, 0x0a /* Public */,
      11,    1,  111,    2, 0x0a /* Public */,
      12,    1,  114,    2, 0x0a /* Public */,
      13,    0,  117,    2, 0x0a /* Public */,
      14,    0,  118,    2, 0x0a /* Public */,
      15,    0,  119,    2, 0x0a /* Public */,
      16,    0,  120,    2, 0x0a /* Public */,
      17,    0,  121,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PainterWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PainterWidget *_t = static_cast<PainterWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewFileSlots(); break;
        case 1: _t->SavePixmapSlots(); break;
        case 2: _t->SaveAsPixmapSlots(); break;
        case 3: _t->CloseSlots(); break;
        case 4: _t->OpenPixmapSlots(); break;
        case 5: _t->SetPaintFlagSlots((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->SetDrawTypeFlagSLots((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->SetPenColorSlots((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 8: _t->SetPenSizeSlots((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->SetBgColorSlots((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 10: _t->SetPenTypeSlots((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->AddTexts(); break;
        case 12: _t->TurnUpSlots(); break;
        case 13: _t->TurnDownSlots(); break;
        case 14: _t->TurnDefaultSlots(); break;
        case 15: _t->ForwardSlots(); break;
        default: ;
        }
    }
}

const QMetaObject PainterWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PainterWidget.data,
      qt_meta_data_PainterWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PainterWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PainterWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PainterWidget.stringdata0))
        return static_cast<void*>(const_cast< PainterWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PainterWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
