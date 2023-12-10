/****************************************************************************
** Meta object code from reading C++ file 'SystemSettingController.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Controller/SystemSetting/SystemSettingController.h"
#include <QtCore/qmetatype.h>

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
    "isAirplaneModeActiveChanged",
    "",
    "isAirplaneModeActive",
    "setIsAirplaneModeActive",
    "newIsAirplaneModeActive",
    "handleUpdateAirplaneMode",
    "SystemSettingAdapter::AirplaneModeEnums",
    "setNewValueAirplaneMode"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[24];
    char stringdata1[28];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[24];
    char stringdata5[24];
    char stringdata6[25];
    char stringdata7[40];
    char stringdata8[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS_t qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 23),  // "SystemSettingController"
        QT_MOC_LITERAL(24, 27),  // "isAirplaneModeActiveChanged"
        QT_MOC_LITERAL(52, 0),  // ""
        QT_MOC_LITERAL(53, 20),  // "isAirplaneModeActive"
        QT_MOC_LITERAL(74, 23),  // "setIsAirplaneModeActive"
        QT_MOC_LITERAL(98, 23),  // "newIsAirplaneModeActive"
        QT_MOC_LITERAL(122, 24),  // "handleUpdateAirplaneMode"
        QT_MOC_LITERAL(147, 39),  // "SystemSettingAdapter::Airplan..."
        QT_MOC_LITERAL(187, 23)   // "setNewValueAirplaneMode"
    },
    "SystemSettingController",
    "isAirplaneModeActiveChanged",
    "",
    "isAirplaneModeActive",
    "setIsAirplaneModeActive",
    "newIsAirplaneModeActive",
    "handleUpdateAirplaneMode",
    "SystemSettingAdapter::AirplaneModeEnums",
    "setNewValueAirplaneMode"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSystemSettingControllerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   55, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   45,    2, 0x10a,    3 /* Public | MethodIsConst  */,
       4,    1,   46,    2, 0x0a,    4 /* Public */,
       6,    1,   49,    2, 0x0a,    6 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   52,    2, 0x02,    8 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, 0x80000000 | 7,    2,

 // methods: parameters
    QMetaType::Void, QMetaType::Bool,    2,

 // properties: name, type, flags
       3, QMetaType::Bool, 0x00015103, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject SystemSettingController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSystemSettingControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSystemSettingControllerENDCLASS_t,
        // property 'isAirplaneModeActive'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SystemSettingController, std::true_type>,
        // method 'isAirplaneModeActiveChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isAirplaneModeActive'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setIsAirplaneModeActive'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'handleUpdateAirplaneMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const SystemSettingAdapter::AirplaneModeEnums &, std::false_type>,
        // method 'setNewValueAirplaneMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>
    >,
    nullptr
} };

void SystemSettingController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SystemSettingController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->isAirplaneModeActiveChanged(); break;
        case 1: { bool _r = _t->isAirplaneModeActive();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->setIsAirplaneModeActive((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->handleUpdateAirplaneMode((*reinterpret_cast< std::add_pointer_t<SystemSettingAdapter::AirplaneModeEnums>>(_a[1]))); break;
        case 4: _t->setNewValueAirplaneMode((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SystemSettingController::*)();
            if (_t _q_method = &SystemSettingController::isAirplaneModeActiveChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SystemSettingController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isAirplaneModeActive(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SystemSettingController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIsAirplaneModeActive(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void SystemSettingController::isAirplaneModeActiveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
