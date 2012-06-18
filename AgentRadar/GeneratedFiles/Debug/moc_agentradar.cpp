/****************************************************************************
** Meta object code from reading C++ file 'agentradar.h'
**
** Created: Mon Jun 18 12:17:54 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../agentradar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'agentradar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AgentRadar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      30,   11,   11,   11, 0x0a,
      50,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AgentRadar[] = {
    "AgentRadar\0\0CreateNewSector()\0"
    "SetWedgesBool(bool)\0GetGLWidget(MyGLWidget*)\0"
};

void AgentRadar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AgentRadar *_t = static_cast<AgentRadar *>(_o);
        switch (_id) {
        case 0: _t->CreateNewSector(); break;
        case 1: _t->SetWedgesBool((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->GetGLWidget((*reinterpret_cast< MyGLWidget*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AgentRadar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AgentRadar::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AgentRadar,
      qt_meta_data_AgentRadar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AgentRadar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AgentRadar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AgentRadar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AgentRadar))
        return static_cast<void*>(const_cast< AgentRadar*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AgentRadar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
