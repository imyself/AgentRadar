/****************************************************************************
** Meta object code from reading C++ file 'myglwidget.h'
**
** Created: Thu Jun 14 22:35:35 2012
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
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      48,   11,   11,   11, 0x05,
      69,   11,   11,   11, 0x05,
      96,   11,   11,   11, 0x05,
     124,   11,   11,   11, 0x05,
     152,   11,   11,   11, 0x05,
     180,   11,   11,   11, 0x05,
     202,   11,   11,   11, 0x05,
     228,   11,   11,   11, 0x05,
     255,   11,   11,   11, 0x05,
     279,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     303,   11,   11,   11, 0x0a,
     319,   11,   11,   11, 0x0a,
     339,   11,   11,   11, 0x0a,
     361,   11,   11,   11, 0x0a,
     384,   11,   11,   11, 0x0a,
     404,   11,   11,   11, 0x0a,
     427,   11,   11,   11, 0x0a,
     451,   11,   11,   11, 0x0a,
     472,   11,   11,   11, 0x0a,
     493,   11,   11,   11, 0x0a,
     513,   11,   11,   11, 0x0a,
     535,   11,   11,   11, 0x0a,
     558,   11,   11,   11, 0x0a,
     575,   11,   11,   11, 0x0a,
     599,   11,   11,   11, 0x0a,
     620,   11,   11,   11, 0x0a,
     642,   11,   11,   11, 0x0a,
     663,   11,   11,   11, 0x0a,
     677,   11,   11,   11, 0x0a,
     692,   11,   11,   11, 0x0a,
     717,   11,   11,   11, 0x0a,
     749,   11,   11,   11, 0x0a,
     758,   11,   11,   11, 0x0a,
     770,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyGLWidget[] = {
    "MyGLWidget\0\0SendSnappingPoint(QListWidgetItem*)\0"
    "ClearSnappingPoint()\0SendWedgeLeftBound(double)\0"
    "SendWedgeRightBound(double)\0"
    "SendWedgeUpperBound(double)\0"
    "SendWedgeLowerBound(double)\0"
    "SendAgentStatus(bool)\0SendObstaclesStatus(bool)\0"
    "SendInspectionStatus(bool)\0"
    "SendNetFlowStatus(bool)\0SendDensityStatus(bool)\0"
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
    "SetCurrentArc(QListWidgetItem*)\0"
    "AddArc()\0RemoveArc()\0CallUpdateGL()\0"
};

void MyGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyGLWidget *_t = static_cast<MyGLWidget *>(_o);
        switch (_id) {
        case 0: _t->SendSnappingPoint((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->ClearSnappingPoint(); break;
        case 2: _t->SendWedgeLeftBound((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->SendWedgeRightBound((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->SendWedgeUpperBound((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->SendWedgeLowerBound((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->SendAgentStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->SendObstaclesStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->SendInspectionStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->SendNetFlowStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->SendDensityStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->SetTypeWedges(); break;
        case 12: _t->SetTypeRectangles(); break;
        case 13: _t->SetNumberSectors((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->MergeSelectedSectors(); break;
        case 15: _t->DisplayAgents((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->DisplayObstacles((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->DisplayInspection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->DisplayNetFlow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->DisplayDensity((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->SetCardinality((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->WedgeSelectLeft((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->WedgeSelectRight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->WedgeClockwise(); break;
        case 24: _t->WedgeCounterClockwise(); break;
        case 25: _t->WedgeSetDegrees((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->WedgeSelectNear((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->WedgeSelectFar((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->WedgeCloser(); break;
        case 29: _t->WedgeFarther(); break;
        case 30: _t->WedgeSetDistance((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->SetCurrentArc((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 32: _t->AddArc(); break;
        case 33: _t->RemoveArc(); break;
        case 34: _t->CallUpdateGL(); break;
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
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void MyGLWidget::SendSnappingPoint(QListWidgetItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGLWidget::ClearSnappingPoint()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MyGLWidget::SendWedgeLeftBound(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGLWidget::SendWedgeRightBound(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyGLWidget::SendWedgeUpperBound(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyGLWidget::SendWedgeLowerBound(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyGLWidget::SendAgentStatus(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyGLWidget::SendObstaclesStatus(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MyGLWidget::SendInspectionStatus(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MyGLWidget::SendNetFlowStatus(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MyGLWidget::SendDensityStatus(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_END_MOC_NAMESPACE
