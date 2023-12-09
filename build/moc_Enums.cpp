/****************************************************************************
** Meta object code from reading C++ file 'Enums.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Controller/Enums.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Enums.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSEnumsENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSEnumsENDCLASS = QtMocHelpers::stringData(
    "Enums",
    "ScreenID",
    "SET_Main",
    "SET_WifiMenu",
    "WifiState",
    "Unknown",
    "Unpaired",
    "CheckingSSID",
    "CheckingSSIDFail",
    "CheckingSSIDSuccess",
    "Paired",
    "WaitingAuthen",
    "AuthenFail",
    "AuthenSuccess",
    "ConnectedState",
    "DeviceConnecting",
    "DeviceConnected"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSEnumsENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[6];
    char stringdata1[9];
    char stringdata2[9];
    char stringdata3[13];
    char stringdata4[10];
    char stringdata5[8];
    char stringdata6[9];
    char stringdata7[13];
    char stringdata8[17];
    char stringdata9[20];
    char stringdata10[7];
    char stringdata11[14];
    char stringdata12[11];
    char stringdata13[14];
    char stringdata14[15];
    char stringdata15[17];
    char stringdata16[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSEnumsENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSEnumsENDCLASS_t qt_meta_stringdata_CLASSEnumsENDCLASS = {
    {
        QT_MOC_LITERAL(0, 5),  // "Enums"
        QT_MOC_LITERAL(6, 8),  // "ScreenID"
        QT_MOC_LITERAL(15, 8),  // "SET_Main"
        QT_MOC_LITERAL(24, 12),  // "SET_WifiMenu"
        QT_MOC_LITERAL(37, 9),  // "WifiState"
        QT_MOC_LITERAL(47, 7),  // "Unknown"
        QT_MOC_LITERAL(55, 8),  // "Unpaired"
        QT_MOC_LITERAL(64, 12),  // "CheckingSSID"
        QT_MOC_LITERAL(77, 16),  // "CheckingSSIDFail"
        QT_MOC_LITERAL(94, 19),  // "CheckingSSIDSuccess"
        QT_MOC_LITERAL(114, 6),  // "Paired"
        QT_MOC_LITERAL(121, 13),  // "WaitingAuthen"
        QT_MOC_LITERAL(135, 10),  // "AuthenFail"
        QT_MOC_LITERAL(146, 13),  // "AuthenSuccess"
        QT_MOC_LITERAL(160, 14),  // "ConnectedState"
        QT_MOC_LITERAL(175, 16),  // "DeviceConnecting"
        QT_MOC_LITERAL(192, 15)   // "DeviceConnected"
    },
    "Enums",
    "ScreenID",
    "SET_Main",
    "SET_WifiMenu",
    "WifiState",
    "Unknown",
    "Unpaired",
    "CheckingSSID",
    "CheckingSSIDFail",
    "CheckingSSIDSuccess",
    "Paired",
    "WaitingAuthen",
    "AuthenFail",
    "AuthenSuccess",
    "ConnectedState",
    "DeviceConnecting",
    "DeviceConnected"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSEnumsENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       3,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    2,   29,
       4,    4, 0x0,    9,   33,
      14,   14, 0x0,    2,   51,

 // enum data: key, value
       2, uint(Enums::SET_Main),
       3, uint(Enums::SET_WifiMenu),
       5, uint(Enums::Unknown),
       6, uint(Enums::Unpaired),
       7, uint(Enums::CheckingSSID),
       8, uint(Enums::CheckingSSIDFail),
       9, uint(Enums::CheckingSSIDSuccess),
      10, uint(Enums::Paired),
      11, uint(Enums::WaitingAuthen),
      12, uint(Enums::AuthenFail),
      13, uint(Enums::AuthenSuccess),
      15, uint(Enums::DeviceConnecting),
      16, uint(Enums::DeviceConnected),

       0        // eod
};

Q_CONSTINIT const QMetaObject Enums::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSEnumsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSEnumsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSEnumsENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Enums, std::true_type>
    >,
    nullptr
} };

void Enums::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *Enums::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Enums::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSEnumsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Enums::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
