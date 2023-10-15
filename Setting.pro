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
        Controller/AppMain.cpp \
        AppWindow/AppWindow.cpp \
        Controller/Wifi/WifiController.cpp \
        Model/WifiDeviceModel.cpp \
        main.cpp

resources.prefix = /$${TARGET}
RESOURCES += resources \
    Setting.qrc \
    Images.qrc

resources.files = Screen/main.qml

HEADERS += \
    Controller/AppMain.h \
    AppWindow/AppWindow.h \
    Controller/Wifi/WifiController.h \
    Model/WifiDeviceModel.h

DISTFILES +=

