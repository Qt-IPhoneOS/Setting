QT += quick virtualkeyboard
CONFIG += c++20

LIBS += -L$$PWD/../../Executable \
        -lmiddlewarelayer \
        -luicommon \
        -lservice

INCLUDEPATH += $$PWD/../../MiddlewareLayer \
               $$PWD/../../MiddlewareLayer/Common \
               $$PWD/../../MiddlewareLayer/Wifi \
               $$PWD/../UICommon \
               $$PWD/../../Services/include
               $$PWD/../../Services/include/Common
               $$PWD/../../Services/include/Wifi
               $$PWD/../../Services/include/SystemSetting

SOURCES += \
        Controller/SettingEngine.cpp \
        Controller/SettingController.cpp \
        Controller/Wifi/WifiController.cpp \
        Controller/ScreenNavigator/ScreenNavigator.cpp \
        Model/WifiDeviceModel.cpp \
        Controller/AirplaneMode/AirplaneModeController.cpp \
        Model/AirplaneMode/AirplaneModeModel.cpp \
        main.cpp

resources.prefix = /$${TARGET}
RESOURCES += resources \
    Setting.qrc \
    Images.qrc

resources.files = Screen/main.qml

HEADERS += \
    Controller/Enums.h \
    Controller/SettingEngine.h \
    Controller/SettingController.h \
    Controller/Wifi/WifiController.h \
    Controller/AirplaneMode/AirplaneModeController.h \
    Controller/ScreenNavigator/ScreenNavigator.h \
    Model/WifiDeviceModel.h \
    Model/AirplaneMode/AirplaneModeModel.h 

DISTFILES +=

