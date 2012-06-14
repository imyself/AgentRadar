/****************************************************************************
** Meta object code from reading C++ file 'myglwidget.h'
**
** Created: Thu Jun 14 19:19:18 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myglwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myglwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyGLWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   11,   11,   11, 0x0a,
      64,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
     106,   11,   11,   11, 0x0a,
     129,   11,   11,   11, 0x0a,
     149,   11,   11,   11, 0x0a,
     172,   11,   11,   11, 0x0a,
     196,   11,   11,   11, 0x0a,
     217,   11,   11,   11, 0x0a,
     238,   11,   11,   11, 0x0a,
     258,   11,   11,   11, 0x0a,
     280,   11,   11,   11, 0x0a,
     303,   11,   11,   11, 0x0a,
     320,   11,   11,   11, 0x0a,
     344,   11,   11,   11, 0x0a,
     365,   11,   11,   11, 0x0a,
     387,   11,   11,   11, 0x0a,
     408,   11,   11,   11, 0x0a,
     422,   11,   11,   11, 0x0a,
     437,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyGLWidget[] = {
    "MyGLWidget\0\0SendSnappingPoint(QListWidgetItem*)\0"
    "SetTypeWedges()\0SetTypeRectangles()\0"
    "SetNumberSectors(int)\0MergeSelectedSectors()\0"
    "DisplayAgents(bool)\0DisplayObstacles(bool)\0"
    "DisplayInspection(bool)\0DisplayNetFlow(bool)\0"
    "DisplayDensity(bool)\0SetCardinality(int)\0"
    "WedgeSelectLeft(bool)\0WedgeSelectRight(bool)\0"
    "WedgeClockwise()\0WedgeCounterClockwise()\0"
    "WedgeSetDegrees(int)\0WedgeSelectNear(bool)\0"
    "WedgeSelectFar(bool)\0WedgeCloser()\0"
    "WedgeFarther()\0WedgeSetDistance(double)\0"
};

void MyGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyGLWidget *_t = static_cast<MyGLWidget *>(_o);
        switch (_id) {
        case 0: _t->SendSnappingPoint((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->SetTypeWedges(); break;
        case 2: _t->SetTypeRectangles(); break;
        case 3: _t->SetNumberSectors((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->MergeSelectedSectors(); break;
        case 5: _t->DisplayAgents((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->DisplayObstacles((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->DisplayInspection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->DisplayNetFlow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->DisplayDensity((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->SetCardinality((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->WedgeSelectLeft((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->WedgeSelectRight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->WedgeClockwise(); break;
        case 14: _t->WedgeCounterClockwise(); break;
        case 15: _t->WedgeSetDegrees((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->WedgeSelectNear((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->WedgeSelectFar((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->WedgeCloser(); break;
        case 19: _t->WedgeFarther(); break;
        case 20: _t->WedgeSetDistance((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyGLWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyGLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_MyGLWidget,
      qt_meta_data_MyGLWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyGLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyGLWidget))
        return static_cast<void*>(const_cast< MyGLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int MyGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void MyGLWidget::SendSnappingPoint(QListWidgetItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
