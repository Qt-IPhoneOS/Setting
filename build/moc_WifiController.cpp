/****************************************************************************
** Meta object code from reading C++ file 'WifiController.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Controller/Wifi/WifiController.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WifiController.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSWifiControllerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSWifiControllerENDCLASS = QtMocHelpers::stringData(
    "WifiController",
    "wifiOnChanged",
    "",
    "connectedNameChanged",
    "connectedStatusChanged",
    "handleUpdatePairedDevices",
    "std::vector<WifiDevice*>",
    "handleUpdateDeviceState",
    "std::string",
    "Enums::WifiState",
    "handleUpdateConnectedDevice",
    "WifiDevice*",
    "handleUpdateEnableWifi",
    "handleAddDiscoveryDevice",
    "handleRemoveDiscoveryDevice",
    "setEnableWifi",
    "enable",
    "connectDevice",
    "addr",
    "startDiscovery",
    "wifiOn",
    "connectedName",
    "connectedStatus",
    "Enums::ConnectedState"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWifiControllerENDCLASS_t {
    uint offsetsAndSizes[48];
    char stringdata0[15];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[23];
    char stringdata5[26];
    char stringdata6[25];
    char stringdata7[24];
    char stringdata8[12];
    char stringdata9[17];
    char stringdata10[28];
    char stringdata11[12];
    char stringdata12[23];
    char stringdata13[25];
    char stringdata14[28];
    char stringdata15[14];
    char stringdata16[7];
    char stringdata17[14];
    char stringdata18[5];
    char stringdata19[15];
    char stringdata20[7];
    char stringdata21[14];
    char stringdata22[16];
    char stringdata23[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWifiControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWifiControllerENDCLASS_t qt_meta_stringdata_CLASSWifiControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "WifiController"
        QT_MOC_LITERAL(15, 13),  // "wifiOnChanged"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 20),  // "connectedNameChanged"
        QT_MOC_LITERAL(51, 22),  // "connectedStatusChanged"
        QT_MOC_LITERAL(74, 25),  // "handleUpdatePairedDevices"
        QT_MOC_LITERAL(100, 24),  // "std::vector<WifiDevice*>"
        QT_MOC_LITERAL(125, 23),  // "handleUpdateDeviceState"
        QT_MOC_LITERAL(149, 11),  // "std::string"
        QT_MOC_LITERAL(161, 16),  // "Enums::WifiState"
        QT_MOC_LITERAL(178, 27),  // "handleUpdateConnectedDevice"
        QT_MOC_LITERAL(206, 11),  // "WifiDevice*"
        QT_MOC_LITERAL(218, 22),  // "handleUpdateEnableWifi"
        QT_MOC_LITERAL(241, 24),  // "handleAddDiscoveryDevice"
        QT_MOC_LITERAL(266, 27),  // "handleRemoveDiscoveryDevice"
        QT_MOC_LITERAL(294, 13),  // "setEnableWifi"
        QT_MOC_LITERAL(308, 6),  // "enable"
        QT_MOC_LITERAL(315, 13),  // "connectDevice"
        QT_MOC_LITERAL(329, 4),  // "addr"
        QT_MOC_LITERAL(334, 14),  // "startDiscovery"
        QT_MOC_LITERAL(349, 6),  // "wifiOn"
        QT_MOC_LITERAL(356, 13),  // "connectedName"
        QT_MOC_LITERAL(370, 15),  // "connectedStatus"
        QT_MOC_LITERAL(386, 21)   // "Enums::ConnectedState"
    },
    "WifiController",
    "wifiOnChanged",
    "",
    "connectedNameChanged",
    "connectedStatusChanged",
    "handleUpdatePairedDevices",
    "std::vector<WifiDevice*>",
    "handleUpdateDeviceState",
    "std::string",
    "Enums::WifiState",
    "handleUpdateConnectedDevice",
    "WifiDevice*",
    "handleUpdateEnableWifi",
    "handleAddDiscoveryDevice",
    "handleRemoveDiscoveryDevice",
    "setEnableWifi",
    "enable",
    "connectDevice",
    "addr",
    "startDiscovery",
    "wifiOn",
    "connectedName",
    "connectedStatus",
    "Enums::ConnectedState"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWifiControllerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       3,  118, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    4 /* Public */,
       3,    0,   87,    2, 0x06,    5 /* Public */,
       4,    0,   88,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   89,    2, 0x0a,    7 /* Public */,
       7,    3,   92,    2, 0x0a,    9 /* Public */,
      10,    1,   99,    2, 0x0a,   13 /* Public */,
      12,    1,  102,    2, 0x0a,   15 /* Public */,
      13,    1,  105,    2, 0x0a,   17 /* Public */,
      14,    1,  108,    2, 0x0a,   19 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      15,    1,  111,    2, 0x02,   21 /* Public */,
      17,    1,  114,    2, 0x02,   23 /* Public */,
      19,    0,  117,    2, 0x02,   25 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 9, 0x80000000 | 9,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 8,    2,

 // methods: parameters
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,

 // properties: name, type, flags
      20, QMetaType::Bool, 0x00015103, uint(0), 0,
      21, QMetaType::QString, 0x00015103, uint(1), 0,
      22, 0x80000000 | 23, 0x0001510b, uint(2), 0,

       0        // eod
};

Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_CLASSWifiControllerENDCLASS[] = {
    QMetaObject::SuperData::link<Enums::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject WifiController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSWifiControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWifiControllerENDCLASS,
    qt_static_metacall,
    qt_meta_extradata_CLASSWifiControllerENDCLASS,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWifiControllerENDCLASS_t,
        // property 'wifiOn'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'connectedName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'connectedStatus'
        QtPrivate::TypeAndForceComplete<Enums::ConnectedState, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WifiController, std::true_type>,
        // method 'wifiOnChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectedNameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectedStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleUpdatePairedDevices'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<WifiDevice*>, std::false_type>,
        // method 'handleUpdateDeviceState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>,
        QtPrivate::TypeAndForceComplete<Enums::WifiState, std::false_type>,
        QtPrivate::TypeAndForceComplete<Enums::WifiState, std::false_type>,
        // method 'handleUpdateConnectedDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<WifiDevice *, std::false_type>,
        // method 'handleUpdateEnableWifi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'handleAddDiscoveryDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<WifiDevice *, std::false_type>,
        // method 'handleRemoveDiscoveryDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>,
        // method 'setEnableWifi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        // method 'connectDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'startDiscovery'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void WifiController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WifiController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->wifiOnChanged(); break;
        case 1: _t->connectedNameChanged(); break;
        case 2: _t->connectedStatusChanged(); break;
        case 3: _t->handleUpdatePairedDevices((*reinterpret_cast< std::add_pointer_t<std::vector<WifiDevice*>>>(_a[1]))); break;
        case 4: _t->handleUpdateDeviceState((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Enums::WifiState>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Enums::WifiState>>(_a[3]))); break;
        case 5: _t->handleUpdateConnectedDevice((*reinterpret_cast< std::add_pointer_t<WifiDevice*>>(_a[1]))); break;
        case 6: _t->handleUpdateEnableWifi((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->handleAddDiscoveryDevice((*reinterpret_cast< std::add_pointer_t<WifiDevice*>>(_a[1]))); break;
        case 8: _t->handleRemoveDiscoveryDevice((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 9: _t->setEnableWifi((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->connectDevice((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->startDiscovery(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WifiController::*)();
            if (_t _q_method = &WifiController::wifiOnChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WifiController::*)();
            if (_t _q_method = &WifiController::connectedNameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WifiController::*)();
            if (_t _q_method = &WifiController::connectedStatusChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<WifiController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->wifiOn(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->connectedName(); break;
        case 2: *reinterpret_cast< Enums::ConnectedState*>(_v) = _t->connectedStatus(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<WifiController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setWifiOn(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setConnectedName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setConnectedStatus(*reinterpret_cast< Enums::ConnectedState*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *WifiController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WifiController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWifiControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WifiController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void WifiController::wifiOnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WifiController::connectedNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WifiController::connectedStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
