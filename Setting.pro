QT += quick virtualkeyboard
CONFIG += c++20

LIBS += -L$$PWD/../../Executable \
        -lmiddlewarelayer \
        -luicommon \
        -lservice

INCLUDEPATH += $$PWD/../../MiddlewareLayer \
               $$PWD/../../MiddlewareLayer/Common \
               $$PWD/../../MiddlewareLayer/Wifi \
               $$PWD/../../MiddlewareLayer/SystemSetting \
               $$PWD/../UICommon \
               $$PWD/../UICommon/Feature \
               $$PWD/Controller \
               $$PWD/../../Services/include \
               $$PWD/../../Services/include/Common \
               $$PWD/../../Services/include/Wifi \
               $$PWD/../../Services/include/SystemSetting \

SOURCES += \
        Controller/SettingEngine.cpp \
        Controller/Wifi/WifiController.cpp \
        Model/WifiDeviceModel.cpp \
        Controller/SystemSetting/SystemSettingController.cpp \
        main.cpp

RESOURCES += \
    Setting.qrc \
    Images.qrc

HEADERS += \
    Controller/Enums.h \
    Controller/SettingEngine.h \
    Controller/Wifi/WifiController.h \
    Model/WifiDeviceModel.h \
    Controller/SystemSetting/SystemSettingController.h \

DISTFILES +=

