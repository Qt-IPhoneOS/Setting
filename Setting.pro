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
               $$PWD/../../Services/include/SystemSettingServices \

SOURCES += \
        Controller/SettingEngine.cpp \
        Controller/Wifi/WifiController.cpp \
        Controller/ScreenNavigator/ScreenNavigator.cpp \
        Controller/SystemSettingController/SystemSettingController.cpp \
        Model/SystemSettingModel/SystemSettingModel.cpp \
        Model/WifiDeviceModel.cpp \
        main.cpp

resources.prefix = /$${TARGET}
RESOURCES += resources \
    Setting.qrc \
    Images.qrc

resources.files = Screen/main.qml

HEADERS += \
    Controller/Enums.h \
    Controller/SettingEngine.h \
    Controller/Wifi/WifiController.h \
    Controller/ScreenNavigator/ScreenNavigator.h \
    Controller/SystemSettingController/SystemSettingController.h \
    Model/SystemSettingModel/SystemSettingModel.h \
    Model/WifiDeviceModel.h \

DISTFILES +=

