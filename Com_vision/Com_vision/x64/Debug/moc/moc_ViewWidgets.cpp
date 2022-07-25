/****************************************************************************
** Meta object code from reading C++ file 'ViewWidgets.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ViewWidgets.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ViewWidgets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ViewWidgets_t {
    QByteArrayData data[7];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ViewWidgets_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ViewWidgets_t qt_meta_stringdata_ViewWidgets = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ViewWidgets"
QT_MOC_LITERAL(1, 12, 28), // "sendGrayAndCoordinate_SIGNAL"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 6), // "HTuple"
QT_MOC_LITERAL(4, 49, 4), // "gray"
QT_MOC_LITERAL(5, 54, 3), // "row"
QT_MOC_LITERAL(6, 58, 3) // "col"

    },
    "ViewWidgets\0sendGrayAndCoordinate_SIGNAL\0"
    "\0HTuple\0gray\0row\0col"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewWidgets[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    6,

       0        // eod
};

void ViewWidgets::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewWidgets *_t = static_cast<ViewWidgets *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendGrayAndCoordinate_SIGNAL((*reinterpret_cast< HTuple(*)>(_a[1])),(*reinterpret_cast< HTuple(*)>(_a[2])),(*reinterpret_cast< HTuple(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ViewWidgets::*_t)(HTuple , HTuple , HTuple );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ViewWidgets::sendGrayAndCoordinate_SIGNAL)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ViewWidgets::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ViewWidgets.data,
      qt_meta_data_ViewWidgets,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ViewWidgets::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewWidgets::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ViewWidgets.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ViewWidgets::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ViewWidgets::sendGrayAndCoordinate_SIGNAL(HTuple _t1, HTuple _t2, HTuple _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
