/****************************************************************************
** Meta object code from reading C++ file 'SystemSettingController.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Controller/SystemSetting/SystemSettingController.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SystemSettingController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS = QtMocHelpers::stringData(
    "SystemSettingController",
    "setNewAirplaneMode",
    "",
    "handleUpdateAirplaneMode",
    "SystemSettingAdapter::AirplaneModeEnums",
    "systemSettingModelObject",
    "QSharedPointer<SystemSettingModel>"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[24];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[40];
    char stringdata5[25];
    char stringdata6[35];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS_t qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 23),  // "SystemSettingController"
        QT_MOC_LITERAL(24, 18),  // "setNewAirplaneMode"
        QT_MOC_LITERAL(43, 0),  // ""
        QT_MOC_LITERAL(44, 24),  // "handleUpdateAirplaneMode"
        QT_MOC_LITERAL(69, 39),  // "SystemSettingAdapter::Airplan..."
        QT_MOC_LITERAL(109, 24),  // "systemSettingModelObject"
        QT_MOC_LITERAL(134, 34)   // "QSharedPointer<SystemSettingM..."
    },
    "SystemSettingController",
    "setNewAirplaneMode",
    "",
    "handleUpdateAirplaneMode",
    "SystemSettingAdapter::AirplaneModeEnums",
    "systemSettingModelObject",
    "QSharedPointer<SystemSettingModel>"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSystemSettingControllerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       1,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x0a,    2 /* Public */,
       3,    1,   29,    2, 0x0a,    4 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // properties: name, type, flags
       5, 0x80000000 | 6, 0x00015409, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject SystemSettingController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSystemSettingControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS_t,
        // property 'systemSettingModelObject'
        QtPrivate::TypeAndForceComplete<QSharedPointer<SystemSettingModel>, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SystemSettingController, std::true_type>,
        // method 'setNewAirplaneMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        // method 'handleUpdateAirplaneMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const SystemSettingAdapter::AirplaneModeEnums &, std::false_type>
    >,
    nullptr
} };

void SystemSettingController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SystemSettingController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setNewAirplaneMode((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->handleUpdateAirplaneMode((*reinterpret_cast< std::add_pointer_t<SystemSettingAdapter::AirplaneModeEnums>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSharedPointer<SystemSettingModel> >(); break;
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SystemSettingController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QSharedPointer<SystemSettingModel>*>(_v) = _t->systemSettingModelObject(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *SystemSettingController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SystemSettingController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SystemSettingController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
