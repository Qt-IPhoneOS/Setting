QT += quick virtualkeyboard
CONFIG += c++20
TARGET = Setting

LIBS += -L$$PWD/../../executable \
        -lmiddlewarelayer \
        -luicommon \
        -lservice

INCLUDEPATH += $$PWD/../../libs/MiddlewareLayer \
               $$PWD/../../libs/MiddlewareLayer/Common \
               $$PWD/../../libs/MiddlewareLayer/Wifi \
               $$PWD/../../libs/MiddlewareLayer/SystemSetting \
               $$PWD/../../libs/UICommon \
               $$PWD/../../libs/UICommon/Feature \
               $$PWD/Controller \
               $$PWD/../../libs/Services/include \
               $$PWD/../../libs/Services/include/Common \
               $$PWD/../../libs/Services/include/Wifi \
               $$PWD/../../libs/Services/include/SystemSetting \
               $$PWD/../../libs/Services/include/SIM \

SOURCES += \
        Controller/SettingEngine.cpp \
        Controller/Wifi/WifiController.cpp \
        Model/WifiDeviceModel.cpp \
        Controller/SystemSetting/SystemSettingController.cpp \
        Controller/SIM/SIMController.cpp \
        main.cpp

QML_IMPORT_PATH += $$PWD/../../libs/UICommon

RESOURCES += \
    Setting.qrc \
    Images.qrc

HEADERS += \
    Controller/Enums.h \
    Controller/SettingEngine.h \
    Controller/Wifi/WifiController.h \
    Model/WifiDeviceModel.h \
    Controller/SystemSetting/SystemSettingController.h \
    Controller/SIM/SIMController.h

DISTFILES +=

